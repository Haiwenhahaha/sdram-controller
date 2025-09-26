// sc_main.cpp
#include <systemc>
#include "Vtoplevel.h"  // 使用 --sc 生成的 SystemC 封装

int sc_main(int argc, char* argv[]) {
	//int main(int argc, char** argv) {
    sc_core::sc_clock sysclk("sysclk", sc_core::sc_time(10, sc_core::SC_NS)); //创建时钟：10ns 周期=100MHz 的系统时钟，SystemC 内建事件驱动。
	//用 sc_signal 封装的布尔和 4 位无符号输入。
    sc_core::sc_signal<bool> rst_n, btn_n;
    sc_core::sc_signal<sc_dt::sc_uint<4>> gpio1;
	//顶层实例与端口绑定
    Vtoplevel top("top");
    top.sys_clk_pad_i(sysclk);
    top.rst_n_pad_i(rst_n);
    top.btn_n_pad_i(btn_n);
    top.gpio1_i(gpio1);
    // 其它输出/三态口可按需绑定 sc_signal/sc_signal_rv

//初始刺激：
    rst_n = false;
    btn_n = true;
    gpio1 = 0xA;
	
//定长运行与改变信号
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
