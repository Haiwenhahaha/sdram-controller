// sc_main.cpp
#include <systemc>
#include "Vtoplevel.h"  // 使用 --sc 生成的 SystemC 封装

int sc_main(int argc, char* argv[]) {
    sc_core::sc_clock sysclk("sysclk", sc_core::sc_time(10, sc_core::SC_NS)); // 100MHz示例
    sc_core::sc_signal<bool> rst_n, btn_n;
    sc_core::sc_signal<sc_dt::sc_uint<4>> gpio1;

    Vtoplevel top("top");
    top.sys_clk_pad_i(sysclk);
    top.rst_n_pad_i(rst_n);
    top.btn_n_pad_i(btn_n);
    top.gpio1_i(gpio1);
    // 其它输出/三态口可按需绑定 sc_signal/sc_signal_rv

    rst_n = false;
    btn_n = true;
    gpio1 = 0xA;

    sc_core::sc_start(sc_core::sc_time(200, sc_core::SC_NS)); // 复位期间
    rst_n = true;

    // 模拟一次单击
    btn_n = false;
    sc_core::sc_start(sc_core::sc_time(50, sc_core::SC_NS));
    btn_n = true;

    // 再跑一段
    sc_core::sc_start(sc_core::sc_time(10, sc_core::SC_US));
    return 0;
}