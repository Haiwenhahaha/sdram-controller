// sc_main.cpp
#include <systemc>
#include <cstdio>
#include "verilated.h"
#include "verilated_vcd_sc.h"
#include "Vtoplevel.h"

using namespace sc_core;
using namespace sc_dt;	//data types

int sc_main(int argc, char* argv[]) {
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);

    // 时钟：10ns 周期=100MHz（PLL 仿真桩会把它直通到 100M/1M 两路）
    sc_clock sysclk("sysclk", sc_time(10, SC_NS));
	// 对比 sc_core::sc_clock sysclk("sysclk", sc_core::sc_time(10, sc_core::SC_NS)); 

    // 输入信号，有显示名字，方便调试
    sc_signal<bool> rst_n{"rst_n"};
    sc_signal<bool> btn_n{"btn_n"};
	//sc_bv 是“bit vector”，更适合表示引脚/总线的按位值（不做算术）
    sc_signal<sc_bv<4>> gpio1{"gpio1"};
	
    // 输出/三态信号
    sc_signal<sc_bv<2>>  sdram_ba{"sdram_ba"};
    sc_signal<sc_bv<13>> sdram_a{"sdram_a"};
    sc_signal<bool>      sdram_cs_n{"sdram_cs_n"};
    sc_signal<bool>      sdram_ras_n{"sdram_ras_n"};
    sc_signal<bool>      sdram_cas_n{"sdram_cas_n"};
    sc_signal<bool>      sdram_we_n{"sdram_we_n"};
    sc_signal<sc_bv<2>>  sdram_dqm{"sdram_dqm"};
    sc_signal<bool>      sdram_cke{"sdram_cke"};
    sc_signal<bool>      sdram_clk{"sdram_clk"};
    sc_signal<sc_bv<16>> sdram_dq{"sdram_dq"};   // inout，用普通 sc_signal 也可连接
    sc_signal<sc_bv<8>>  gpio0{"gpio0"};         // inout

    Vtoplevel top("top");
    // 绑定端口
    top.sys_clk_pad_i(sysclk);
    top.rst_n_pad_i(rst_n);
    top.btn_n_pad_i(btn_n);

    top.sdram_ba_pad_o(sdram_ba);
    top.sdram_a_pad_o(sdram_a);
    top.sdram_cs_n_pad_o(sdram_cs_n);
    top.sdram_ras_pad_o(sdram_ras_n);
    top.sdram_cas_pad_o(sdram_cas_n);
    top.sdram_we_pad_o(sdram_we_n);
    top.sdram_dq_pad_io(sdram_dq);
    top.sdram_dqm_pad_o(sdram_dqm);
    top.sdram_cke_pad_o(sdram_cke);
    top.sdram_clk_pad_o(sdram_clk);

    top.gpio0_io(gpio0);
    top.gpio1_i(gpio1);

    // 波形
    VerilatedVcdSc* tfp = new VerilatedVcdSc;
    top.trace(tfp, 99);
    tfp->open("wave.vcd");

	// 驱动线程（sc_spawn lambda）：复位、单击、双击、延时退出
	//初始化 rst_n/btn_n/gpio1； 
	//for 10 次 posedge 等待：wait(sysclk.posedge_event())；再释放复位； 
	//初始化等待 50 周期； 定义 press(low_cycles) 按键序列：拉低若干周期，再拉高并等 50 周期； 按序执行单击→双击→再次单击→长时间运行； 
	//最后 sc_stop(); 这是 SystemC 典型写法：通过事件等待（posedge_event）在时钟边沿同步推进。
    sc_spawn([&](){
        rst_n = false;
        btn_n = true;
        gpio1 = sc_bv<4>("1010");  // DIP: 0xA

        // 复位 10 个上升沿
        for (int i = 0; i < 10; ++i) wait(sysclk.posedge_event());
        rst_n = true;

        // 等待 50 周期用于初始化
        for (int i = 0; i < 50; ++i) wait(sysclk.posedge_event());

        auto press = [&](int low_cycles){
            btn_n = false;                         // 低为按下
            for (int i = 0; i < low_cycles; ++i) wait(sysclk.posedge_event());
            btn_n = true;
            for (int i = 0; i < 50; ++i) wait(sysclk.posedge_event());
        };

        // 单击（触发写）
        press(5);
        // 双击（触发读）
        press(5);
        for (int i = 0; i < 20; ++i) wait(sysclk.posedge_event());
        press(5);

        // 继续运行一段时间
        for (int i = 0; i < 2000; ++i) wait(sysclk.posedge_event());

        sc_stop();
    });

    // 打印线程：每 100 周期打印一次 SDRAM 关键信号
	// 循环 wait(posedge)，计数到 100 的倍数输出关键 SDRAM 信号； 
	// 用 sc_time_stamp().to_string() 打印当前 SystemC 时间。 两个线程并发执行，由 SystemC 调度器在每个事件点进行协同。
    sc_spawn([&](){
        unsigned long long cyc = 0;
        while (true) {
            wait(sysclk.posedge_event());
            ++cyc;
            if (cyc % 100 == 0) {
                std::printf("t=%s cyc=%6llu  sdram: cs=%d ras=%d cas=%d we=%d  cke=%d  ba=0x%X  a[12:0]=0x%04X\n",
                    sc_time_stamp().to_string().c_str(),
                    cyc,
                    (int)sdram_cs_n.read(),
                    (int)sdram_ras_n.read(),
                    (int)sdram_cas_n.read(),
                    (int)sdram_we_n.read(),
                    (int)sdram_cke.read(),
                    (unsigned)sdram_ba.read().to_uint(),
                    (unsigned)(sdram_a.read().to_uint() & 0x1FFF)
                );
            }
        }
    });

    sc_start();  // 运行至 sc_stop
    tfp->close();
    delete tfp;
    return 0;
}
