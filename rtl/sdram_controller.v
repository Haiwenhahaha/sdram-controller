/**
 * DE0 Nano 开发板上的 ISSI IS42S16160G-7 SDRAM 简单控制器
 *  容量：16Mbit x 16位数据总线 (32MB)
 *  默认配置：
 *    频率：133MHz
 *    CAS延迟：3
 *
 *  简化的主机接口特性：
 *     * 不支持突发传输
 *     * haddr - 读写16位数据的地址
 *     * data_input - 写数据，当wr_enable为高时锁存
 *     * data_output - 读数据，在rd_enable和地址出现在总线上
 *       几个时钟周期后可用
 *     * rst_n - 启动SDRAM初始化过程
 *     * rd_enable - 读使能，时钟上升沿时锁存haddr，
 *       几个时钟周期后数据将在data_output端口可用
 *     * wr_enable - 写使能，时钟上升沿时锁存haddr和data_input，
 *       几个时钟周期后数据将写入SDRAM
 *
 * 工作原理
 *  这个简单的主机接口有一个忙信号，用于指示何时不能发出命令。
 */

module sdram_controller (
    /* 主机接口 */
    wr_addr,      // 写地址
    wr_data,      // 写数据
    wr_enable,    // 写使能

    rd_addr,      // 读地址
    rd_data,      // 读数据
    rd_ready,     // 读数据就绪
    rd_enable,    // 读使能

    busy,         // 控制器忙信号
    rst_n,        // 复位信号
    clk,          // 时钟信号

    /* SDRAM 接口 */
    addr,         // SDRAM地址总线
    bank_addr,    // 存储体地址
    data,         // 数据总线
    clock_enable, // 时钟使能
    cs_n,         // 片选信号
    ras_n,        // 行地址选通
    cas_n,        // 列地址选通
    we_n,         // 写使能
    data_mask_low,  // 低字节数据掩码
    data_mask_high // 高字节数据掩码
);

/* 内部参数定义 */
parameter ROW_WIDTH = 13;    // 行地址宽度
parameter COL_WIDTH = 9;     // 列地址宽度
parameter BANK_WIDTH = 2;    // 存储体地址宽度

parameter SDRADDR_WIDTH = ROW_WIDTH > COL_WIDTH ? ROW_WIDTH : COL_WIDTH; // SDRAM地址总线宽度
parameter HADDR_WIDTH = BANK_WIDTH + ROW_WIDTH + COL_WIDTH; // 主机地址总线宽度 (24位)

parameter CLK_FREQUENCY = 133;  // 时钟频率 (MHz)
parameter REFRESH_TIME =  32;   // 刷新时间 (ms) - 刷新间隔时间
parameter REFRESH_COUNT = 8192; // 刷新计数 - 每个刷新周期需要多少次刷新

// 计算两次刷新之间的时钟周期数
// 公式：时钟频率 * 1000 * 刷新时间 / 刷新计数
localparam CYCLES_BETWEEN_REFRESH = ( CLK_FREQUENCY
                                      * 1_000
                                      * REFRESH_TIME
                                    ) / REFRESH_COUNT;

// 状态机状态定义
localparam IDLE      = 5'b00000;  // 空闲状态

// SDRAM 初始化状态
localparam INIT_NOP1 = 5'b01000,  // 初始化等待1
           INIT_PRE1 = 5'b01001,  // 初始化预充电1
           INIT_NOP1_1=5'b00101,  // 初始化等待1_1
           INIT_REF1 = 5'b01010,  // 初始化刷新1
           INIT_NOP2 = 5'b01011,  // 初始化等待2
           INIT_REF2 = 5'b01100,  // 初始化刷新2
           INIT_NOP3 = 5'b01101,  // 初始化等待3
           INIT_LOAD = 5'b01110,  // 初始化模式寄存器加载
           INIT_NOP4 = 5'b01111;  // 初始化等待4

// 自动刷新状态
localparam REF_PRE  =  5'b00001,  // 刷新预充电
           REF_NOP1 =  5'b00010,  // 刷新等待1
           REF_REF  =  5'b00011,  // 刷新执行
           REF_NOP2 =  5'b00100;  // 刷新等待2

// 读操作状态
localparam READ_ACT  = 5'b10000,  // 读激活
           READ_NOP1 = 5'b10001,  // 读等待1
           READ_CAS  = 5'b10010,  // 读列地址选通
           READ_NOP2 = 5'b10011,  // 读等待2
           READ_READ = 5'b10100;  // 读数据

// 写操作状态
localparam WRIT_ACT  = 5'b11000,  // 写激活
           WRIT_NOP1 = 5'b11001,  // 写等待1
           WRIT_CAS  = 5'b11010,  // 写列地址选通
           WRIT_NOP2 = 5'b11011;  // 写等待2

// SDRAM 命令定义
// 命令格式：CKE CS RAS CAS WE BA
localparam CMD_PALL = 8'b10010001,  // 预充电所有存储体
           CMD_REF  = 8'b10001000,  // 自动刷新
           CMD_NOP  = 8'b10111000,  // 无操作
           CMD_MRS  = 8'b1000000x,  // 模式寄存器设置
           CMD_BACT = 8'b10011xxx,  // 存储体激活
           CMD_READ = 8'b10101xx1,  // 读命令
           CMD_WRIT = 8'b10100xx1;  // 写命令

/* 接口定义 */
/* 主机接口 */
input  [HADDR_WIDTH-1:0]   wr_addr;      // 写地址输入
input  [15:0]              wr_data;      // 写数据输入
input                      wr_enable;    // 写使能输入

input  [HADDR_WIDTH-1:0]   rd_addr;      // 读地址输入
output [15:0]              rd_data;      // 读数据输出
input                      rd_enable;    // 读使能输入
output                     rd_ready;     // 读数据就绪输出

output                     busy;         // 忙信号输出
input                      rst_n;        // 复位信号输入
input                      clk;          // 时钟输入

/* SDRAM 接口 */
output [SDRADDR_WIDTH-1:0] addr;         // SDRAM地址输出
output [BANK_WIDTH-1:0]    bank_addr;    // 存储体地址输出
inout  [15:0]              data;         // 数据总线，双向
output                     clock_enable; // 时钟使能输出
output                     cs_n;         // 片选信号输出
output                     ras_n;        // 行地址选通输出
output                     cas_n;        // 列地址选通输出
output                     we_n;         // 写使能输出
output                     data_mask_low;  // 低字节数据掩码输出
output                     data_mask_high; // 高字节数据掩码输出

/* I/O 寄存器 */

reg  [HADDR_WIDTH-1:0]   haddr_r;        // 主机地址寄存器
reg  [15:0]              wr_data_r;      // 写数据寄存器
reg  [15:0]              rd_data_r;      // 读数据寄存器
reg                      busy;           // 忙信号寄存器
reg                      data_mask_low_r;  // 低字节数据掩码寄存器
reg                      data_mask_high_r; // 高字节数据掩码寄存器
reg [SDRADDR_WIDTH-1:0]  addr_r;         // SDRAM地址寄存器
reg [BANK_WIDTH-1:0]     bank_addr_r;    // 存储体地址寄存器
reg                      rd_ready_r;     // 读就绪寄存器

wire [15:0]              data_output;    // 数据输出线
wire                     data_mask_low, data_mask_high; // 数据掩码线

// 数据掩码信号分配
assign data_mask_high = data_mask_high_r;
assign data_mask_low  = data_mask_low_r;
assign rd_data        = rd_data_r;

/* 内部连线 */
reg [3:0] state_cnt;     // 状态计数器
reg [9:0] refresh_cnt;   // 刷新计数器

reg [7:0] command;       // 当前命令
reg [4:0] state;         // 当前状态

// TODO: 在编程模式寄存器时输出 addr[6:4]

reg [7:0] command_nxt;    // 下一个命令
reg [3:0] state_cnt_nxt;  // 下一个状态计数器值
reg [4:0] next;           // 下一个状态

// 命令信号分配：{CKE, CS, RAS, CAS, WE}
assign {clock_enable, cs_n, ras_n, cas_n, we_n} = command[7:3];
// 状态[4]在读/写模式时会被设置
assign bank_addr      = (state[4]) ? bank_addr_r : command[2:1];
assign addr           = (state[4] | state == INIT_LOAD) ? addr_r : { {SDRADDR_WIDTH-11{1'b0}}, command[0], 10'd0 };

// 数据总线：仅在写列地址选通时输出数据，其他时候为高阻态
assign data = (state == WRIT_CAS) ? wr_data_r : 16'bz;
assign rd_ready = rd_ready_r;

// 主机接口处理
// 所有信号在时钟上升沿时寄存
always @ (posedge clk)
  if (~rst_n)
    begin
    // 复位时初始化所有寄存器
    state <= INIT_NOP1;           // 初始化为初始化状态
    command <= CMD_NOP;           // 初始化为无操作命令
    state_cnt <= 4'hf;            // 初始化状态计数器

    haddr_r <= {HADDR_WIDTH{1'b0}}; // 清空地址寄存器
    wr_data_r <= 16'b0;           // 清空写数据寄存器
    rd_data_r <= 16'b0;           // 清空读数据寄存器
    busy <= 1'b0;                 // 清空忙信号
    end
  else
    begin

    state <= next;                // 更新当前状态
    command <= command_nxt;       // 更新当前命令

    // 状态计数器递减逻辑
    if (!state_cnt)
      state_cnt <= state_cnt_nxt;
    else
      state_cnt <= state_cnt - 1'b1;

    // 写数据锁存
    if (wr_enable)
      wr_data_r <= wr_data;

    // 读数据处理
    if (state == READ_READ)
      begin
      rd_data_r <= data;          // 锁存读出的数据
      rd_ready_r <= 1'b1;         // 设置读数据就绪信号
      end
    else
      rd_ready_r <= 1'b0;         // 清除读数据就绪信号

    // 忙信号：当状态[4]为1时表示控制器忙
    busy <= state[4];

    // 地址锁存：优先处理读操作
    if (rd_enable)
      haddr_r <= rd_addr;
    else if (wr_enable)
      haddr_r <= wr_addr;

    end

// 刷新计数器处理
always @ (posedge clk)
 if (~rst_n)
   refresh_cnt <= 10'b0;        // 复位时清零刷新计数器
 else
   if (state == REF_NOP2)
     refresh_cnt <= 10'b0;      // 刷新完成后重置计数器
   else
     refresh_cnt <= refresh_cnt + 1'b1; // 其他时候递增计数器


/* 根据当前状态处理发送给 SDRAM 的地址逻辑 */
always @*
begin
    // 数据掩码设置：在读/写操作时禁用掩码，其他时候启用掩码
    if (state[4])
      {data_mask_low_r, data_mask_high_r} = 2'b00;  // 读/写时不禁用数据掩码
    else
      {data_mask_low_r, data_mask_high_r} = 2'b11;  // 其他时候禁用数据掩码

   // 默认地址设置
   bank_addr_r = 2'b00;                    // 默认存储体地址为0
   addr_r = {SDRADDR_WIDTH{1'b0}};         // 默认行/列地址为0

   // 激活命令时的地址设置
   if (state == READ_ACT | state == WRIT_ACT)
     begin
     // 提取存储体地址和行地址
     bank_addr_r = haddr_r[HADDR_WIDTH-1:HADDR_WIDTH-(BANK_WIDTH)];
     addr_r = haddr_r[HADDR_WIDTH-(BANK_WIDTH+1):HADDR_WIDTH-(BANK_WIDTH+ROW_WIDTH)];
     end
   else if (state == READ_CAS | state == WRIT_CAS)
     begin
     // 列地址选通命令时的地址设置
     // 设置存储体地址用于预充电
     bank_addr_r = haddr_r[HADDR_WIDTH-1:HADDR_WIDTH-(BANK_WIDTH)];

     // 地址位分配示例：
     //               BANK  ROW    COL
     // HADDR_WIDTH   2 +   13 +   9   = 24
     // SDRADDR_WIDTH 13

     // 设置列地址选通地址：
     //   前导0，
     //   1 (A10总是用于自动预充电)，
     //   填充0，
     //   列地址
     addr_r = {
               {SDRADDR_WIDTH-(11){1'b0}},  // 前导0
               1'b1,                         /* A10 - 自动预充电 */
               {10-COL_WIDTH{1'b0}},        // 填充0
               haddr_r[COL_WIDTH-1:0]       // 列地址
              };
     end
   else if (state == INIT_LOAD)
     begin
     // 初始化时编程模式寄存器
     // 模式寄存器设置：CAS延迟=3，突发长度=1，突发类型=顺序
     //                                       B  C  SB
     //                                       R  A  EUR
     //                                       S  S-3Q ST
     //                                       T  654L210
     addr_r = {{SDRADDR_WIDTH-10{1'b0}}, 10'b1000110000};
     end
end

// Next state logic
always @*
begin
   state_cnt_nxt = 4'd0;
   command_nxt = CMD_NOP;
   if (state == IDLE)
        // Monitor for refresh or hold
        if (refresh_cnt >= CYCLES_BETWEEN_REFRESH)
          begin
          next = REF_PRE;
          command_nxt = CMD_PALL;
          end
        else if (rd_enable)
          begin
          next = READ_ACT;
          command_nxt = CMD_BACT;
          end
        else if (wr_enable)
          begin
          next = WRIT_ACT;
          command_nxt = CMD_BACT;
          end
        else
          begin
          // HOLD
          next = IDLE;
          end
    else
      if (!state_cnt)
        case (state)
          // INIT ENGINE
          INIT_NOP1:
            begin
            next = INIT_PRE1;
            command_nxt = CMD_PALL;
            end
          INIT_PRE1:
            begin
            next = INIT_NOP1_1;
            end
          INIT_NOP1_1:
            begin
            next = INIT_REF1;
            command_nxt = CMD_REF;
            end
          INIT_REF1:
            begin
            next = INIT_NOP2;
            state_cnt_nxt = 4'd7;
            end
          INIT_NOP2:
            begin
            next = INIT_REF2;
            command_nxt = CMD_REF;
            end
          INIT_REF2:
            begin
            next = INIT_NOP3;
            state_cnt_nxt = 4'd7;
            end
          INIT_NOP3:
            begin
            next = INIT_LOAD;
            command_nxt = CMD_MRS;
            end
          INIT_LOAD:
            begin
            next = INIT_NOP4;
            state_cnt_nxt = 4'd1;
            end
          // INIT_NOP4: default - IDLE

          // REFRESH
          REF_PRE:
            begin
            next = REF_NOP1;
            end
          REF_NOP1:
            begin
            next = REF_REF;
            command_nxt = CMD_REF;
            end
          REF_REF:
            begin
            next = REF_NOP2;
            state_cnt_nxt = 4'd7;
            end
          // REF_NOP2: default - IDLE

          // WRITE
          WRIT_ACT:
            begin
            next = WRIT_NOP1;
            state_cnt_nxt = 4'd1;
            end
          WRIT_NOP1:
            begin
            next = WRIT_CAS;
            command_nxt = CMD_WRIT;
            end
          WRIT_CAS:
            begin
            next = WRIT_NOP2;
            state_cnt_nxt = 4'd1;
            end
          // WRIT_NOP2: default - IDLE

          // READ
          READ_ACT:
            begin
            next = READ_NOP1;
            state_cnt_nxt = 4'd1;
            end
          READ_NOP1:
            begin
            next = READ_CAS;
            command_nxt = CMD_READ;
            end
          READ_CAS:
            begin
            next = READ_NOP2;
            state_cnt_nxt = 4'd1;
            end
          READ_NOP2:
            begin
            next = READ_READ;
            end
          // READ_READ: default - IDLE

          default:
            begin
            next = IDLE;
            end
          endcase
      else
        begin
        // Counter Not Reached - HOLD
        next = state;
        command_nxt = command;
        end
end

endmodule
