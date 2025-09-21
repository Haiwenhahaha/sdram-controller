/* 输入是一个按键信号
 * 检测按键在时间间隔内是双击还是单击。
 * 输出信号在复位前保持有效。
 */

module double_click (
  button,   // 按键输入

  single,   // 单击输出
  double,   // 双击输出

  clk,      // 时钟输入
  rst_n     // 复位输入
);

parameter WAIT_WIDTH = 19;  // 等待时间计数器宽度

input  button;     // 按键输入
output single,     // 单击输出
       double;     // 双击输出
input clk,         // 时钟输入
      rst_n;       // 复位输入

// 按键状态寄存器
reg btn_now,       // 当前按键状态
    btn_last,      // 上一次按键状态
    collect;       // 收集状态标志

// 计数寄存器
reg [2:0] click_cnt;                    // 点击计数器
reg [WAIT_WIDTH-1:0] dbl_click_cnt;     // 双击等待计数器

// 输出逻辑：计数完成且有1次点击为单击，否则为双击
assign single = (!dbl_click_cnt & (click_cnt == 3'b001)) ? 1'b1 : 1'b0;
assign double = (!dbl_click_cnt & (click_cnt != 3'b001)) ? 1'b1 : 1'b0;

// 检测按键按下（下降沿）
wire btn_down = btn_now & ~btn_last;
//wire btn_up =  ~btn_now &  btn_last;  // 未使用的按键释放检测

// 按键状态同步（在时钟下降沿处理，避免竞争条件）
always @ (negedge clk)
 if (~rst_n) 
  { btn_last, btn_now } <= 2'b00;  // 复位时清零按键状态
 else
  { btn_last, btn_now } <= { btn_now, button };  // 移位更新按键状态

// 开始递减计数并统计点击次数
always @ (posedge clk) 
 if (~rst_n)
  begin
  click_cnt <= 3'd0;                      // 复位时清零点击计数
  dbl_click_cnt <= {WAIT_WIDTH{1'b1}};    // 复位时设置等待计数为全1
  collect <= 1'b0;                        // 复位时清零收集标志
  end
 else
  begin
  // 等待计数器递减逻辑
  if (collect & (dbl_click_cnt != {WAIT_WIDTH{1'b0}})) 
    dbl_click_cnt <= dbl_click_cnt - 1'b1;  // 在收集状态下递减计数器
  else
    dbl_click_cnt <= dbl_click_cnt;         // 否则保持计数器不变
    
  // 按键按下处理
  if (btn_down)
    begin
    collect <= 1'b1;                        // 开始收集点击
    click_cnt <= click_cnt + 1'b1;          // 递增点击计数
    end
  else
    begin
    collect <= collect;                     // 保持收集状态
    click_cnt <= click_cnt;                 // 保持点击计数
    end  
  end

endmodule
