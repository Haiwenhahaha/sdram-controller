//////////////////////////////////////////////////////////////////////
//
// 高级 SDRAM 控制器测试平台
// 包含完整的测试套件、自动化验证和性能分析
//
// 功能特点：
// 1. 完整的测试套件（功能测试、性能测试、压力测试）
// 2. 自动化测试结果验证和报告生成
// 3. SDRAM 时序验证
// 4. 错误注入和故障测试
// 5. 性能统计和分析
// 6. 可配置的测试参数
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
#include <map>
#include <chrono>

// === 测试结果统计结构 ===
struct TestStatistics {
    vluint64_t total_cycles = 0;
    vluint64_t test_duration_us = 0;
    uint32_t button_operations = 0;
    uint32_t sdram_commands = 0;
    uint32_t write_operations = 0;
    uint32_t read_operations = 0;
    uint32_t errors_detected = 0;
    uint32_t warnings_count = 0;
    bool test_passed = true;
    
    // 性能指标
    double commands_per_second = 0.0;
    double operations_per_second = 0.0;
    double error_rate = 0.0;
};

// === SDRAM 时序验证结构 ===
struct SDRAMTiming {
    vluint64_t last_cs_assert_time = 0;
    vluint64_t last_ras_assert_time = 0;
    vluint64_t last_cas_assert_time = 0;
    vluint64_t last_we_assert_time = 0;
    
    // 时序要求（以时钟周期为单位）
    static const int MIN_CS_PULSE_WIDTH = 2;
    static const int MIN_RAS_TO_CAS_DELAY = 2;
    static const int MIN_CAS_TO_WE_DELAY = 1;
    static const int MIN_WE_PULSE_WIDTH = 1;
    static const int MAX_COMMAND_INTERVAL = 1000;
};

// === 错误注入配置 ===
struct ErrorInjection {
    bool inject_clock_glitch = false;
    bool inject_signal_noise = false;
    bool corrupt_data_bus = false;
    bool force_busy_state = false;
    
    int glitch_probability = 1;  // 1/1000 概率
    int noise_probability = 5;   // 5/1000 概率
};

// === 全局变量 ===
static vluint64_t main_time = 0;
static TestStatistics g_stats;
static SDRAMTiming g_timing;
static ErrorInjection g_error_injection;
static bool g_timing_violations_detected = false;

double sc_time_stamp() { return main_time; }

// === 测试配置 ===
struct AdvancedTestConfig {
    // 基础配置
    int reset_cycles = 10;
    int init_wait_cycles = 50;
    int button_press_cycles = 5;
    int button_release_wait = 50;
    int double_click_gap = 20;
    
    // 测试规模配置
    int functional_test_cycles = 1000;
    int performance_test_cycles = 5000;
    int stress_test_cycles = 10000;
    
    // 波形和报告配置
    bool enable_trace = true;
    std::string trace_filename = "advanced_test.vcd";
    std::string report_filename = "test_report.txt";
    
    // 验证配置
    bool enable_timing_check = true;
    bool enable_error_injection = false;
    bool enable_performance_analysis = true;
    
    // 错误注入配置
    int error_injection_rate = 100;  // 每1000个周期注入一次错误
};

static AdvancedTestConfig g_config;

// === 辅助函数 ===
void tick_clock(Vtoplevel* top, VerilatedVcdC* tfp = nullptr) {
    // 错误注入：时钟毛刺
    if (g_error_injection.inject_clock_glitch && 
        (rand() % 1000) < g_error_injection.glitch_probability) {
        // 注入时钟毛刺：额外的时钟脉冲
        top->sys_clk_pad_i = 1;
        top->eval();
        if (tfp) tfp->dump(main_time);
        main_time++;
        
        top->sys_clk_pad_i = 0;
        top->eval();
        if (tfp) tfp->dump(main_time);
        main_time++;
        
        printf("⚠️  注入时钟毛刺\n");
        g_stats.warnings_count++;
    }
    
    // 正常时钟周期
    top->sys_clk_pad_i = 1;
    top->eval();
    if (tfp) tfp->dump(main_time);
    main_time++;

    top->sys_clk_pad_i = 0;
    top->eval();
    if (tfp) tfp->dump(main_time);
    main_time++;
    
    g_stats.total_cycles++;
}

void press_button(Vtoplevel* top, VerilatedVcdC* tfp, 
                  int cycles_low, const char* description) {
    printf("🔘 执行按键操作：%s (按下 %d 个周期)\n", description, cycles_low);
    g_stats.button_operations++;
    
    top->btn_n_pad_i = 0;
    for (int i = 0; i < cycles_low; ++i) {
        tick_clock(top, tfp);
    }
    
    top->btn_n_pad_i = 1;
    for (int i = 0; i < g_config.button_release_wait; ++i) {
        tick_clock(top, tfp);
    }
    
    printf("✅ 按键操作完成：%s\n", description);
}

// === SDRAM 时序验证函数 ===
bool verify_sdram_timing(Vtoplevel* top) {
    if (!g_config.enable_timing_check) return true;
    
    bool timing_ok = true;
    int cs = top->sdram_cs_n_pad_o;
    int ras = top->sdram_ras_pad_o;
    int cas = top->sdram_cas_pad_o;
    int we = top->sdram_we_pad_o;
    
    // 检查 CS 脉冲宽度
    if (cs == 0 && g_timing.last_cs_assert_time > 0) {
        vluint64_t pulse_width = g_stats.total_cycles - g_timing.last_cs_assert_time;
        if (pulse_width < SDRAMTiming::MIN_CS_PULSE_WIDTH) {
            printf("❌ 时序违规：CS 脉冲宽度过短 (%llu < %d)\n", 
                   pulse_width, SDRAMTiming::MIN_CS_PULSE_WIDTH);
            timing_ok = false;
            g_timing_violations_detected = true;
        }
    }
    
    // 检查 RAS 到 CAS 延迟
    if (cas == 0 && g_timing.last_ras_assert_time > 0) {
        vluint64_t delay = g_stats.total_cycles - g_timing.last_ras_assert_time;
        if (delay < SDRAMTiming::MIN_RAS_TO_CAS_DELAY) {
            printf("❌ 时序违规：RAS 到 CAS 延迟过短 (%llu < %d)\n", 
                   delay, SDRAMTiming::MIN_RAS_TO_CAS_DELAY);
            timing_ok = false;
            g_timing_violations_detected = true;
        }
    }
    
    // 更新时序记录
    if (cs == 0) g_timing.last_cs_assert_time = g_stats.total_cycles;
    if (ras == 0) g_timing.last_ras_assert_time = g_stats.total_cycles;
    if (cas == 0) g_timing.last_cas_assert_time = g_stats.total_cycles;
    if (we == 0) g_timing.last_we_assert_time = g_stats.total_cycles;
    
    return timing_ok;
}

// === 信号监控和分析 ===
void monitor_and_analyze(Vtoplevel* top, vluint64_t cycle) {
    static int last_cs = 1, last_ras = 1, last_cas = 1, last_we = 1;
    static uint32_t command_sequence = 0;
    
    int cs = top->sdram_cs_n_pad_o;
    int ras = top->sdram_ras_pad_o;
    int cas = top->sdram_cas_pad_o;
    int we = top->sdram_we_pad_o;
    
    // 检测命令信号变化
    if (cs == 0 && last_cs == 1) {
        g_stats.sdram_commands++;
        command_sequence++;
        
        // 分析命令类型
        if (ras == 0 && cas == 0 && we == 0) {
            g_stats.read_operations++;
            printf("📖 检测到读命令 #%u\n", g_stats.read_operations);
        } else if (ras == 0 && cas == 0 && we == 1) {
            g_stats.write_operations++;
            printf("📝 检测到写命令 #%u\n", g_stats.write_operations);
        }
    }
    
    last_cs = cs; last_ras = ras; last_cas = cas; last_we = we;
    
    // 时序验证
    if (!verify_sdram_timing(top)) {
        g_stats.errors_detected++;
    }
    
    // 错误注入：信号噪声
    if (g_error_injection.inject_signal_noise && 
        (rand() % 1000) < g_error_injection.noise_probability) {
        // 随机翻转一个控制信号
        int signal_to_flip = rand() % 4;
        switch (signal_to_flip) {
            case 0: top->sdram_cs_n_pad_o = !top->sdram_cs_n_pad_o; break;
            case 1: top->sdram_ras_pad_o = !top->sdram_ras_pad_o; break;
            case 2: top->sdram_cas_pad_o = !top->sdram_cas_pad_o; break;
            case 3: top->sdram_we_pad_o = !top->sdram_we_pad_o; break;
        }
        printf("⚠️  注入信号噪声：翻转信号 %d\n", signal_to_flip);
        g_stats.warnings_count++;
    }
    
    // 周期性状态报告
    if (cycle % 500 == 0) {
        printf("🔄 周期 %6llu: 命令=%u 读=%u 写=%u 错误=%u\n",
               cycle, g_stats.sdram_commands, 
               g_stats.read_operations, g_stats.write_operations, 
               g_stats.errors_detected);
    }
}

// === 测试套件 ===

// 1. 功能测试
bool run_functional_test(Vtoplevel* top, VerilatedVcdC* tfp) {
    printf("\n🧪 === 功能测试开始 ===\n");
    
    // 基本按键操作测试
    press_button(top, tfp, g_config.button_press_cycles, "功能测试 - 单击");
    
    for (int i = 0; i < 100; ++i) {
        tick_clock(top, tfp);
        monitor_and_analyze(top, g_stats.total_cycles);
    }
    
    // 双击测试
    press_button(top, tfp, g_config.button_press_cycles, "功能测试 - 双击1");
    for (int i = 0; i < g_config.double_click_gap; ++i) {
        tick_clock(top, tfp);
        monitor_and_analyze(top, g_stats.total_cycles);
    }
    press_button(top, tfp, g_config.button_press_cycles, "功能测试 - 双击2");
    
    // 运行功能测试周期
    for (int i = 0; i < g_config.functional_test_cycles; ++i) {
        tick_clock(top, tfp);
        monitor_and_analyze(top, g_stats.total_cycles);
    }
    
    printf("✅ 功能测试完成\n");
    return g_stats.errors_detected == 0;
}

// 2. 性能测试
bool run_performance_test(Vtoplevel* top, VerilatedVcdC* tfp) {
    printf("\n⚡ === 性能测试开始 ===\n");
    
    auto start_time = std::chrono::high_resolution_clock::now();
    uint32_t initial_commands = g_stats.sdram_commands;
    
    // 快速连续操作
    for (int i = 0; i < 10; ++i) {
        press_button(top, tfp, 2, "性能测试 - 快速操作");
        for (int j = 0; j < 20; ++i) {
            tick_clock(top, tfp);
            monitor_and_analyze(top, g_stats.total_cycles);
        }
    }
    
    // 运行性能测试周期
    for (int i = 0; i < g_config.performance_test_cycles; ++i) {
        tick_clock(top, tfp);
        monitor_and_analyze(top, g_stats.total_cycles);
    }
    
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
    
    g_stats.test_duration_us = duration.count();
    uint32_t commands_during_test = g_stats.sdram_commands - initial_commands;
    
    if (g_stats.test_duration_us > 0) {
        g_stats.commands_per_second = (double)commands_during_test * 1000000.0 / g_stats.test_duration_us;
        g_stats.operations_per_second = (double)g_stats.button_operations * 1000000.0 / g_stats.test_duration_us;
    }
    
    printf("✅ 性能测试完成\n");
    printf("   测试时长：%llu 微秒\n", g_stats.test_duration_us);
    printf("   命令速率：%.2f 命令/秒\n", g_stats.commands_per_second);
    printf("   操作速率：%.2f 操作/秒\n", g_stats.operations_per_second);
    
    return true;
}

// 3. 压力测试
bool run_stress_test(Vtoplevel* top, VerilatedVcdC* tfp) {
    printf("\n💪 === 压力测试开始 ===\n");
    
    // 启用错误注入
    g_error_injection.inject_clock_glitch = true;
    g_error_injection.inject_signal_noise = true;
    
    // 极限操作频率
    for (int i = 0; i < 50; ++i) {
        press_button(top, tfp, 1, "压力测试 - 极限操作");
        for (int j = 0; j < 5; ++j) {
            tick_clock(top, tfp);
            monitor_and_analyze(top, g_stats.total_cycles);
        }
    }
    
    // 长时间运行
    for (int i = 0; i < g_config.stress_test_cycles; ++i) {
        tick_clock(top, tfp);
        monitor_and_analyze(top, g_stats.total_cycles);
        
        // 定期检查系统状态
        if (i % 1000 == 0 && i > 0) {
            printf("🔄 压力测试进度：%d/%d (%.1f%%)\n", 
                   i, g_config.stress_test_cycles,
                   (float)i * 100.0f / g_config.stress_test_cycles);
        }
    }
    
    // 禁用错误注入
    g_error_injection.inject_clock_glitch = false;
    g_error_injection.inject_signal_noise = false;
    
    printf("✅ 压力测试完成\n");
    printf("   检测到的错误：%u\n", g_stats.errors_detected);
    printf("   警告次数：%u\n", g_stats.warnings_count);
    
    return g_stats.errors_detected < 10;  // 允许少量错误
}

// === 测试结果验证 ===
bool verify_all_tests() {
    printf("\n🔍 === 测试结果验证 ===\n");
    bool all_passed = true;
    
    // 基本功能验证
    if (g_stats.total_cycles < 1000) {
        printf("❌ 错误：测试周期数过少 (%llu)\n", g_stats.total_cycles);
        all_passed = false;
    } else {
        printf("✅ 测试周期数正常：%llu\n", g_stats.total_cycles);
    }
    
    if (g_stats.button_operations < 5) {
        printf("❌ 错误：按键操作次数不足 (%u)\n", g_stats.button_operations);
        all_passed = false;
    } else {
        printf("✅ 按键操作次数正常：%u\n", g_stats.button_operations);
    }
    
    // SDRAM 功能验证
    if (g_stats.sdram_commands == 0) {
        printf("❌ 错误：未检测到 SDRAM 命令\n");
        all_passed = false;
    } else {
        printf("✅ SDRAM 命令检测正常：%u\n", g_stats.sdram_commands);
    }
    
    if (g_stats.read_operations == 0 && g_stats.write_operations == 0) {
        printf("❌ 错误：未检测到读写操作\n");
        all_passed = false;
    } else {
        printf("✅ 读写操作检测正常：读=%u 写=%u\n", 
               g_stats.read_operations, g_stats.write_operations);
    }
    
    // 时序验证
    if (g_timing_violations_detected) {
        printf("❌ 错误：检测到时序违规\n");
        all_passed = false;
    } else {
        printf("✅ 时序验证通过\n");
    }
    
    // 错误率计算
    g_stats.error_rate = (double)g_stats.errors_detected / g_stats.total_cycles * 100.0;
    if (g_stats.error_rate > 0.1) {  // 错误率超过 0.1%
        printf("❌ 错误：错误率过高 (%.3f%%)\n", g_stats.error_rate);
        all_passed = false;
    } else {
        printf("✅ 错误率正常：%.3f%%\n", g_stats.error_rate);
    }
    
    return all_passed;
}

// === 报告生成 ===
void generate_test_report() {
    printf("\n📊 === 生成测试报告 ===\n");
    
    FILE* report = fopen(g_config.report_filename.c_str(), "w");
    if (!report) {
        printf("❌ 无法创建报告文件：%s\n", g_config.report_filename.c_str());
        return;
    }
    
    fprintf(report, "=== SDRAM 控制器测试报告 ===\n");
    fprintf(report, "测试时间：%s", ctime(&std::time(nullptr)));
    fprintf(report, "\n=== 测试统计 ===\n");
    fprintf(report, "总时钟周期：%llu\n", g_stats.total_cycles);
    fprintf(report, "测试时长：%llu 微秒\n", g_stats.test_duration_us);
    fprintf(report, "按键操作次数：%u\n", g_stats.button_operations);
    fprintf(report, "SDRAM 命令总数：%u\n", g_stats.sdram_commands);
    fprintf(report, "读操作次数：%u\n", g_stats.read_operations);
    fprintf(report, "写操作次数：%u\n", g_stats.write_operations);
    fprintf(report, "检测到的错误：%u\n", g_stats.errors_detected);
    fprintf(report, "警告次数：%u\n", g_stats.warnings_count);
    
    fprintf(report, "\n=== 性能指标 ===\n");
    fprintf(report, "命令处理速率：%.2f 命令/秒\n", g_stats.commands_per_second);
    fprintf(report, "操作处理速率：%.2f 操作/秒\n", g_stats.operations_per_second);
    fprintf(report, "错误率：%.3f%%\n", g_stats.error_rate);
    
    fprintf(report, "\n=== 测试结果 ===\n");
    fprintf(report, "总体结果：%s\n", g_stats.test_passed ? "通过" : "失败");
    fprintf(report, "时序验证：%s\n", g_timing_violations_detected ? "失败" : "通过");
    
    fclose(report);
    printf("✅ 测试报告已保存：%s\n", g_config.report_filename.c_str());
}

// === 命令行参数解析 ===
void parse_arguments(int argc, char** argv) {
    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];
        
        if (arg == "--no-trace") {
            g_config.enable_trace = false;
        } else if (arg.find("--trace-file=") == 0) {
            g_config.trace_filename = arg.substr(13);
        } else if (arg.find("--report-file=") == 0) {
            g_config.report_filename = arg.substr(14);
        } else if (arg.find("--cycles=") == 0) {
            g_config.stress_test_cycles = std::atoi(arg.substr(9).c_str());
        } else if (arg == "--enable-error-injection") {
            g_config.enable_error_injection = true;
        } else if (arg == "--disable-timing-check") {
            g_config.enable_timing_check = false;
        } else if (arg == "--help") {
            printf("用法：%s [选项]\n", argv[0]);
            printf("选项：\n");
            printf("  --no-trace                    禁用波形跟踪\n");
            printf("  --trace-file=文件名           指定波形文件名\n");
            printf("  --report-file=文件名          指定报告文件名\n");
            printf("  --cycles=数量                 指定压力测试周期数\n");
            printf("  --enable-error-injection      启用错误注入测试\n");
            printf("  --disable-timing-check        禁用时序检查\n");
            printf("  --help                        显示此帮助信息\n");
            exit(0);
        }
    }
}

// === 主函数 ===
int main(int argc, char** argv) {
    printf("🚀 === 高级 SDRAM 控制器测试平台启动 ===\n");
    
    // 解析命令行参数
    parse_arguments(argc, argv);
    
    // 初始化随机数种子
    srand(time(nullptr));
    
    // 初始化 Verilator
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(g_config.enable_trace);
    printf("✅ Verilator 初始化完成\n");

    // 创建顶层模块实例
    Vtoplevel* top = new Vtoplevel;
    printf("✅ 顶层模块实例化完成\n");

    // 波形跟踪设置
    VerilatedVcdC* tfp = nullptr;
    if (g_config.enable_trace) {
        tfp = new VerilatedVcdC;
        top->trace(tfp, 99);
        tfp->open(g_config.trace_filename.c_str());
        printf("✅ VCD 波形文件：%s\n", g_config.trace_filename.c_str());
    }

    // 初始状态设置
    top->sys_clk_pad_i = 0;
    top->rst_n_pad_i = 0;
    top->btn_n_pad_i = 1;
    top->gpio1_i = 0xA;
    
    printf("✅ 初始状态设置完成\n");

    // 复位序列
    printf("\n🔄 === 系统复位 ===\n");
    for (int i = 0; i < g_config.reset_cycles; ++i) {
        tick_clock(top, tfp);
    }
    top->rst_n_pad_i = 1;
    printf("✅ 复位完成，系统开始运行\n");

    // 系统初始化等待
    printf("⏳ 等待系统初始化...\n");
    for (int i = 0; i < g_config.init_wait_cycles; ++i) {
        tick_clock(top, tfp);
        monitor_and_analyze(top, g_stats.total_cycles);
    }
    printf("✅ 系统初始化完成\n");

    // 运行测试套件
    bool functional_test_passed = run_functional_test(top, tfp);
    bool performance_test_passed = run_performance_test(top, tfp);
    bool stress_test_passed = run_stress_test(top, tfp);
    
    // 综合测试结果验证
    g_stats.test_passed = functional_test_passed && 
                          performance_test_passed && 
                          stress_test_passed &&
                          verify_all_tests();

    // 生成测试报告
    generate_test_report();

    // 清理资源
    if (tfp) {
        tfp->close();
        delete tfp;
    }
    top->final();
    delete top;

    // 最终结果
    printf("\n🎯 === 测试完成 ===\n");
    printf("总体结果：%s\n", g_stats.test_passed ? "✅ 通过" : "❌ 失败");
    printf("详细报告：%s\n", g_config.report_filename.c_str());
    
    return g_stats.test_passed ? 0 : 1;
}
