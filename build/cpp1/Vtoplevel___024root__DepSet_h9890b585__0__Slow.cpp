// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtoplevel.h for the primary calling header

#include "Vtoplevel__pch.h"
#include "Vtoplevel___024root.h"

VL_ATTR_COLD void Vtoplevel___024root___eval_static(Vtoplevel___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel___024root___eval_static\n"); );
    Vtoplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__sys_clk_pad_i__0 
        = vlSelfRef.sys_clk_pad_i;
    vlSelfRef.__Vtrigprevexpr___TOP__toplevel__DOT__clk1m__0 
        = vlSelfRef.toplevel__DOT__clk1m;
}

VL_ATTR_COLD void Vtoplevel___024root___eval_initial__TOP(Vtoplevel___024root* vlSelf);
VL_ATTR_COLD void Vtoplevel___024root____Vm_traceActivitySetAll(Vtoplevel___024root* vlSelf);

VL_ATTR_COLD void Vtoplevel___024root___eval_initial(Vtoplevel___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel___024root___eval_initial\n"); );
    Vtoplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtoplevel___024root___eval_initial__TOP(vlSelf);
    Vtoplevel___024root____Vm_traceActivitySetAll(vlSelf);
}

VL_ATTR_COLD void Vtoplevel___024root___eval_initial__TOP(Vtoplevel___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel___024root___eval_initial__TOP\n"); );
    Vtoplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.toplevel__DOT__clk1m = 0U;
    vlSelfRef.toplevel__DOT__pll_1mi__DOT__cnt = 0U;
}

VL_ATTR_COLD void Vtoplevel___024root___eval_final(Vtoplevel___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel___024root___eval_final\n"); );
    Vtoplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtoplevel___024root___dump_triggers__stl(Vtoplevel___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtoplevel___024root___eval_phase__stl(Vtoplevel___024root* vlSelf);

VL_ATTR_COLD void Vtoplevel___024root___eval_settle(Vtoplevel___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel___024root___eval_settle\n"); );
    Vtoplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY(((0x64U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vtoplevel___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("rtl/toplevel.v", 30, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vtoplevel___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtoplevel___024root___dump_triggers__stl(Vtoplevel___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel___024root___dump_triggers__stl\n"); );
    Vtoplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtoplevel___024root___stl_sequent__TOP__0(Vtoplevel___024root* vlSelf);

VL_ATTR_COLD void Vtoplevel___024root___eval_stl(Vtoplevel___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel___024root___eval_stl\n"); );
    Vtoplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vtoplevel___024root___stl_sequent__TOP__0(vlSelf);
        Vtoplevel___024root____Vm_traceActivitySetAll(vlSelf);
    }
}

VL_ATTR_COLD void Vtoplevel___024root___stl_sequent__TOP__0(Vtoplevel___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel___024root___stl_sequent__TOP__0\n"); );
    Vtoplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.sdram_cke_pad_o = (1U & ((IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__command) 
                                       >> 7U));
    vlSelfRef.sdram_cs_n_pad_o = (1U & ((IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__command) 
                                        >> 6U));
    vlSelfRef.sdram_ras_pad_o = (1U & ((IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__command) 
                                       >> 5U));
    vlSelfRef.sdram_cas_pad_o = (1U & ((IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__command) 
                                       >> 4U));
    vlSelfRef.sdram_we_pad_o = (1U & ((IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__command) 
                                      >> 3U));
    vlSelfRef.sdram_dqm_pad_o = ((2U & ((~ ((IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state) 
                                            >> 4U)) 
                                        << 1U)) | (1U 
                                                   & (~ 
                                                      ((IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state) 
                                                       >> 4U))));
    vlSelfRef.sdram_clk_pad_o = vlSelfRef.sys_clk_pad_i;
    vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state_cnt_nxt = 0U;
    if ((0U != (IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state))) {
        if ((0U == (IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state_cnt))) {
            if ((0x10U & (IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state))) {
                if ((8U & (IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state))) {
                    if ((1U & (~ ((IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state) 
                                  >> 2U)))) {
                        if ((2U & (IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state))) {
                            if ((1U & (~ (IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state)))) {
                                vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state_cnt_nxt = 1U;
                            }
                        } else if ((1U & (~ (IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state)))) {
                            vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state_cnt_nxt = 1U;
                        }
                    }
                } else if ((1U & (~ ((IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state) 
                                     >> 2U)))) {
                    if ((2U & (IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state))) {
                        if ((1U & (~ (IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state)))) {
                            vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state_cnt_nxt = 1U;
                        }
                    } else if ((1U & (~ (IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state)))) {
                        vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state_cnt_nxt = 1U;
                    }
                }
            } else if ((8U & (IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state))) {
                if ((4U & (IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state))) {
                    if ((2U & (IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state))) {
                        if ((1U & (~ (IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state)))) {
                            vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state_cnt_nxt = 1U;
                        }
                    } else if ((1U & (~ (IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state)))) {
                        vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state_cnt_nxt = 7U;
                    }
                } else if ((2U & (IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state))) {
                    if ((1U & (~ (IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state)))) {
                        vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state_cnt_nxt = 7U;
                    }
                }
            } else if ((1U & (~ ((IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state) 
                                 >> 2U)))) {
                if ((2U & (IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state))) {
                    if ((1U & (IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state))) {
                        vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state_cnt_nxt = 7U;
                    }
                }
            }
        }
    }
    vlSelfRef.sdram_dq_pad_io = (((0x1aU == (IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state))
                                   ? 0xffffU : 0U) 
                                 & (((0x1aU == (IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state))
                                      ? 0xffffU : 0U) 
                                    & (((0x1aU == (IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state))
                                         ? (IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__wr_data_r)
                                         : 0U) & ((0x1aU 
                                                   == (IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state))
                                                   ? 0xffffU
                                                   : 0U))));
    vlSelfRef.gpio0_io = (0xffU & ((0x80000U & vlSelfRef.toplevel__DOT__dnano_interfacei__DOT__led_cnt)
                                    ? ((IData)(vlSelfRef.toplevel__DOT__dnano_interfacei__DOT__rd_data_r) 
                                       >> 8U) : (IData)(vlSelfRef.toplevel__DOT__dnano_interfacei__DOT__rd_data_r)));
    vlSelfRef.toplevel__DOT__wr_enable = ((~ (0U != vlSelfRef.toplevel__DOT__dnano_interfacei__DOT__double_clicki__DOT__dbl_click_cnt)) 
                                          & (1U == (IData)(vlSelfRef.toplevel__DOT__dnano_interfacei__DOT__double_clicki__DOT__click_cnt)));
    vlSelfRef.toplevel__DOT__rd_enable = ((~ (0U != vlSelfRef.toplevel__DOT__dnano_interfacei__DOT__double_clicki__DOT__dbl_click_cnt)) 
                                          & (1U != (IData)(vlSelfRef.toplevel__DOT__dnano_interfacei__DOT__double_clicki__DOT__click_cnt)));
    vlSelfRef.toplevel__DOT__dnano_interfacei__DOT__double_clicki__DOT__btn_down 
        = ((~ (IData)(vlSelfRef.toplevel__DOT__dnano_interfacei__DOT__double_clicki__DOT__btn_last)) 
           & (IData)(vlSelfRef.toplevel__DOT__dnano_interfacei__DOT__double_clicki__DOT__btn_now));
    vlSelfRef.toplevel__DOT__dnano_interfacei__DOT__dbl_clck_rst_n 
        = ((~ ((IData)(vlSelfRef.toplevel__DOT__rdaddr_fifoi__DOT__wr_fifo_cnt) 
               | (IData)(vlSelfRef.toplevel__DOT__wr_fifoi__DOT__wr_fifo_cnt))) 
           & (IData)(vlSelfRef.rst_n_pad_i));
    vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__command_nxt = 0xb8U;
    if ((0U == (IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state))) {
        if ((0x207U <= (IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__refresh_cnt))) {
            vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__next = 1U;
            vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__command_nxt = 0x91U;
        } else if (vlSelfRef.toplevel__DOT__rdaddr_fifoi__DOT__rd_fifo_cnt) {
            vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__next = 0x10U;
            vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__command_nxt = 0x98U;
        } else if (vlSelfRef.toplevel__DOT__wr_fifoi__DOT__rd_fifo_cnt) {
            vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__next = 0x18U;
            vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__command_nxt = 0x98U;
        } else {
            vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__next = 0U;
        }
    } else if ((0U == (IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state_cnt))) {
        if ((0x10U & (IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state))) {
            if ((8U & (IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state))) {
                vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__next 
                    = ((4U & (IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state))
                        ? 0U : ((2U & (IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state))
                                 ? ((1U & (IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state))
                                     ? 0U : 0x1bU) : 
                                ((1U & (IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state))
                                  ? 0x1aU : 0x19U)));
                if ((1U & (~ ((IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state) 
                              >> 2U)))) {
                    if ((1U & (~ ((IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state) 
                                  >> 1U)))) {
                        if ((1U & (IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state))) {
                            vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__command_nxt = 0xa1U;
                        }
                    }
                }
            } else {
                vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__next 
                    = ((4U & (IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state))
                        ? 0U : ((2U & (IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state))
                                 ? ((1U & (IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state))
                                     ? 0x14U : 0x13U)
                                 : ((1U & (IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state))
                                     ? 0x12U : 0x11U)));
                if ((1U & (~ ((IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state) 
                              >> 2U)))) {
                    if ((1U & (~ ((IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state) 
                                  >> 1U)))) {
                        if ((1U & (IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state))) {
                            vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__command_nxt = 0xa9U;
                        }
                    }
                }
            }
        } else if ((8U & (IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state))) {
            if ((4U & (IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state))) {
                vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__next 
                    = ((2U & (IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state))
                        ? ((1U & (IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state))
                            ? 0U : 0xfU) : ((1U & (IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state))
                                             ? 0xeU
                                             : 0xdU));
                if ((1U & (~ ((IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state) 
                              >> 1U)))) {
                    if ((1U & (IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state))) {
                        vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__command_nxt = 0x80U;
                    }
                }
            } else if ((2U & (IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state))) {
                if ((1U & (IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state))) {
                    vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__next = 0xcU;
                    vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__command_nxt = 0x88U;
                } else {
                    vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__next = 0xbU;
                }
            } else {
                vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__next 
                    = ((1U & (IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state))
                        ? 5U : 9U);
                if ((1U & (~ (IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state)))) {
                    vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__command_nxt = 0x91U;
                }
            }
        } else if ((4U & (IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state))) {
            vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__next 
                = ((2U & (IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state))
                    ? 0U : ((1U & (IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state))
                             ? 0xaU : 0U));
            if ((1U & (~ ((IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state) 
                          >> 1U)))) {
                if ((1U & (IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state))) {
                    vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__command_nxt = 0x88U;
                }
            }
        } else if ((2U & (IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state))) {
            vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__next 
                = ((1U & (IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state))
                    ? 4U : 3U);
            if ((1U & (~ (IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state)))) {
                vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__command_nxt = 0x88U;
            }
        } else {
            vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__next 
                = ((1U & (IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state))
                    ? 2U : 0U);
        }
    } else {
        vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__next 
            = vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state;
        vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__command_nxt 
            = vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__command;
    }
    vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__bank_addr_r = 0U;
    vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__addr_r = 0U;
    if (((0x10U == (IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state)) 
         | (0x18U == (IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state)))) {
        vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__bank_addr_r 
            = (3U & (vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__haddr_r 
                     >> 0x16U));
        vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__addr_r 
            = (0x1fffU & (vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__haddr_r 
                          >> 9U));
    } else if (((0x12U == (IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state)) 
                | (0x1aU == (IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state)))) {
        vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__bank_addr_r 
            = (3U & (vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__haddr_r 
                     >> 0x16U));
        vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__addr_r 
            = (0x400U | (0x1ffU & vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__haddr_r));
    } else if ((0xeU == (IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state))) {
        vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__addr_r = 0x230U;
    }
    vlSelfRef.sdram_ba_pad_o = (3U & ((0x10U & (IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state))
                                       ? (IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__bank_addr_r)
                                       : ((IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__command) 
                                          >> 1U)));
    vlSelfRef.sdram_a_pad_o = ((IData)((((IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state) 
                                         >> 4U) | (0xeU 
                                                   == (IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state))))
                                ? (IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__addr_r)
                                : (0x400U & ((IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__command) 
                                             << 0xaU)));
}

VL_ATTR_COLD void Vtoplevel___024root___eval_triggers__stl(Vtoplevel___024root* vlSelf);

VL_ATTR_COLD bool Vtoplevel___024root___eval_phase__stl(Vtoplevel___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel___024root___eval_phase__stl\n"); );
    Vtoplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtoplevel___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vtoplevel___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtoplevel___024root___dump_triggers__ico(Vtoplevel___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel___024root___dump_triggers__ico\n"); );
    Vtoplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VicoTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtoplevel___024root___dump_triggers__act(Vtoplevel___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel___024root___dump_triggers__act\n"); );
    Vtoplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge sys_clk_pad_i)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge toplevel.clk1m)\n");
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @(negedge toplevel.clk1m)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtoplevel___024root___dump_triggers__nba(Vtoplevel___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel___024root___dump_triggers__nba\n"); );
    Vtoplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge sys_clk_pad_i)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge toplevel.clk1m)\n");
    }
    if ((4ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @(negedge toplevel.clk1m)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtoplevel___024root____Vm_traceActivitySetAll(Vtoplevel___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel___024root____Vm_traceActivitySetAll\n"); );
    Vtoplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[0U] = 1U;
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    vlSelfRef.__Vm_traceActivity[4U] = 1U;
    vlSelfRef.__Vm_traceActivity[5U] = 1U;
}

VL_ATTR_COLD void Vtoplevel___024root___ctor_var_reset(Vtoplevel___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel___024root___ctor_var_reset\n"); );
    Vtoplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->sys_clk_pad_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8106737703199408211ull);
    vlSelf->rst_n_pad_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14737086024603330519ull);
    vlSelf->btn_n_pad_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17348895393869609366ull);
    vlSelf->sdram_ba_pad_o = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 10771783769588372747ull);
    vlSelf->sdram_a_pad_o = VL_SCOPED_RAND_RESET_I(13, __VscopeHash, 7168165629281663340ull);
    vlSelf->sdram_cs_n_pad_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8646616519071670128ull);
    vlSelf->sdram_ras_pad_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 850426670792373416ull);
    vlSelf->sdram_cas_pad_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4600898215630378219ull);
    vlSelf->sdram_we_pad_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1829201606401673355ull);
    vlSelf->sdram_dq_pad_io = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 7180706256454863611ull);
    vlSelf->sdram_dqm_pad_o = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 13487024162881110762ull);
    vlSelf->sdram_cke_pad_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7773418570532363604ull);
    vlSelf->sdram_clk_pad_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11603369615207230519ull);
    vlSelf->gpio0_io = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 8266226482823357641ull);
    vlSelf->gpio1_i = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 16774529281344616792ull);
    vlSelf->toplevel__DOT__clk1m = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13558657496851011506ull);
    vlSelf->toplevel__DOT__wr_enable = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8346715309659426670ull);
    vlSelf->toplevel__DOT__wro_fifo = VL_SCOPED_RAND_RESET_Q(40, __VscopeHash, 2387206063256818589ull);
    vlSelf->toplevel__DOT__ctrl_busy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17741511519383444521ull);
    vlSelf->toplevel__DOT__rd_enable = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4682094136786875071ull);
    vlSelf->toplevel__DOT__rdao_fifo = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 6269103448234563363ull);
    vlSelf->toplevel__DOT__rddata_fifo = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 9791576780561005037ull);
    vlSelf->toplevel__DOT__pll_1mi__DOT__cnt = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3459101736114201245ull);
    vlSelf->toplevel__DOT__wr_fifoi__DOT__wr_data_r = VL_SCOPED_RAND_RESET_Q(40, __VscopeHash, 9707746637653240689ull);
    vlSelf->toplevel__DOT__wr_fifoi__DOT__wr_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 157857639397590272ull);
    vlSelf->toplevel__DOT__wr_fifoi__DOT__wr_syn1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12117441670001003782ull);
    vlSelf->toplevel__DOT__wr_fifoi__DOT__wr_syn2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1319452545496308885ull);
    vlSelf->toplevel__DOT__wr_fifoi__DOT__wr_ack1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14547873318475334099ull);
    vlSelf->toplevel__DOT__wr_fifoi__DOT__wr_ack2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 946610810540593634ull);
    vlSelf->toplevel__DOT__wr_fifoi__DOT__rd_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5676039198391063441ull);
    vlSelf->toplevel__DOT__wr_fifoi__DOT__rd_syn1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8160179226962857316ull);
    vlSelf->toplevel__DOT__wr_fifoi__DOT__rd_syn2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7145375728712185380ull);
    vlSelf->toplevel__DOT__wr_fifoi__DOT__rd_ack1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1877251936983538403ull);
    vlSelf->toplevel__DOT__wr_fifoi__DOT__rd_ack2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12819399971050076616ull);
    vlSelf->toplevel__DOT__wr_fifoi__DOT__wr_fifo_cnt = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18199646458586584787ull);
    vlSelf->toplevel__DOT__wr_fifoi__DOT__rd_fifo_cnt = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13168116304774532746ull);
    vlSelf->toplevel__DOT__rdaddr_fifoi__DOT__wr_data_r = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 11594262104804772656ull);
    vlSelf->toplevel__DOT__rdaddr_fifoi__DOT__wr_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4705188320031699180ull);
    vlSelf->toplevel__DOT__rdaddr_fifoi__DOT__wr_syn1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17276839353801429676ull);
    vlSelf->toplevel__DOT__rdaddr_fifoi__DOT__wr_syn2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5030809258575317269ull);
    vlSelf->toplevel__DOT__rdaddr_fifoi__DOT__wr_ack1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9640586667422728123ull);
    vlSelf->toplevel__DOT__rdaddr_fifoi__DOT__wr_ack2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17357508044029027423ull);
    vlSelf->toplevel__DOT__rdaddr_fifoi__DOT__rd_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16505064838850366439ull);
    vlSelf->toplevel__DOT__rdaddr_fifoi__DOT__rd_syn1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8531737886653846290ull);
    vlSelf->toplevel__DOT__rdaddr_fifoi__DOT__rd_syn2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2081144464551710719ull);
    vlSelf->toplevel__DOT__rdaddr_fifoi__DOT__rd_ack1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11346398867017111952ull);
    vlSelf->toplevel__DOT__rdaddr_fifoi__DOT__rd_ack2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5241602844151726050ull);
    vlSelf->toplevel__DOT__rdaddr_fifoi__DOT__wr_fifo_cnt = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7311302170355759574ull);
    vlSelf->toplevel__DOT__rdaddr_fifoi__DOT__rd_fifo_cnt = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2760917355532384211ull);
    vlSelf->toplevel__DOT__rddata_fifoi__DOT__wr_data_r = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 9163274661782158993ull);
    vlSelf->toplevel__DOT__rddata_fifoi__DOT__wr_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3356199725556530691ull);
    vlSelf->toplevel__DOT__rddata_fifoi__DOT__wr_syn1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7410023631350786542ull);
    vlSelf->toplevel__DOT__rddata_fifoi__DOT__wr_syn2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 961643810586127129ull);
    vlSelf->toplevel__DOT__rddata_fifoi__DOT__wr_ack1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2732341859352809112ull);
    vlSelf->toplevel__DOT__rddata_fifoi__DOT__wr_ack2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11608175145892280067ull);
    vlSelf->toplevel__DOT__rddata_fifoi__DOT__rd_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11326296710570372032ull);
    vlSelf->toplevel__DOT__rddata_fifoi__DOT__rd_syn1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3539767733156516284ull);
    vlSelf->toplevel__DOT__rddata_fifoi__DOT__rd_syn2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16431126665435632812ull);
    vlSelf->toplevel__DOT__rddata_fifoi__DOT__rd_ack1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4488281149364194903ull);
    vlSelf->toplevel__DOT__rddata_fifoi__DOT__rd_ack2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15426459178037126483ull);
    vlSelf->toplevel__DOT__rddata_fifoi__DOT__wr_fifo_cnt = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1707763808884151857ull);
    vlSelf->toplevel__DOT__rddata_fifoi__DOT__rd_fifo_cnt = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6025852783188951417ull);
    vlSelf->toplevel__DOT__sdram_controlleri__DOT__haddr_r = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 6762050835124749619ull);
    vlSelf->toplevel__DOT__sdram_controlleri__DOT__wr_data_r = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 15294998784572662105ull);
    vlSelf->toplevel__DOT__sdram_controlleri__DOT__rd_data_r = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 8014658133949427548ull);
    vlSelf->toplevel__DOT__sdram_controlleri__DOT__addr_r = VL_SCOPED_RAND_RESET_I(13, __VscopeHash, 7441617774741445178ull);
    vlSelf->toplevel__DOT__sdram_controlleri__DOT__bank_addr_r = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 11292981551269833958ull);
    vlSelf->toplevel__DOT__sdram_controlleri__DOT__rd_ready_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7192076075169478710ull);
    vlSelf->toplevel__DOT__sdram_controlleri__DOT__state_cnt = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 3591632588851284455ull);
    vlSelf->toplevel__DOT__sdram_controlleri__DOT__refresh_cnt = VL_SCOPED_RAND_RESET_I(10, __VscopeHash, 10700600976429513337ull);
    vlSelf->toplevel__DOT__sdram_controlleri__DOT__command = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 786597708991088465ull);
    vlSelf->toplevel__DOT__sdram_controlleri__DOT__state = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 8901910403711656559ull);
    vlSelf->toplevel__DOT__sdram_controlleri__DOT__command_nxt = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 6914713166983503371ull);
    vlSelf->toplevel__DOT__sdram_controlleri__DOT__state_cnt_nxt = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 17938411744214174310ull);
    vlSelf->toplevel__DOT__sdram_controlleri__DOT__next = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 2540745880762286743ull);
    vlSelf->toplevel__DOT__dnano_interfacei__DOT__rd_data_r = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 10142087954359930036ull);
    vlSelf->toplevel__DOT__dnano_interfacei__DOT__led_cnt = VL_SCOPED_RAND_RESET_I(20, __VscopeHash, 14619327624335965150ull);
    vlSelf->toplevel__DOT__dnano_interfacei__DOT__rd_ack_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 652468880200769907ull);
    vlSelf->toplevel__DOT__dnano_interfacei__DOT__dbl_clck_rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7173853340752006427ull);
    vlSelf->toplevel__DOT__dnano_interfacei__DOT__double_clicki__DOT__btn_now = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1182984963315426611ull);
    vlSelf->toplevel__DOT__dnano_interfacei__DOT__double_clicki__DOT__btn_last = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17457044765073504650ull);
    vlSelf->toplevel__DOT__dnano_interfacei__DOT__double_clicki__DOT__collect = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 530781224624743811ull);
    vlSelf->toplevel__DOT__dnano_interfacei__DOT__double_clicki__DOT__click_cnt = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 14671932355058186816ull);
    vlSelf->toplevel__DOT__dnano_interfacei__DOT__double_clicki__DOT__dbl_click_cnt = VL_SCOPED_RAND_RESET_I(19, __VscopeHash, 16235079922687483394ull);
    vlSelf->toplevel__DOT__dnano_interfacei__DOT__double_clicki__DOT__btn_down = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2566370833668440571ull);
    vlSelf->__Vdly__toplevel__DOT__wr_fifoi__DOT__wr_syn2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7747128212350477677ull);
    vlSelf->__Vdly__toplevel__DOT__rdaddr_fifoi__DOT__wr_syn2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18442136698222142773ull);
    vlSelf->__Vdly__toplevel__DOT__rddata_fifoi__DOT__rd_syn2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1911158664541042990ull);
    vlSelf->__Vdly__toplevel__DOT__wr_fifoi__DOT__rd_syn2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15994125328884388909ull);
    vlSelf->__Vdly__toplevel__DOT__rdaddr_fifoi__DOT__rd_syn2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12374185213684578121ull);
    vlSelf->__Vdly__toplevel__DOT__rddata_fifoi__DOT__wr_syn2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17470567666920460522ull);
    vlSelf->__Vtrigprevexpr___TOP__sys_clk_pad_i__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9532158921344082187ull);
    vlSelf->__Vtrigprevexpr___TOP__toplevel__DOT__clk1m__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4519452121985257241ull);
    for (int __Vi0 = 0; __Vi0 < 6; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
