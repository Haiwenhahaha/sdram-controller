// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vtoplevel__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vtoplevel::Vtoplevel(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vtoplevel__Syms(contextp(), _vcname__, this)}
    , sys_clk_pad_i{vlSymsp->TOP.sys_clk_pad_i}
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
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

Vtoplevel::Vtoplevel(const char* _vcname__)
    : Vtoplevel(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vtoplevel::~Vtoplevel() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vtoplevel___024root___eval_debug_assertions(Vtoplevel___024root* vlSelf);
#endif  // VL_DEBUG
void Vtoplevel___024root___eval_static(Vtoplevel___024root* vlSelf);
void Vtoplevel___024root___eval_initial(Vtoplevel___024root* vlSelf);
void Vtoplevel___024root___eval_settle(Vtoplevel___024root* vlSelf);
void Vtoplevel___024root___eval(Vtoplevel___024root* vlSelf);

void Vtoplevel::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtoplevel::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vtoplevel___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vtoplevel___024root___eval_static(&(vlSymsp->TOP));
        Vtoplevel___024root___eval_initial(&(vlSymsp->TOP));
        Vtoplevel___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vtoplevel___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vtoplevel::eventsPending() { return false; }

uint64_t Vtoplevel::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vtoplevel::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vtoplevel___024root___eval_final(Vtoplevel___024root* vlSelf);

VL_ATTR_COLD void Vtoplevel::final() {
    Vtoplevel___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vtoplevel::hierName() const { return vlSymsp->name(); }
const char* Vtoplevel::modelName() const { return "Vtoplevel"; }
unsigned Vtoplevel::threads() const { return 1; }
void Vtoplevel::prepareClone() const { contextp()->prepareClone(); }
void Vtoplevel::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vtoplevel::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vtoplevel___024root__trace_decl_types(VerilatedVcd* tracep);

void Vtoplevel___024root__trace_init_top(Vtoplevel___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vtoplevel___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtoplevel___024root*>(voidSelf);
    Vtoplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    Vtoplevel___024root__trace_decl_types(tracep);
    Vtoplevel___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vtoplevel___024root__trace_register(Vtoplevel___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vtoplevel::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vtoplevel::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace-vcd with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vtoplevel___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
