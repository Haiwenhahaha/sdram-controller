// Verilated -*- SystemC -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtoplevel.h for the primary calling header

#include "Vtoplevel__pch.h"
#include "Vtoplevel__Syms.h"
#include "Vtoplevel___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtoplevel___024root___dump_triggers__ico(Vtoplevel___024root* vlSelf);
#endif  // VL_DEBUG

void Vtoplevel___024root___eval_triggers__ico(Vtoplevel___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel___024root___eval_triggers__ico\n"); );
    Vtoplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered.setBit(0U, (IData)(vlSelfRef.__VicoFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtoplevel___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtoplevel___024root___dump_triggers__act(Vtoplevel___024root* vlSelf);
#endif  // VL_DEBUG

void Vtoplevel___024root___eval_triggers__act(Vtoplevel___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel___024root___eval_triggers__act\n"); );
    Vtoplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.setBit(0U, ((IData)(vlSelfRef.__Vcellinp__toplevel__sys_clk_pad_i) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP____Vcellinp__toplevel__sys_clk_pad_i__0))));
    vlSelfRef.__VactTriggered.setBit(1U, ((IData)(vlSelfRef.toplevel__DOT__clk1m) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__toplevel__DOT__clk1m__0))));
    vlSelfRef.__VactTriggered.setBit(2U, ((~ (IData)(vlSelfRef.toplevel__DOT__clk1m)) 
                                          & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__toplevel__DOT__clk1m__0)));
    vlSelfRef.__Vtrigprevexpr___TOP____Vcellinp__toplevel__sys_clk_pad_i__0 
        = vlSelfRef.__Vcellinp__toplevel__sys_clk_pad_i;
    vlSelfRef.__Vtrigprevexpr___TOP__toplevel__DOT__clk1m__0 
        = vlSelfRef.toplevel__DOT__clk1m;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtoplevel___024root___dump_triggers__act(vlSelf);
    }
#endif
}
