//////////////////////////////////////////////////////////////////////
//
// SystemC 版本的 SDRAM 控制器测试平台
// 基于 Verilator 生成的 SystemC 封装进行仿真
//
// 功能特点：
// 1. 使用 SystemC 框架进行仿真
// 2. 自动生成 VCD 波形文件
// 3. 多线程监控和驱动
// 4. 详细的信号监控和日志输出
//
//////////////////////////////////////////////////////////////////////

#include <systemc>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include "verilated.h"
#include "verilated_vcd_sc.h"
#include "Vtoplevel.h"

using namespace sc_core;
using namespace sc_dt;

// 全局变量用于统计和验证
static int test_cycles = 0;
static int button_press_count = 0;
static bool test_passed = true;

int sc_main(int argc, char* argv[]) {
    printf("=== SDRAM 控制器 SystemC 测试平台启动 ===\n");
    
    // 初始化 Verilator 参数
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);

    // 创建时钟信号：10ns 周期 = 100MHz
    // 注意：PLL 仿真桩会将此时钟直通到 100MHz 和 1MHz 两路
    sc_clock sysclk("sysclk", sc_time(10, SC_NS));
    printf("系统时钟：100MHz (10ns 周期)\n");

    // === 输入信号定义 ===
    sc_signal<bool> rst_n{"rst_n"};           // 复位信号，低电平有效
    sc_signal<bool> btn_n{"btn_n"};           // 按键信号，低电平有效
    sc_signal<sc_bv<4>> gpio1{"gpio1"};       // DIP 开关输入 (4位)

    // === SDRAM 控制信号定义 ===
    sc_signal<sc_bv<2>>  sdram_ba{"sdram_ba"};      // SDRAM 存储体地址 (2位)
    sc_signal<sc_bv<13>> sdram_a{"sdram_a"};        // SDRAM 行/列地址总线 (13位)
    sc_signal<bool>      sdram_cs_n{"sdram_cs_n"};  // 片选信号，低电平有效
    sc_signal<bool>      sdram_ras_n{"sdram_ras_n"}; // 行地址选通，低电平有效
    sc_signal<bool>      sdram_cas_n{"sdram_cas_n"}; // 列地址选通，低电平有效
    sc_signal<bool>      sdram_we_n{"sdram_we_n"};   // 写使能信号，低电平有效
    sc_signal<sc_bv<2>>  sdram_dqm{"sdram_dqm"};    // 数据掩码信号 (2位)
    sc_signal<bool>      sdram_cke{"sdram_cke"};     // 时钟使能信号
    sc_signal<bool>      sdram_clk{"sdram_clk"};     // SDRAM 时钟输出
    sc_signal<sc_bv<16>> sdram_dq{"sdram_dq"};       // 数据总线，双向16位

    // === GPIO 信号定义 ===
    sc_signal<sc_bv<8>>  gpio0{"gpio0"};      // GPIO0：LED 指示灯 (8位)

    // 实例化顶层模块
    Vtoplevel top("top");
    printf("顶层模块实例化完成\n");

    // === 信号绑定 ===
    // 基础信号
    top.sys_clk_pad_i(sysclk);
    top.rst_n_pad_i(rst_n);
    top.btn_n_pad_i(btn_n);

    // SDRAM 控制信号绑定
    top.sdram_ba_pad_o(sdram_ba);
    top.sdram_a_pad_o(sdram_a);
    top.sdram_cs_n_pad_o(sdram_cs_n);
    top.sdram_ras_pad_o(sdram_ras_n);    // 注意：这里使用 ras_n 信号
    top.sdram_cas_pad_o(sdram_cas_n);    // 注意：这里使用 cas_n 信号
    top.sdram_we_pad_o(sdram_we_n);      // 注意：这里使用 we_n 信号
    top.sdram_dq_pad_io(sdram_dq);
    top.sdram_dqm_pad_o(sdram_dqm);
    top.sdram_cke_pad_o(sdram_cke);
    top.sdram_clk_pad_o(sdram_clk);

    // GPIO 信号绑定
    top.gpio0_io(gpio0);
    top.gpio1_i(gpio1);

    printf("所有信号绑定完成\n");

    // === 波形跟踪设置 ===
    VerilatedVcdSc* tfp = new VerilatedVcdSc;
    top.trace(tfp, 99);  // 跟踪深度为 99 层
    tfp->open("wave_systemc.vcd");
    printf("VCD 波形文件：wave_systemc.vcd\n");

    // === 主驱动线程：控制复位、按键操作和测试序列 ===
    sc_spawn([&](){
        printf("\n=== 开始测试序列 ===\n");
        
        // 初始状态设置
        rst_n = false;  // 复位激活
        btn_n = true;   // 按键未按下
        gpio1 = sc_bv<4>("1010");  // DIP 开关设置为 0xA
        
        printf("初始状态：复位激活，DIP开关=0x%X\n", 
               (unsigned)gpio1.read().to_uint());

        // 复位序列：等待 10 个时钟周期
        printf("执行复位序列...\n");
        for (int i = 0; i < 10; ++i) {
            wait(sysclk.posedge_event());
            test_cycles++;
        }
        rst_n = true;  // 释放复位
        printf("复位释放，系统开始正常运行\n");

        // 等待系统初始化：50 个时钟周期
        printf("等待系统初始化...\n");
        for (int i = 0; i < 50; ++i) {
            wait(sysclk.posedge_event());
            test_cycles++;
        }
        printf("系统初始化完成\n");

        // 定义按键按下函数
        auto press_button = [&](int low_cycles, const char* description){
            printf("执行按键操作：%s (按下 %d 个周期)\n", description, low_cycles);
            button_press_count++;
            
            btn_n = false;  // 按下按键
            for (int i = 0; i < low_cycles; ++i) {
                wait(sysclk.posedge_event());
                test_cycles++;
            }
            btn_n = true;   // 释放按键
            
            // 释放后等待一段时间
            for (int i = 0; i < 50; ++i) {
                wait(sysclk.posedge_event());
                test_cycles++;
            }
            printf("按键操作完成：%s\n", description);
        };

        // === 测试序列 1：单击操作（触发写操作）===
        press_button(5, "单击 - 触发写操作");
        
        // 等待写操作完成
        for (int i = 0; i < 100; ++i) {
            wait(sysclk.posedge_event());
            test_cycles++;
        }

        // === 测试序列 2：双击操作（触发读操作）===
        press_button(5, "双击第一次 - 开始双击序列");
        
        // 短等待（小于双击检测窗口）
        for (int i = 0; i < 20; ++i) {
            wait(sysclk.posedge_event());
            test_cycles++;
        }
        
        press_button(5, "双击第二次 - 触发读操作");

        // 等待读操作完成
        for (int i = 0; i < 100; ++i) {
            wait(sysclk.posedge_event());
            test_cycles++;
        }

        // === 测试序列 3：连续操作测试 ===
        printf("\n=== 开始连续操作测试 ===\n");
        
        // 多次单击测试
        for (int i = 0; i < 3; ++i) {
            press_button(3, "连续单击测试");
            for (int j = 0; j < 50; ++j) {
                wait(sysclk.posedge_event());
                test_cycles++;
            }
        }

        // 继续运行一段时间观察系统行为
        printf("继续运行 2000 个周期进行观察...\n");
        for (int i = 0; i < 2000; ++i) {
            wait(sysclk.posedge_event());
            test_cycles++;
        }

        printf("\n=== 测试序列完成 ===\n");
        printf("总测试周期：%d\n", test_cycles);
        printf("按键操作次数：%d\n", button_press_count);
        
        // 停止仿真
        sc_stop();
    });

    // === 监控线程：实时监控和记录关键信号 ===
    sc_spawn([&](){
        unsigned long long cycle_count = 0;
        int sdram_command_count = 0;
        int last_cs_state = 1;
        
        printf("启动信号监控线程\n");
        
        while (true) {
            wait(sysclk.posedge_event());
            cycle_count++;
            
            // 检测 SDRAM 命令
            int cs_state = (int)sdram_cs_n.read();
            if (cs_state == 0 && last_cs_state == 1) {
                sdram_command_count++;
                printf("检测到 SDRAM 命令 #%d，周期 %llu\n", 
                       sdram_command_count, cycle_count);
            }
            last_cs_state = cs_state;
            
            // 每 100 个周期打印一次状态
            if (cycle_count % 100 == 0) {
                printf("周期 %6llu: cs=%d ras=%d cas=%d we=%d cke=%d ba=0x%X a=0x%04X\n",
                    cycle_count,
                    (int)sdram_cs_n.read(),
                    (int)sdram_ras_n.read(),
                    (int)sdram_cas_n.read(),
                    (int)sdram_we_n.read(),
                    (int)sdram_cke.read(),
                    (unsigned)sdram_ba.read().to_uint(),
                    (unsigned)(sdram_a.read().to_uint() & 0x1FFF)
                );
                
                // 检查异常状态
                if (!sdram_cke.read()) {
                    printf("警告：SDRAM 时钟使能信号为低！\n");
                    test_passed = false;
                }
            }
            
            // 每 1000 个周期检查一次系统状态
            if (cycle_count % 1000 == 0) {
                printf("系统状态检查 - 周期 %llu:\n", cycle_count);
                printf("  SDRAM 命令总数：%d\n", sdram_command_count);
                printf("  GPIO0 状态：0x%02X\n", (unsigned)gpio0.read().to_uint());
                printf("  GPIO1 状态：0x%X\n", (unsigned)gpio1.read().to_uint());
            }
        }
    });

    // === 验证线程：检查测试结果 ===
    sc_spawn([&](){
        wait(sc_time(50, SC_US));  // 等待测试完成
        
        printf("\n=== 测试结果验证 ===\n");
        
        // 验证基本功能
        if (test_cycles < 100) {
            printf("错误：测试周期数过少 (%d)\n", test_cycles);
            test_passed = false;
        }
        
        if (button_press_count < 2) {
            printf("错误：按键操作次数不足 (%d)\n", button_press_count);
            test_passed = false;
        }
        
        // 验证 SDRAM 基本信号
        if (sdram_cke.read() == false) {
            printf("错误：SDRAM 时钟使能信号异常\n");
            test_passed = false;
        }
        
        if (test_passed) {
            printf("✓ 所有基本测试通过\n");
        } else {
            printf("✗ 部分测试失败\n");
        }
    });

    // 开始仿真
    printf("\n开始 SystemC 仿真...\n");
    sc_start();  // 运行至 sc_stop()
    
    // 清理资源
    tfp->close();
    delete tfp;
    
    printf("\n=== 仿真结束 ===\n");
    printf("最终状态：%s\n", test_passed ? "通过" : "失败");
    
    return test_passed ? 0 : 1;
}
