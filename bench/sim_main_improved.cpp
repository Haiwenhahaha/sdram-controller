//////////////////////////////////////////////////////////////////////
//
// Verilator 纯 C++ 版本的 SDRAM 控制器测试平台
// 直接使用 Verilator 生成的 C++ 模型进行仿真
//
// 功能特点：
// 1. 最高性能的仿真方式
// 2. 自动生成 VCD 波形文件
// 3. 详细的信号监控和验证
// 4. 自动化的测试结果检查
// 5. 可配置的测试参数
//
//////////////////////////////////////////////////////////////////////

#include "Vtoplevel.h"
#include "verilated.h"
#if VM_TRACE
#include "verilated_vcd_c.h"
#endif
#include <cstdio>
#include <cstdint>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <string>

// === 全局变量和配置 ===
static vluint64_t main_time = 0;        // 仿真时间计数器
static vluint64_t test_start_time = 0;  // 测试开始时间
static bool test_passed = true;         // 测试结果标志
static int total_cycles = 0;            // 总时钟周期计数
static int button_operations = 0;       // 按键操作计数

// 时间戳函数，供 Verilator 使用
double sc_time_stamp() { 
    return main_time; 
}

// === 测试配置结构 ===
struct TestConfig {
    int reset_cycles = 10;          // 复位周期数
    int init_wait_cycles = 50;      // 初始化等待周期数
    int button_press_cycles = 5;    // 按键按下周期数
    int button_release_wait = 50;   // 按键释放后等待周期数
    int double_click_gap = 20;      // 双击间隔周期数
    int observation_cycles = 2000;  // 观察周期数
    bool enable_trace = true;       // 是否启用波形跟踪
    std::string trace_filename = "wave_verilator.vcd";  // 波形文件名
};

// 全局测试配置
static TestConfig g_config;

// === 信号状态监控结构 ===
struct SignalMonitor {
    uint32_t cs_commands = 0;       // CS 命令计数
    uint32_t ras_commands = 0;      // RAS 命令计数
    uint32_t cas_commands = 0;      // CAS 命令计数
    uint32_t we_commands = 0;       // WE 命令计数
    uint32_t last_ba = 0;           // 最后的存储体地址
    uint32_t last_addr = 0;         // 最后的地址
    bool cke_stable = true;         // 时钟使能信号稳定性
    bool clock_detected = false;    // 时钟检测
};

static SignalMonitor g_monitor;

// === 辅助函数：时钟周期驱动 ===
void tick_clock(Vtoplevel* top, VerilatedVcdC* tfp = nullptr) {
    // 上升沿
    top->sys_clk_pad_i = 1;
    top->eval();
    if (tfp) tfp->dump(main_time);
    main_time++;

    // 下降沿
    top->sys_clk_pad_i = 0;
    top->eval();
    if (tfp) tfp->dump(main_time);
    main_time++;
    
    total_cycles++;
}

// === 辅助函数：按键操作 ===
void press_button(Vtoplevel* top, VerilatedVcdC* tfp, 
                  int cycles_low, const char* description) {
    printf("执行按键操作：%s (按下 %d 个周期)\n", description, cycles_low);
    button_operations++;
    
    top->btn_n_pad_i = 0;  // 按下按键
    for (int i = 0; i < cycles_low; ++i) {
        tick_clock(top, tfp);
    }
    
    top->btn_n_pad_i = 1;  // 释放按键
    for (int i = 0; i < g_config.button_release_wait; ++i) {
        tick_clock(top, tfp);
    }
    
    printf("按键操作完成：%s\n", description);
}

// === 信号监控和分析函数 ===
void monitor_signals(Vtoplevel* top, vluint64_t cycle) {
    // 检测 SDRAM 命令信号变化
    static int last_cs = 1, last_ras = 1, last_cas = 1, last_we = 1;
    
    int cs = top->sdram_cs_n_pad_o;
    int ras = top->sdram_ras_pad_o;
    int cas = top->sdram_cas_pad_o;
    int we = top->sdram_we_pad_o;
    
    // 检测命令信号变化
    if (cs == 0 && last_cs == 1) g_monitor.cs_commands++;
    if (ras == 0 && last_ras == 1) g_monitor.ras_commands++;
    if (cas == 0 && last_cas == 1) g_monitor.cas_commands++;
    if (we == 0 && last_we == 1) g_monitor.we_commands++;
    
    last_cs = cs; last_ras = ras; last_cas = cas; last_we = we;
    
    // 更新地址信息
    g_monitor.last_ba = top->sdram_ba_pad_o;
    g_monitor.last_addr = top->sdram_a_pad_o;
    
    // 检查时钟使能信号
    if (!top->sdram_cke_pad_o) {
        g_monitor.cke_stable = false;
    }
    
    // 检测时钟信号
    if (top->sdram_clk_pad_o) {
        g_monitor.clock_detected = true;
    }
    
    // 周期性状态报告
    if (cycle % 100 == 0) {
        printf("周期 %6llu: cs=%d ras=%d cas=%d we=%d cke=%d ba=0x%X a=0x%04X gpio0=0x%02X\n",
               cycle,
               cs, ras, cas, we,
               (int)top->sdram_cke_pad_o,
               (unsigned)(top->sdram_ba_pad_o & 0x3),
               (unsigned)(top->sdram_a_pad_o & 0x1FFF),
               (unsigned)(top->gpio0_io & 0xFF));
    }
    
    // 详细状态报告
    if (cycle % 1000 == 0) {
        printf("\n=== 详细状态报告 - 周期 %llu ===\n", cycle);
        printf("SDRAM 命令统计：\n");
        printf("  CS 命令：%u\n", g_monitor.cs_commands);
        printf("  RAS 命令：%u\n", g_monitor.ras_commands);
        printf("  CAS 命令：%u\n", g_monitor.cas_commands);
        printf("  WE 命令：%u\n", g_monitor.we_commands);
        printf("当前地址：BA=0x%X, A=0x%04X\n", 
               g_monitor.last_ba, g_monitor.last_addr);
        printf("系统状态：CKE=%s, 时钟检测=%s\n",
               top->sdram_cke_pad_o ? "正常" : "异常",
               g_monitor.clock_detected ? "是" : "否");
        printf("按键操作次数：%d\n", button_operations);
    }
}

// === 测试验证函数 ===
bool verify_test_results(Vtoplevel* top) {
    printf("\n=== 测试结果验证 ===\n");
    bool all_passed = true;
    
    // 验证基本功能
    if (total_cycles < 100) {
        printf("❌ 错误：测试周期数过少 (%d)\n", total_cycles);
        all_passed = false;
    } else {
        printf("✓ 测试周期数正常：%d\n", total_cycles);
    }
    
    if (button_operations < 2) {
        printf("❌ 错误：按键操作次数不足 (%d)\n", button_operations);
        all_passed = false;
    } else {
        printf("✓ 按键操作次数正常：%d\n", button_operations);
    }
    
    // 验证 SDRAM 信号
    if (!g_monitor.cke_stable) {
        printf("❌ 错误：SDRAM 时钟使能信号异常\n");
        all_passed = false;
    } else {
        printf("✓ SDRAM 时钟使能信号正常\n");
    }
    
    if (!g_monitor.clock_detected) {
        printf("❌ 警告：未检测到 SDRAM 时钟信号\n");
    } else {
        printf("✓ SDRAM 时钟信号检测正常\n");
    }
    
    // 验证命令活动
    if (g_monitor.cs_commands == 0) {
        printf("❌ 警告：未检测到 SDRAM CS 命令\n");
    } else {
        printf("✓ 检测到 %u 个 SDRAM CS 命令\n", g_monitor.cs_commands);
    }
    
    // 验证系统最终状态
    if (top->sdram_cke_pad_o == 0) {
        printf("❌ 错误：最终状态 SDRAM 时钟使能信号为低\n");
        all_passed = false;
    }
    
    return all_passed;
}

// === 命令行参数解析 ===
void parse_arguments(int argc, char** argv) {
    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];
        
        if (arg == "--no-trace") {
            g_config.enable_trace = false;
        } else if (arg.find("--trace-file=") == 0) {
            g_config.trace_filename = arg.substr(13);
        } else if (arg.find("--cycles=") == 0) {
            g_config.observation_cycles = std::atoi(arg.substr(9).c_str());
        } else if (arg == "--help") {
            printf("用法：%s [选项]\n", argv[0]);
            printf("选项：\n");
            printf("  --no-trace              禁用波形跟踪\n");
            printf("  --trace-file=文件名     指定波形文件名\n");
            printf("  --cycles=数量           指定观察周期数\n");
            printf("  --help                 显示此帮助信息\n");
            exit(0);
        }
    }
}

// === 主函数 ===
int main(int argc, char** argv) {
    printf("=== SDRAM 控制器 Verilator 测试平台启动 ===\n");
    
    // 解析命令行参数
    parse_arguments(argc, argv);
    
    // 初始化 Verilator
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(g_config.enable_trace);
    printf("Verilator 初始化完成\n");

    // 创建顶层模块实例
    Vtoplevel* top = new Vtoplevel;
    printf("顶层模块实例化完成\n");

    // === 波形跟踪设置 ===
    VerilatedVcdC* tfp = nullptr;
    if (g_config.enable_trace) {
        tfp = new VerilatedVcdC;
        top->trace(tfp, 99);  // 跟踪深度为 99 层
        tfp->open(g_config.trace_filename.c_str());
        printf("VCD 波形文件：%s\n", g_config.trace_filename.c_str());
    }

    // === 仿真辅助函数定义 ===
    auto eval_dump = [&]() {
        top->eval();
        if (tfp) tfp->dump(main_time);
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
        
        total_cycles++;
        monitor_signals(top, total_cycles);
    };

    // === 初始状态设置 ===
    top->sys_clk_pad_i  = 0;
    top->rst_n_pad_i    = 0;  // 复位激活（低电平有效）
    top->btn_n_pad_i    = 1;  // 按键未按下
    top->gpio1_i        = 0xA; // DIP 开关设置为 0xA (1010)
    
    printf("初始状态设置完成\n");
    printf("  DIP 开关：0x%X\n", top->gpio1_i);

    // 初始化 inout 信号（可选，Verilator 会自动处理）
    // top->sdram_dq_pad_io = 0;
    // top->gpio0_io = 0;

    // === 复位序列 ===
    printf("\n=== 开始复位序列 ===\n");
    test_start_time = main_time;
    
    for (int i = 0; i < g_config.reset_cycles; ++i) {
        tick();
    }
    top->rst_n_pad_i = 1;  // 释放复位
    printf("复位释放，系统开始正常运行\n");

    // === 系统初始化等待 ===
    printf("等待系统初始化...\n");
    for (int i = 0; i < g_config.init_wait_cycles; ++i) {
        tick();
    }
    printf("系统初始化完成\n");

    // === 测试序列 1：单击操作（触发写操作）===
    printf("\n=== 测试序列 1：单击操作 ===\n");
    press_button(top, tfp, g_config.button_press_cycles, "单击 - 触发写操作");
    
    // 等待写操作完成
    printf("等待写操作完成...\n");
    for (int i = 0; i < 100; ++i) {
        tick();
    }

    // === 测试序列 2：双击操作（触发读操作）===
    printf("\n=== 测试序列 2：双击操作 ===\n");
    press_button(top, tfp, g_config.button_press_cycles, "双击第一次 - 开始双击序列");
    
    // 短等待（小于双击检测窗口）
    printf("双击间隔等待...\n");
    for (int i = 0; i < g_config.double_click_gap; ++i) {
        tick();
    }
    
    press_button(top, tfp, g_config.button_press_cycles, "双击第二次 - 触发读操作");

    // 等待读操作完成
    printf("等待读操作完成...\n");
    for (int i = 0; i < 100; ++i) {
        tick();
    }

    // === 测试序列 3：连续操作测试 ===
    printf("\n=== 测试序列 3：连续操作测试 ===\n");
    
    // 多次单击测试
    for (int i = 0; i < 3; ++i) {
        press_button(top, tfp, 3, "连续单击测试");
        for (int j = 0; j < 50; ++j) {
            tick();
        }
    }

    // === 观察阶段 ===
    printf("\n=== 观察阶段：运行 %d 个周期 ===\n", g_config.observation_cycles);
    for (int i = 0; i < g_config.observation_cycles; ++i) {
        tick();
        
        // 检查是否需要提前退出
        if (Verilated::gotFinish()) {
            printf("收到仿真停止信号\n");
            break;
        }
        
        // 每 500 个周期打印一次进度
        if (i % 500 == 0 && i > 0) {
            printf("观察进度：%d/%d 周期 (%.1f%%)\n", 
                   i, g_config.observation_cycles, 
                   (float)i * 100.0f / g_config.observation_cycles);
        }
    }

    // === 测试结果验证 ===
    test_passed = verify_test_results(top);

    // === 清理资源 ===
    if (tfp) {
        tfp->close();
        delete tfp;
    }
    top->final();
    delete top;

    // === 最终报告 ===
    printf("\n=== 仿真完成报告 ===\n");
    printf("总仿真时间：%llu 时间单位\n", main_time);
    printf("总时钟周期：%d\n", total_cycles);
    printf("按键操作次数：%d\n", button_operations);
    printf("SDRAM 命令统计：\n");
    printf("  CS 命令：%u\n", g_monitor.cs_commands);
    printf("  RAS 命令：%u\n", g_monitor.ras_commands);
    printf("  CAS 命令：%u\n", g_monitor.cas_commands);
    printf("  WE 命令：%u\n", g_monitor.we_commands);
    printf("测试结果：%s\n", test_passed ? "通过 ✓" : "失败 ❌");
    
    if (g_config.enable_trace) {
        printf("波形文件已保存：%s\n", g_config.trace_filename.c_str());
    }

    return test_passed ? 0 : 1;
}
