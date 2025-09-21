//////////////////////////////////////////////////////////////////////
//
// DE0 Nano 开发板 SDRAM 控制器顶层模块
// 用于控制 SDRAM 存储器的读写操作
//
//////////////////////////////////////////////////////////////////////
//
// This source file may be used and distributed without
// restriction provided that this copyright statement is not
// removed from the file and that any derivative work contains
// the original copyright notice and the associated disclaimer.
//
// This source file is free software; you can redistribute it
// and/or modify it under the terms of the GNU Lesser General
// Public License as published by the Free Software Foundation;
// either version 2.1 of the License, or (at your option) any
// later version.
//
// This source is distributed in the hope that it will be
// useful, but WITHOUT ANY WARRANTY; without even the implied
// warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
// PURPOSE.  See the GNU Lesser General Public License for more
// details.
//
// You should have received a copy of the GNU Lesser General
// Public License along with this source; if not, download it
// from http://www.opencores.org/lgpl.shtml
//
//////////////////////////////////////////////////////////////////////

module toplevel (
    // 系统时钟和复位信号
    input         sys_clk_pad_i,    // 系统时钟输入 (50MHz)
    input         rst_n_pad_i,      // 复位信号，低电平有效
    input         btn_n_pad_i,      // 按键输入，低电平有效

    // SDRAM 控制信号
    output [1:0]  sdram_ba_pad_o,   // SDRAM 存储体地址
    output [12:0] sdram_a_pad_o,    // SDRAM 行/列地址总线
    output        sdram_cs_n_pad_o, // SDRAM 片选信号，低电平有效
    output        sdram_ras_pad_o,  // 行地址选通信号，低电平有效
    output        sdram_cas_pad_o,  // 列地址选通信号，低电平有效
    output        sdram_we_pad_o,   // 写使能信号，低电平有效
    inout  [15:0] sdram_dq_pad_io,  // SDRAM 数据总线，双向16位
    output [1:0]  sdram_dqm_pad_o,  // 数据掩码信号
    output        sdram_cke_pad_o,  // 时钟使能信号
    output        sdram_clk_pad_o,  // SDRAM 时钟输出

    // GPIO 接口
    inout [7:0]   gpio0_io,         // GPIO0：LED 指示灯
    input [3:0]   gpio1_i           // GPIO1：DIP 开关
);

// 时钟信号定义
wire clk100m;  // 100MHz 时钟，用于 SDRAM 控制器
wire clk1m;    // 1MHz 时钟，用于用户接口

// SDRAM 时钟输出直接使用 100MHz 时钟
assign sdram_clk_pad_o = clk100m;

// 锁相环 (PLL) 实例化
// 生成 100MHz 时钟用于 SDRAM 控制器
pll_100m pll_100mi (
    .inclk0      (sys_clk_pad_i),  // 输入时钟 50MHz
    .c0          (clk100m)         // 输出 100MHz 时钟
);

// 生成 1MHz 时钟用于用户接口
pll_1m pll_1mi (
    .inclk0      (sys_clk_pad_i),  // 输入时钟 50MHz
    .c0          (clk1m)           // 输出 1MHz 时钟
);

// 跨时钟域 FIFO 模块
// 用于在 1MHz 用户接口和 100MHz SDRAM 控制器之间传输数据

// 写操作 FIFO：24位地址 + 16位数据 = 40位
// 1MHz 用户接口侧信号
wire [39:0] wr_fifo;       // 写数据：高24位为地址，低16位为数据
wire wr_enable;            // 写使能信号：用户接口向 FIFO 写入数据
wire wr_full;              // FIFO 满信号：防止用户接口继续写入

// 100MHz SDRAM 控制器侧信号
wire [39:0] wro_fifo;      // 从 FIFO 读出的数据
wire ctrl_busy;            // 控制器忙信号：用于从 FIFO 读取数据
wire ctrl_wr_enable;       // 控制器写使能：FIFO 非空时有效

// 写操作 FIFO 实例化 (40位宽度)
fifo #(.BUS_WIDTH(40)) wr_fifoi (
    .wr_clk        (clk1m),         // 写时钟：1MHz
    .rd_clk        (clk100m),       // 读时钟：100MHz
    .wr_data       (wr_fifo),       // 写数据输入
    .rd_data       (wro_fifo),      // 读数据输出
    .rd            (ctrl_busy),     // 读使能：控制器忙时读取
    .wr            (wr_enable),     // 写使能：用户接口写入
    .full          (wr_full),       // FIFO 满信号
    .empty_n       (ctrl_wr_enable), // FIFO 非空信号
    .rst_n         (rst_n_pad_i)    // 复位信号
);

// 读地址 FIFO：仅传输 24位地址
// 1MHz 用户接口侧信号
wire        rd_enable;     // 读使能信号：用户接口请求读操作
wire        rdaddr_full;   // 读地址 FIFO 满信号：防止继续请求读操作

// 100MHz SDRAM 控制器侧信号
wire [23:0] rdao_fifo;     // 从 FIFO 读出的地址
wire ctrl_rd_enable;       // 控制器读使能：FIFO 非空时有效

// 读地址 FIFO 实例化 (24位宽度)
fifo #(.BUS_WIDTH(24)) rdaddr_fifoi (
    .wr_clk        (clk1m),         // 写时钟：1MHz
    .rd_clk        (clk100m),       // 读时钟：100MHz
    .wr_data       (wr_fifo[39:16]), // 写数据：从写 FIFO 的地址部分获取
    .rd_data       (rdao_fifo),     // 读数据输出
    .rd            (ctrl_busy),     // 读使能：控制器忙时读取
    .wr            (rd_enable),     // 写使能：用户接口请求读操作
    .full          (rdaddr_full),   // FIFO 满信号
    .empty_n       (ctrl_rd_enable), // FIFO 非空信号
    .rst_n         (rst_n_pad_i)    // 复位信号
);

// 读数据 FIFO：传输从 SDRAM 读取的 16位数据
// 100MHz SDRAM 控制器侧信号
wire [15:0] rddo_fifo;      // 控制器输出的读数据
wire ctrl_rd_ready;         // 控制器读数据就绪信号：数据可从 SDRAM 读取

// 1MHz 用户接口侧信号
wire [15:0] rddata_fifo;    // 用户接口接收的读数据
wire        rd_ready;       // 读数据就绪信号：数据可供用户接口读取
wire        rd_ack;         // 读确认信号：用户接口确认数据已读取

// 读数据 FIFO 实例化 (16位宽度)
// 数据流向：100MHz (控制器) -> 1MHz (用户接口)
fifo #(.BUS_WIDTH(16)) rddata_fifoi (
    .wr_clk        (clk100m),       // 写时钟：100MHz
    .rd_clk        (clk1m),         // 读时钟：1MHz
    .wr_data       (rddo_fifo),     // 写数据输入：来自控制器
    .rd_data       (rddata_fifo),   // 读数据输出：发送给用户接口
    .rd            (rd_ack),        // 读使能：用户接口确认读取
    .wr            (ctrl_rd_ready), // 写使能：控制器数据就绪
    .full          (),              // 未使用的满信号
    .empty_n       (rd_ready),      // FIFO 非空信号：数据就绪
    .rst_n         (rst_n_pad_i)    // 复位信号
);


// SDRAM 控制器实例化
sdram_controller sdram_controlleri (
    /* 主机接口信号 */
    .wr_addr       (wro_fifo[39:16]), // 写地址：24位
    .wr_data       (wro_fifo[15:0]),  // 写数据：16位
    .wr_enable     (ctrl_wr_enable),  // 写使能信号

    .rd_addr       (rdao_fifo),       // 读地址：24位
    .rd_data       (rddo_fifo),       // 读数据：16位
    .rd_ready      (ctrl_rd_ready),   // 读数据就绪信号
    .rd_enable     (ctrl_rd_enable),  // 读使能信号
    
    .busy          (ctrl_busy),       // 控制器忙信号
    .rst_n         (rst_n_pad_i),     // 复位信号
    .clk           (clk100m),         // 控制器时钟：100MHz

    /* SDRAM 物理接口信号 */
    .addr          (sdram_a_pad_o),      // SDRAM 地址总线
    .bank_addr     (sdram_ba_pad_o),     // SDRAM 存储体地址
    .data          (sdram_dq_pad_io),    // SDRAM 数据总线
    .clock_enable  (sdram_cke_pad_o),    // 时钟使能
    .cs_n          (sdram_cs_n_pad_o),   // 片选信号
    .ras_n         (sdram_ras_pad_o),    // 行地址选通
    .cas_n         (sdram_cas_pad_o),    // 列地址选通
    .we_n          (sdram_we_pad_o),     // 写使能
    .data_mask_low (sdram_dqm_pad_o[0]), // 低字节数据掩码
    .data_mask_high(sdram_dqm_pad_o[1])  // 高字节数据掩码
);

// 系统忙信号：当任何 FIFO 满时，系统忙
wire        busy;
assign busy = wr_full | rdaddr_full;

// DE0 Nano 用户接口实例化
dnano_interface #(.HADDR_WIDTH(24)) dnano_interfacei (
    /* 人机交互接口 */
    .button_n     (btn_n_pad_i),   // 按键输入
    .dip          (gpio1_i),       // DIP 开关输入
    .leds         (gpio0_io),      // LED 输出

    /* 控制器接口 */
    .haddr        (wr_fifo[39:16]), // 主机地址：24位地址
    .busy         (busy),           // 系统忙信号
  
    .wr_enable    (wr_enable),      // 写使能信号
    .wr_data      (wr_fifo[15:00]), // 写数据：16位数据
  
    .rd_enable    (rd_enable),      // 读使能信号
  
    .rd_data      (rddata_fifo),    // 读数据：16位数据
    .rd_rdy       (rd_ready),       // 读数据就绪信号
    .rd_ack       (rd_ack),         // 读确认信号

    /* 基础信号 */
    .rst_n        (rst_n_pad_i),    // 复位信号
    .clk          (clk1m)           // 时钟信号：1MHz
);

endmodule // toplevel
