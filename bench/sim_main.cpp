// sim_main.cpp
#include "Vtoplevel.h"
#include "verilated.h"
#if VM_TRACE
#include "verilated_vcd_c.h"
#endif
#include <cstdio>
#include <cstdint>

static vluint64_t main_time = 0;
double sc_time_stamp() { return main_time; }

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);

    Vtoplevel* top = new Vtoplevel;

#if VM_TRACE
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace(tfp, 99);
    tfp->open("wave.vcd");
#endif

    auto eval_dump = [&]() {
        top->eval();
#if VM_TRACE
        tfp->dump(main_time);
#endif
    };

    auto tick = [&]() {
        // 上升沿
        top->sys_clk_pad_i = 1;
        eval_dump();
        main_time++;

        // 下降沿
        top->sys_clk_pad_i = 0;
        eval_dump();
        main_time++;
    };

    // 初始输入
    top->sys_clk_pad_i  = 0;
    top->rst_n_pad_i    = 0;  // 低有效复位
    top->btn_n_pad_i    = 1;  // 未按下
    top->gpio1_i        = 0xA; // DIP 开关示例: 1010

    // 若顶层将 inout 作为端口变量暴露出来，可以显式清零（可选）
    // top->sdram_dq_pad_io = 0;
    // top->gpio0_io = 0;

    // 复位若干周期
    for (int i = 0; i < 10; ++i) tick();
    top->rst_n_pad_i = 1;

    // 再跑一些空周期间，等待初始化
    for (int i = 0; i < 50; ++i) tick();

    // 模拟一次“单击”（btn_n 为低表示按下）
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
        if ((i % 100) == 0) {
            printf("t=%6llu  sdram: cs=%d ras=%d cas=%d we=%d  cke=%d  ba=%02x  a[12:0]=0x%04x\n",
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
        if (Verilated::gotFinish()) break;
    }

#if VM_TRACE
    tfp->close();
    delete tfp;
#endif
    top->final();
    delete top;
    return 0;
}