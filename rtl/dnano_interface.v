/* DE0 Nano 接口模块，用于测试 SDRAM 控制器
 * 处理按键和开关的解析，
 * 与 SDRAM 控制器进行通信。
 */

module dnano_interface (
  /* 人机交互接口 */
  button_n,  // 按键输入
  dip,       // DIP 开关输入
  leds,      // LED 输出

  /* 控制器接口 */
  haddr,     // 主机地址：RW-FIFO 数据1
  busy,      // 忙信号：RW-FIFO 满
  
  wr_enable, // 写使能：WR-FIFO 写入
  wr_data,   // 写数据：WR-FIFO 数据2
  
  rd_enable, // 读使能：RO-FIFO 写入
  
  rd_data,   // 读数据：RI-FIFO 数据
  rd_rdy,    // 读就绪：RI-FIFO 非空
  rd_ack,    // 读确认：RI-FIFO 读取

  /* 基础信号 */
  rst_n,     // 复位信号
  clk        // 时钟信号
);

parameter HADDR_WIDTH = 24;  // 主机地址总线宽度

// 时钟频率与计数器位数的关系：
// @ 1MHz    19位 (512K) 约为 1/2 秒
// @ 100MHz  26位 (64M)  约为 1/2 秒
localparam DOUBlE_CLICK_WAIT = 19;  // 双击等待时间计数器宽度
localparam LED_BLINK = 20;          // LED 闪烁计数器宽度
 
// 输入输出端口定义
input        button_n;    // 按键输入，低电平有效
input  [3:0] dip;         // DIP 开关输入，4位
output [7:0] leds;        // LED 输出，8位

output [HADDR_WIDTH-1:0]   haddr;      // 主机地址输出
output [15:0]              wr_data;    // 写数据输出
input  [15:0]              rd_data;    // 读数据输入
input                      busy;       // 忙信号输入
output                     rd_enable;  // 读使能输出
input                      rd_rdy;     // 读就绪输入
output                     rd_ack;     // 读确认输出
output                     wr_enable;  // 写使能输出

input                      rst_n;      // 复位信号输入
input                      clk;        // 时钟输入

// 内部信号定义
wire  [15:0]              wr_data;    // 写数据线
reg   [15:0]              rd_data_r;  // 读数据寄存器
reg   [LED_BLINK-1:0]     led_cnt;    // LED 闪烁计数器
wire  [7:0]               leds;       // LED 输出线
wire                      wr_enable;  // 写使能线
reg                       rd_ack_r;   // 读确认寄存器

wire  dbl_clck_rst_n;     // 双击检测复位信号

// 双击检测复位信号的生成逻辑
// 我们希望在 SDRAM 忙时复位双击检测
// busy | rst_n
//  0      0     - 复位开启 (低电平)
//  0      1     - 复位关闭 (高电平)
//  1      0     - 忙 + 复位 (低电平)
//  1      1     - 忙信号开启 (低电平)
assign dbl_clck_rst_n = rst_n & ~busy;

// 将 DIP 开关数据从 4 位扩展到 16 位
// 重复 DIP 开关的值和其反值
assign wr_data = {dip, dip, ~dip, ~dip};

// LED 在 SDRAM 数据的高字节和低字节之间切换显示
assign leds = led_cnt[LED_BLINK-1] ? rd_data_r[15:8] : rd_data_r[7:0]; 

// 主机地址由 DIP 开关值重复生成
assign haddr  = {(HADDR_WIDTH/4){dip}};
assign rd_ack = rd_ack_r;

// LED 计数器处理，每半秒循环一次
always @ (posedge clk) 
 if (~rst_n) 
  led_cnt <= {LED_BLINK{1'b0}};  // 复位时清零 LED 计数器
 else
  led_cnt <= led_cnt + 1'b1;     // 其他时候递增计数器
   
// 读数据处理
always @ (posedge clk)
 if (~rst_n)
   begin
   rd_data_r <= 16'b0;  // 复位时清零读数据寄存器
   rd_ack_r <= 1'b0;    // 复位时清零读确认寄存器
   end
 else
   begin   
   rd_ack_r <= rd_rdy;  // 读确认信号跟随读就绪信号
   
   if (rd_rdy)
     rd_data_r <= rd_data;     // 读数据就绪时锁存数据
   else 
     rd_data_r <= rd_data_r;   // 否则保持原值
   end
   
// 双击检测模块实例化
double_click #(.WAIT_WIDTH(DOUBlE_CLICK_WAIT)) double_clicki (
  .button  (~button_n),        // 按键输入（取反，因为按键是低电平有效）
  .single  (wr_enable),        // 单击输出：写使能
  .double  (rd_enable),        // 双击输出：读使能
  .clk     (clk),             // 时钟输入
  .rst_n   (dbl_clck_rst_n)   // 复位输入：双击检测复位信号
);

endmodule
