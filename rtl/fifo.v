/*
 * 这是一个双时钟 FIFO，用于在不同时钟域之间传输数据
 * 
 * 假设输出（读）时钟比输入（写）时钟慢5倍以上
 *
 * FIFO 深度仅为1个字
 *
 * 修改记录
 *  - 2015-07-03   修复了从低速时钟写入时的问题，empty_n 信号
 *                 变高后保持高电平。读端会看到并读取数据，但
 *                 读取完成后 empty_n 仍然保持高电平。它会继续
 *                 读取直到 empty_n 根据写端时钟降低。
 *                 empty_n 应该在读端读取后立即变低。
 *
 */
module fifo (
  // 写端接口
  wr_clk,    // 写时钟
  wr_data,   // 写数据
  wr,        // 写使能
  full,      // 满信号，表示不能再写入
  
  // 读端接口
  rd_data,   // 读数据
  rd_clk,    // 读时钟
  rd,        // 读使能
  empty_n,   // 非空信号，也表示可以读取
  
  rst_n      // 复位信号
);

parameter BUS_WIDTH = 16;  // 数据总线宽度

input [BUS_WIDTH-1:0]  wr_data;   // 写数据输入
input                  wr_clk;    // 写时钟
input                  wr;        // 写使能
output                 full;      // 满信号，低电平表示写端可以写入

output [BUS_WIDTH-1:0] rd_data;   // 读数据输出
input                  rd_clk;    // 读时钟
input                  rd;        // 读使能
output                 empty_n;   // 非空信号，高电平表示读端可以读取

input                  rst_n;     // 复位信号

reg [BUS_WIDTH-1:0]    wr_data_r;  // 写数据寄存器
reg [BUS_WIDTH-1:0]    rd_data;    // 读数据寄存器

/* 
 * 这些寄存器跨越两个时钟域
 *   写时钟域 (CLK WR)           | 读时钟域 (CLK RD)
 *  [wr_r] ------------------> | -> [wr_syn1] -> [wr_syn2] -\
 *  <- [wr_ack2] <- [wr_ack1]  | ---------------------------/
 *    ^^^^^^^^^^               |  
 *  收到写信号时设置 wr_r       |  收到 wr_syn2 时递增计数器
 *  收到 wr_ack2 时清除 wr_r   |  并同步数据
 * 
 */
reg                    wr_r, wr_syn1, wr_syn2, wr_ack1, wr_ack2;  // 写端同步信号
reg                    rd_r, rd_syn1, rd_syn2, rd_ack1, rd_ack2;  // 读端同步信号
reg                    wr_fifo_cnt;  // 写端 FIFO 计数
reg                    rd_fifo_cnt;  // 读端 FIFO 计数

// 状态信号分配
assign full = wr_fifo_cnt == 1'b1;     // 满信号：写端计数为1时满
assign empty_n = rd_fifo_cnt == 1'b1;  // 非空信号：读端计数为1时非空

// 读端时钟域处理
always @ (posedge rd_clk)
  if (~rst_n)
    begin
       // 复位时初始化所有寄存器
       rd_fifo_cnt <= 1'b0;           // 清零读端计数
       {rd_ack2, rd_ack1} <= 2'b00;   // 清零读确认信号
       {wr_syn2, wr_syn1} <= 2'b00;   // 清零写同步信号
    end
  else
    begin
      
      // 同步信号移位寄存器
      {rd_ack2, rd_ack1} <= {rd_ack1, rd_syn2}; 
      {wr_syn2, wr_syn1} <= {wr_syn1, wr_r}; 
      
      // 读请求处理
      if (rd)
        rd_r <= 1'b1;        // 设置读请求
      else if (rd_ack2)
        rd_r <= 1'b0;        // 清除读请求
      
      // 读端计数处理
      if (rd)
        rd_fifo_cnt <= 1'b0; // 读取时清零计数
      if ({wr_syn2, wr_syn1} == 2'b01) // 检测写同步信号上升沿
        rd_fifo_cnt <= 1'b1; // 设置计数为1
      
      // 数据同步
      if (wr_syn2)
        rd_data <= wr_data_r; // 同步写数据到读端
    end
    
// 写端时钟域处理
always @ (posedge wr_clk)
 if (~rst_n)
   begin
      // 复位时初始化所有寄存器
      wr_fifo_cnt <= 1'b0;           // 清零写端计数
      {rd_syn2, rd_syn1} <= 2'b00;   // 清零读同步信号
      {wr_ack2, wr_ack1} <= 2'b00;   // 清零写确认信号
   end
 else
   begin
     // 同步信号移位寄存器
     {wr_ack2, wr_ack1} <= {wr_ack1, wr_syn2};   
     {rd_syn2, rd_syn1} <= {rd_syn1, rd_r};
   
     // 写请求处理
     if (wr)
       wr_r <= 1'b1;        // 设置写请求
     if (wr_ack2)
       wr_r <= 1'b0;        // 清除写请求
       
     // 写端计数处理
     if (wr)
       wr_fifo_cnt <= 1'b1; // 写入时设置计数为1
     if ({rd_syn2, rd_syn1} == 2'b01) // 检测读同步信号上升沿
       wr_fifo_cnt <= 1'b0; // 清零计数
       
     // 写数据寄存
     if (wr)
       wr_data_r <= wr_data; // 锁存写数据

   end


endmodule
