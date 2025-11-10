// Verilated -*- SystemC -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vtoplevel__pch.h"		// 预编译头，包含常用/生成的内部声明，提升编译速度
#include "verilated_vcd_sc.h"

//============================================================
// Constructors

Vtoplevel::Vtoplevel(sc_core::sc_module_name /* unused */)
    : VerilatedModel{*Verilated::threadContextp()}// 初始化基类 VerilatedModel，绑定当前线程上下文
    , vlSymsp{new Vtoplevel__Syms(contextp(), name(), this)} // 创建符号表（模型全局状态），传入上下文、名字、this 指针
    , sys_clk_pad_i{vlSymsp->TOP.sys_clk_pad_i}		// 以下把端口引用绑定到根实例 TOP 的对应端口
    , rst_n_pad_i{vlSymsp->TOP.rst_n_pad_i}
    , btn_n_pad_i{vlSymsp->TOP.btn_n_pad_i}
    , sdram_ba_pad_o{vlSymsp->TOP.sdram_ba_pad_o}
    , sdram_cs_n_pad_o{vlSymsp->TOP.sdram_cs_n_pad_o}
    , sdram_ras_pad_o{vlSymsp->TOP.sdram_ras_pad_o}
    , sdram_cas_pad_o{vlSymsp->TOP.sdram_cas_pad_o}
    , sdram_we_pad_o{vlSymsp->TOP.sdram_we_pad_o}
    , sdram_dqm_pad_o{vlSymsp->TOP.sdram_dqm_pad_o}
    , sdram_cke_pad_o{vlSymsp->TOP.sdram_cke_pad_o}
    , sdram_clk_pad_o{vlSymsp->TOP.sdram_clk_pad_o}
    , gpio0_io{vlSymsp->TOP.gpio0_io}
    , gpio1_i{vlSymsp->TOP.gpio1_i}
    , sdram_a_pad_o{vlSymsp->TOP.sdram_a_pad_o}
    , sdram_dq_pad_io{vlSymsp->TOP.sdram_dq_pad_io}
    , rootp{&(vlSymsp->TOP)}			// rootp 指向顶层根实例，便于访问内部
{
    // Register model with the context
    contextp()->addModel(this);	// 将本模型注册到 Verilator 上下文（便于统一管理）
    contextp()->traceBaseModelCbAdd(	// 注册基础 trace 回调（打开波形文件时调用）
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
    // Sensitivities on all clocks and combinational inputs
    SC_METHOD(eval);	// 声明一个 SystemC 进程（方法进程）调用 eval()
    sensitive << sys_clk_pad_i;
    sensitive << rst_n_pad_i;
    sensitive << btn_n_pad_i;	// 对按键输入敏感
    sensitive << gpio0_io;
    sensitive << gpio1_i;
    sensitive << sdram_dq_pad_io;	// 对 SDRAM 数据总线（双向）敏感

}

//============================================================
// Destructor

Vtoplevel::~Vtoplevel() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vtoplevel___024root___eval_debug_assertions(Vtoplevel___024root* vlSelf);// 调试断言（编译为 debug 时可用）
#endif  // VL_DEBUG
void Vtoplevel___024root___eval_static(Vtoplevel___024root* vlSelf);// 静态阶段（一次性计算）
void Vtoplevel___024root___eval_initial(Vtoplevel___024root* vlSelf);
void Vtoplevel___024root___eval_settle(Vtoplevel___024root* vlSelf);// 稳定阶段（组合信号收敛）
void Vtoplevel___024root___eval(Vtoplevel___024root* vlSelf);// 正常评估（每次敏感触发时调用）

void Vtoplevel::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtoplevel::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vtoplevel___024root___eval_debug_assertions(&(vlSymsp->TOP));	
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();	// 清理延迟删除队列（Verilator 内部）
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {                                 // 若尚未初始化（首次调用）
        vlSymsp->__Vm_didInit = true;                                          // 置初始化完成标志
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vtoplevel___024root___eval_static(&(vlSymsp->TOP));                    // 执行静态初始化
        Vtoplevel___024root___eval_initial(&(vlSymsp->TOP));                   // 执行 initial 块
        Vtoplevel___024root___eval_settle(&(vlSymsp->TOP));                    // 组合逻辑收敛（settle）
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vtoplevel___024root___eval(&(vlSymsp->TOP));                               // 执行一次评估（时序/组合逻辑）
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);                             // 评估结束清理（消息队列/断言等）
}

//============================================================
// Events and timing
bool Vtoplevel::eventsPending() { return false; }                              // 返回是否存在计划事件：此处无时延设计，恒为 false

uint64_t Vtoplevel::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");            // 若调用下一时间槽，直接报错（设计无延时）
    return 0;                                                                  // 不会到达；为满足编译器返回值要求
}

//============================================================
// Utilities

//============================================================
// Invoke final blocks

void Vtoplevel___024root___eval_final(Vtoplevel___024root* vlSelf);            // 声明 final 阶段函数（Verilog final 块）

VL_ATTR_COLD void Vtoplevel::final() {
    Vtoplevel___024root___eval_final(&(vlSymsp->TOP));                         // 仿真结束时调用 final 块
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vtoplevel::hierName() const { return vlSymsp->name(); }            // 返回层级名（模型实例名）
const char* Vtoplevel::modelName() const { return "Vtoplevel"; }               // 返回模型名（类名）
unsigned Vtoplevel::threads() const { return 1; }                              // 线程数（本模型单线程）
void Vtoplevel::prepareClone() const { contextp()->prepareClone(); }           // 进程级克隆前准备（如 fork 前资源处理）
void Vtoplevel::atClone() const {
    contextp()->threadPoolpOnClone();                                          // 克隆后重建线程池等上下文资源
}
std::unique_ptr<VerilatedTraceConfig> Vtoplevel::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}}; // 跟踪配置（本模型禁用层次/时钟域等特性）
};

//============================================================
// Trace configuration

void Vtoplevel___024root__trace_decl_types(VerilatedVcd* tracep);              // 声明：注册所有信号类型到 VCD
                                                                               
void Vtoplevel___024root__trace_init_top(Vtoplevel___024root* vlSelf, VerilatedVcd* tracep); // 声明：顶层 trace 初始化

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vtoplevel___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtoplevel___024root*>(voidSelf); // 将 void* 转回根实例指针
    Vtoplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp; // 获取符号表
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {                          // 若未启用未使用信号计算（通常意味着未设置 traceEverOn）
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0."); // 在时间0之前必须调用 traceEverOn(true)
    }
    vlSymsp->__Vm_baseCode = code;                                             // 记录 trace 基准编码
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE); // 进入模块命名空间（层次前缀）
    Vtoplevel___024root__trace_decl_types(tracep);                              // 声明信号类型信息
    Vtoplevel___024root__trace_init_top(vlSelf, tracep);                        // 初始化顶层信号跟踪（绑定各信号）
    tracep->popPrefix();                                                        // 弹出命名空间前缀
}

VL_ATTR_COLD void Vtoplevel___024root__trace_register(Vtoplevel___024root* vlSelf, VerilatedVcd* tracep); // 声明：注册具体信号到 trace

VL_ATTR_COLD void Vtoplevel::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    if (!sc_core::sc_get_curr_simcontext()->elaboration_done()) {               // 若 SystemC 还未完成 elaboration（结构展开）
        vl_fatal(__FILE__, __LINE__, name(), "Vtoplevel::trace() is called before sc_core::sc_start(). Run sc_core::sc_start(sc_core::SC_ZERO_TIME) before trace() to complete elaboration."); // 报错提示需先 sc_start(0)
    }(void)levels; (void)options;                                               // 未使用的参数（避免编译告警）
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);              // 尝试将通用 trace 指针转为 VCD 专用类型
    if (VL_UNLIKELY(!stfp)) {                                                   // 若失败（传入的对象类型不匹配）
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vtoplevel::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace-vcd with VerilatedVcd object"); // 指导使用正确的 trace 类型/开关
    }
    stfp->spTrace()->addModel(this);                                            // 将本模型添加到 trace 会话
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));                   // 注册初始化回调（打开波形时调用 trace_init）
    Vtoplevel___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());      // 注册具体信号到 trace
}