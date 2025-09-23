// sim_main.cpp
#include "Vtoplevel.h"
#include "verilated.h"	//Verilated 运行时 API（VerilatedContext、gotFinish、final 等），解析命令行、时间管理。
#if VM_TRACE
#include "verilated_vcd_c.h"   //或 "verilated_fst_c.h"：如果需要波形，分别用于 VCD 或 FST 追踪类。
#endif
#include <cstdio>	//标准库：打印（printf）与整数类型（如 uint32_t）。printf 用于周期性输出 SDRAM 控制信号，便于观察。
#include <cstdint>



//旧式 API vs 上下文 API
//本例用全局 main_time + sc_time_stamp 的旧式写法。等价的现代写法是用 VerilatedContext::time() / timeInc() 管理时间，更便于多实例/多上下文；功能相同。

static vluint64_t main_time = 0;
double sc_time_stamp() { return main_time; }

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);//VM_TRACE 控制是否编译波形代码；traceEverOn(true) 控制运行时是否真正记录。两者都需要（带 --trace 构建时通常自动满足 VM_TRACE）。

    Vtoplevel* top = new Vtoplevel;

#if VM_TRACE	//方便一套源码，既能无波形快速仿真（更快），也能带波形调试（更慢）。编译时控制 VM_TRACE 即可切换。
    VerilatedVcdC* tfp = new VerilatedVcdC;		//创建 VCD 追踪对象。
    top->trace(tfp, 99);		//注册需要追踪的层次，99 表示层级深度（越大越深入）。过大对性能略有影响，常见取值 5~99。
    tfp->open("wave.vcd");	//开输出文件。后续每次 dump() 会写入这个文件。
#endif

    auto eval_dump = [&]() {
        top->eval();
#if VM_TRACE
        tfp->dump(main_time);
#endif
    };//封装一次“求值并（可选）写波形”的操作，减少重复代码。dump 使用当前 main_time 作为时间戳，保证每次 eval 后的信号值与该时间对应。

    auto tick = [&]() {
        // 上升沿
        top->sys_clk_pad_i = 1;
        eval_dump();
        main_time++;

        // 下降沿
        top->sys_clk_pad_i = 0;
        eval_dump();
        main_time++;
    };//tick 执行一个完整时钟周期（含上升沿与下降沿），每个半周期推进 main_time：
	//每个边沿都有独立时间戳（t, t+1），波形更清晰；
	//本例每个“半周期”main_time++，因此一个完整周期是 2 个时间单位。VCD 会按这个时间显示。若希望 1 时间单位=1个完整周期，可把 dump 放在两个半周期后再统一自增，或每个 tick 只增加一次 main_time。
	

    // 初始输入
	// sys_clk_pad_i、rst_n_pad_i、btn_n_pad_i、gpio1_i 等需与 RTL 顶层端口一致；若你改了顶层名或端口名，记得对应修改。
    top->sys_clk_pad_i  = 0;
    top->rst_n_pad_i    = 0;  // 低有效复位
    top->btn_n_pad_i    = 1;  // 未按下
    top->gpio1_i        = 0xA; // DIP 开关示例: 1010

    // 若顶层将 inout 作为端口变量暴露出来，可以显式清零（可选）
	// 若 inout 端口在 C++ 模型中以变量形式暴露（有时会是 tri 信号/代理类），可以在仿真初始化为 0，避免 X。是否需要视 Verilator 生成方式而定。
    // top->sdram_dq_pad_io = 0;
    // top->gpio0_io = 0;

    // 复位10 周期
    for (int i = 0; i < 10; ++i) tick();
    top->rst_n_pad_i = 1;

    // 再跑50 空周期间，等待初始化
    for (int i = 0; i < 50; ++i) tick();

    // 模拟一次“单击”（btn_n 为低表示按下）	
	// 将 btn_n 拉低 cycles_low 个周期模拟“按下”，再拉回高电平并等待 50 周期，模拟“按下-抬起-消抖/间隔”的完整事件。
    auto press_button = [&](int cycles_low) {
        top->btn_n_pad_i = 0;
        for (int i = 0; i < cycles_low; ++i) tick();
        top->btn_n_pad_i = 1;
        // 释放后再等一会儿
        for (int i = 0; i < 50; ++i) tick();
    };

    // 单击：应触发 wr_enable（写通路）
    press_button(5);

    // 双击：间隔较短的两次按下，应触发 rd_enable（读通路）
    press_button(5);
    // 短等待（小于 double_click 的窗口），再按一次
    for (int i = 0; i < 20; ++i) tick();
    press_button(5);

    // 主循环，观察一段时间
    for (int i = 0; i < 2000; ++i) {
        // 可选：周期性打印若干关键信号
        if ((i % 100) == 0) {//便于在不看波形的情况下监视 SDRAM 时序信号是否按期望序列变化。
            printf("t=%6llu  sdram: cs=%d ras=%d cas=%d we=%d  cke=%d  ba=%02x  a[12:0]=0x%04x\n",
			//注意强制类型转换为 int/unsigned，避免把 sc_bv/uintX_t 之类类型直接交给 printf 导致告警。
                   (unsigned long long)main_time,
                   (int)top->sdram_cs_n_pad_o,
                   (int)top->sdram_ras_pad_o,
                   (int)top->sdram_cas_pad_o,
                   (int)top->sdram_we_pad_o,
                   (int)top->sdram_cke_pad_o,
                   (unsigned)(top->sdram_ba_pad_o & 0x3),
                   (unsigned)(top->sdram_a_pad_o & 0x1FFF));
        }
        tick();
        if (Verilated::gotFinish()) break;	//再运行 2000 个周期（遇到 $finish 则提前退出）。
    }

#if VM_TRACE
    tfp->close();
    delete tfp;//关闭波形文件，释放追踪对象。
#endif
    top->final();	//触发 Verilog final 块、覆盖率/断言收尾等。
    delete top;
    return 0;//释放模型并正常退出。
}
