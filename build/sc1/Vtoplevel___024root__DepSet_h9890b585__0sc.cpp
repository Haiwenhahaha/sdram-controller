// Verilated -*- SystemC -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtoplevel.h for the primary calling header

#include "Vtoplevel__pch.h"
#include "Vtoplevel___024root.h"

void Vtoplevel___024root___ico_sequent__TOP__0(Vtoplevel___024root* vlSelf);

void Vtoplevel___024root___eval_ico(Vtoplevel___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel___024root___eval_ico\n"); );
    Vtoplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        Vtoplevel___024root___ico_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
    }
}

VL_INLINE_OPT void Vtoplevel___024root___ico_sequent__TOP__0(Vtoplevel___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel___024root___ico_sequent__TOP__0\n"); );
    Vtoplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_ASSIGN_ISI(4, vlSelfRef.__Vcellinp__toplevel__gpio1_i, vlSelfRef.gpio1_i);
    VL_ASSIGN_ISI(8, vlSelfRef.__Vcellinpt__toplevel__gpio0_io, vlSelfRef.gpio0_io);
    VL_ASSIGN_ISI(16, vlSelfRef.__Vcellinpt__toplevel__sdram_dq_pad_io, vlSelfRef.sdram_dq_pad_io);
    VL_ASSIGN_ISI(1, vlSelfRef.__Vcellinp__toplevel__btn_n_pad_i, vlSelfRef.btn_n_pad_i);
    VL_ASSIGN_ISI(1, vlSelfRef.__Vcellinp__toplevel__sys_clk_pad_i, vlSelfRef.sys_clk_pad_i);
    VL_ASSIGN_ISI(1, vlSelfRef.__Vcellinp__toplevel__rst_n_pad_i, vlSelfRef.rst_n_pad_i);
    VL_ASSIGN_SII(1, vlSelfRef.sdram_clk_pad_o, vlSelfRef.__Vcellinp__toplevel__sys_clk_pad_i);
    vlSelfRef.toplevel__DOT__dnano_interfacei__DOT__dbl_clck_rst_n 
        = ((~ ((IData)(vlSelfRef.toplevel__DOT__rdaddr_fifoi__DOT__wr_fifo_cnt) 
               | (IData)(vlSelfRef.toplevel__DOT__wr_fifoi__DOT__wr_fifo_cnt))) 
           & (IData)(vlSelfRef.__Vcellinp__toplevel__rst_n_pad_i));
}

void Vtoplevel___024root___eval_triggers__ico(Vtoplevel___024root* vlSelf);

bool Vtoplevel___024root___eval_phase__ico(Vtoplevel___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel___024root___eval_phase__ico\n"); );
    Vtoplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vtoplevel___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelfRef.__VicoTriggered.any();
    if (__VicoExecute) {
        Vtoplevel___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vtoplevel___024root___eval_act(Vtoplevel___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel___024root___eval_act\n"); );
    Vtoplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vtoplevel___024root___nba_sequent__TOP__0(Vtoplevel___024root* vlSelf);
void Vtoplevel___024root___nba_sequent__TOP__1(Vtoplevel___024root* vlSelf);
void Vtoplevel___024root___nba_sequent__TOP__2(Vtoplevel___024root* vlSelf);
void Vtoplevel___024root___nba_sequent__TOP__3(Vtoplevel___024root* vlSelf);
void Vtoplevel___024root___nba_sequent__TOP__4(Vtoplevel___024root* vlSelf);

void Vtoplevel___024root___eval_nba(Vtoplevel___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel___024root___eval_nba\n"); );
    Vtoplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtoplevel___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtoplevel___024root___nba_sequent__TOP__1(vlSelf);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
    }
    if ((4ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtoplevel___024root___nba_sequent__TOP__2(vlSelf);
        vlSelfRef.__Vm_traceActivity[4U] = 1U;
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtoplevel___024root___nba_sequent__TOP__3(vlSelf);
        vlSelfRef.__Vm_traceActivity[5U] = 1U;
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtoplevel___024root___nba_sequent__TOP__4(vlSelf);
        vlSelfRef.__Vm_traceActivity[6U] = 1U;
    }
}

VL_INLINE_OPT void Vtoplevel___024root___nba_sequent__TOP__0(Vtoplevel___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel___024root___nba_sequent__TOP__0\n"); );
    Vtoplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __Vdly__toplevel__DOT__pll_1mi__DOT__cnt;
    __Vdly__toplevel__DOT__pll_1mi__DOT__cnt = 0;
    // Body
    __Vdly__toplevel__DOT__pll_1mi__DOT__cnt = vlSelfRef.toplevel__DOT__pll_1mi__DOT__cnt;
    vlSelfRef.__Vdly__toplevel__DOT__rddata_fifoi__DOT__rd_syn2 
        = vlSelfRef.toplevel__DOT__rddata_fifoi__DOT__rd_syn2;
    vlSelfRef.__Vdly__toplevel__DOT__wr_fifoi__DOT__wr_syn2 
        = vlSelfRef.toplevel__DOT__wr_fifoi__DOT__wr_syn2;
    vlSelfRef.__Vdly__toplevel__DOT__rdaddr_fifoi__DOT__wr_syn2 
        = vlSelfRef.toplevel__DOT__rdaddr_fifoi__DOT__wr_syn2;
    if ((0x18U == vlSelfRef.toplevel__DOT__pll_1mi__DOT__cnt)) {
        vlSelfRef.toplevel__DOT__clk1m = (1U & (~ (IData)(vlSelfRef.toplevel__DOT__clk1m)));
        __Vdly__toplevel__DOT__pll_1mi__DOT__cnt = 0U;
    } else {
        __Vdly__toplevel__DOT__pll_1mi__DOT__cnt = 
            ((IData)(1U) + vlSelfRef.toplevel__DOT__pll_1mi__DOT__cnt);
    }
    if (vlSelfRef.__Vcellinp__toplevel__rst_n_pad_i) {
        vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state_cnt 
            = (0xfU & ((0U == (IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state_cnt))
                        ? (IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state_cnt_nxt)
                        : ((IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state_cnt) 
                           - (IData)(1U))));
        vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__refresh_cnt 
            = ((4U == (IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state))
                ? 0U : (0x3ffU & ((IData)(1U) + (IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__refresh_cnt))));
        vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__command 
            = vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__command_nxt;
        if (vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__rd_ready_r) {
            vlSelfRef.toplevel__DOT__rddata_fifoi__DOT__wr_fifo_cnt = 1U;
        }
        if ((1U == (((IData)(vlSelfRef.toplevel__DOT__rddata_fifoi__DOT__rd_syn2) 
                     << 1U) | (IData)(vlSelfRef.toplevel__DOT__rddata_fifoi__DOT__rd_syn1)))) {
            vlSelfRef.toplevel__DOT__rddata_fifoi__DOT__wr_fifo_cnt = 0U;
        }
        vlSelfRef.__Vdly__toplevel__DOT__rddata_fifoi__DOT__rd_syn2 
            = vlSelfRef.toplevel__DOT__rddata_fifoi__DOT__rd_syn1;
        if (vlSelfRef.toplevel__DOT__wr_fifoi__DOT__rd_fifo_cnt) {
            vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__wr_data_r 
                = (0xffffU & (IData)(vlSelfRef.toplevel__DOT__wro_fifo));
        }
        if (vlSelfRef.toplevel__DOT__rdaddr_fifoi__DOT__rd_fifo_cnt) {
            vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__haddr_r 
                = vlSelfRef.toplevel__DOT__rdao_fifo;
        } else if (vlSelfRef.toplevel__DOT__wr_fifoi__DOT__rd_fifo_cnt) {
            vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__haddr_r 
                = (0xffffffU & (IData)((vlSelfRef.toplevel__DOT__wro_fifo 
                                        >> 0x10U)));
        }
        if (vlSelfRef.toplevel__DOT__ctrl_busy) {
            vlSelfRef.toplevel__DOT__rdaddr_fifoi__DOT__rd_fifo_cnt = 0U;
            vlSelfRef.toplevel__DOT__wr_fifoi__DOT__rd_fifo_cnt = 0U;
        }
        if ((1U == (((IData)(vlSelfRef.toplevel__DOT__rdaddr_fifoi__DOT__wr_syn2) 
                     << 1U) | (IData)(vlSelfRef.toplevel__DOT__rdaddr_fifoi__DOT__wr_syn1)))) {
            vlSelfRef.toplevel__DOT__rdaddr_fifoi__DOT__rd_fifo_cnt = 1U;
        }
        if (vlSelfRef.toplevel__DOT__rdaddr_fifoi__DOT__wr_syn2) {
            vlSelfRef.toplevel__DOT__rdao_fifo = vlSelfRef.toplevel__DOT__rdaddr_fifoi__DOT__wr_data_r;
        }
        vlSelfRef.__Vdly__toplevel__DOT__rdaddr_fifoi__DOT__wr_syn2 
            = vlSelfRef.toplevel__DOT__rdaddr_fifoi__DOT__wr_syn1;
        if ((1U == (((IData)(vlSelfRef.toplevel__DOT__wr_fifoi__DOT__wr_syn2) 
                     << 1U) | (IData)(vlSelfRef.toplevel__DOT__wr_fifoi__DOT__wr_syn1)))) {
            vlSelfRef.toplevel__DOT__wr_fifoi__DOT__rd_fifo_cnt = 1U;
        }
        if (vlSelfRef.toplevel__DOT__wr_fifoi__DOT__wr_syn2) {
            vlSelfRef.toplevel__DOT__wro_fifo = vlSelfRef.toplevel__DOT__wr_fifoi__DOT__wr_data_r;
        }
        vlSelfRef.__Vdly__toplevel__DOT__wr_fifoi__DOT__wr_syn2 
            = vlSelfRef.toplevel__DOT__wr_fifoi__DOT__wr_syn1;
    } else {
        vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state_cnt = 0xfU;
        vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__refresh_cnt = 0U;
        vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__command = 0xb8U;
        vlSelfRef.toplevel__DOT__rddata_fifoi__DOT__wr_fifo_cnt = 0U;
        vlSelfRef.__Vdly__toplevel__DOT__rddata_fifoi__DOT__rd_syn2 = 0U;
        vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__wr_data_r = 0U;
        vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__haddr_r = 0U;
        vlSelfRef.toplevel__DOT__rdaddr_fifoi__DOT__rd_fifo_cnt = 0U;
        vlSelfRef.__Vdly__toplevel__DOT__rdaddr_fifoi__DOT__wr_syn2 = 0U;
        vlSelfRef.toplevel__DOT__wr_fifoi__DOT__rd_fifo_cnt = 0U;
        vlSelfRef.__Vdly__toplevel__DOT__wr_fifoi__DOT__wr_syn2 = 0U;
    }
    vlSelfRef.toplevel__DOT__pll_1mi__DOT__cnt = __Vdly__toplevel__DOT__pll_1mi__DOT__cnt;
    VL_ASSIGN_SII(1, vlSelfRef.sdram_cke_pad_o, (1U 
                                                 & ((IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__command) 
                                                    >> 7U)));
    VL_ASSIGN_SII(1, vlSelfRef.sdram_we_pad_o, (1U 
                                                & ((IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__command) 
                                                   >> 3U)));
    VL_ASSIGN_SII(1, vlSelfRef.sdram_cas_pad_o, (1U 
                                                 & ((IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__command) 
                                                    >> 4U)));
    VL_ASSIGN_SII(1, vlSelfRef.sdram_ras_pad_o, (1U 
                                                 & ((IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__command) 
                                                    >> 5U)));
    VL_ASSIGN_SII(1, vlSelfRef.sdram_cs_n_pad_o, (1U 
                                                  & ((IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__command) 
                                                     >> 6U)));
    vlSelfRef.toplevel__DOT__rddata_fifoi__DOT__rd_syn1 
        = ((IData)(vlSelfRef.__Vcellinp__toplevel__rst_n_pad_i) 
           && (IData)(vlSelfRef.toplevel__DOT__rddata_fifoi__DOT__rd_r));
    vlSelfRef.toplevel__DOT__rdaddr_fifoi__DOT__wr_syn1 
        = ((IData)(vlSelfRef.__Vcellinp__toplevel__rst_n_pad_i) 
           && (IData)(vlSelfRef.toplevel__DOT__rdaddr_fifoi__DOT__wr_r));
    vlSelfRef.toplevel__DOT__wr_fifoi__DOT__wr_syn1 
        = ((IData)(vlSelfRef.__Vcellinp__toplevel__rst_n_pad_i) 
           && (IData)(vlSelfRef.toplevel__DOT__wr_fifoi__DOT__wr_r));
}

VL_INLINE_OPT void Vtoplevel___024root___nba_sequent__TOP__1(Vtoplevel___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel___024root___nba_sequent__TOP__1\n"); );
    Vtoplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __Vdly__toplevel__DOT__rddata_fifoi__DOT__rd_fifo_cnt;
    __Vdly__toplevel__DOT__rddata_fifoi__DOT__rd_fifo_cnt = 0;
    // Body
    vlSelfRef.__Vdly__toplevel__DOT__wr_fifoi__DOT__rd_syn2 
        = vlSelfRef.toplevel__DOT__wr_fifoi__DOT__rd_syn2;
    vlSelfRef.__Vdly__toplevel__DOT__rdaddr_fifoi__DOT__rd_syn2 
        = vlSelfRef.toplevel__DOT__rdaddr_fifoi__DOT__rd_syn2;
    __Vdly__toplevel__DOT__rddata_fifoi__DOT__rd_fifo_cnt 
        = vlSelfRef.toplevel__DOT__rddata_fifoi__DOT__rd_fifo_cnt;
    vlSelfRef.__Vdly__toplevel__DOT__rddata_fifoi__DOT__wr_syn2 
        = vlSelfRef.toplevel__DOT__rddata_fifoi__DOT__wr_syn2;
    if (vlSelfRef.toplevel__DOT__dnano_interfacei__DOT__dbl_clck_rst_n) {
        vlSelfRef.toplevel__DOT__dnano_interfacei__DOT__double_clicki__DOT__click_cnt 
            = (7U & ((IData)(vlSelfRef.toplevel__DOT__dnano_interfacei__DOT__double_clicki__DOT__btn_down)
                      ? ((IData)(1U) + (IData)(vlSelfRef.toplevel__DOT__dnano_interfacei__DOT__double_clicki__DOT__click_cnt))
                      : (IData)(vlSelfRef.toplevel__DOT__dnano_interfacei__DOT__double_clicki__DOT__click_cnt)));
        vlSelfRef.toplevel__DOT__dnano_interfacei__DOT__double_clicki__DOT__dbl_click_cnt 
            = (0x7ffffU & (((IData)(vlSelfRef.toplevel__DOT__dnano_interfacei__DOT__double_clicki__DOT__collect) 
                            & (0U != vlSelfRef.toplevel__DOT__dnano_interfacei__DOT__double_clicki__DOT__dbl_click_cnt))
                            ? (vlSelfRef.toplevel__DOT__dnano_interfacei__DOT__double_clicki__DOT__dbl_click_cnt 
                               - (IData)(1U)) : vlSelfRef.toplevel__DOT__dnano_interfacei__DOT__double_clicki__DOT__dbl_click_cnt));
        vlSelfRef.toplevel__DOT__dnano_interfacei__DOT__double_clicki__DOT__collect 
            = ((IData)(vlSelfRef.toplevel__DOT__dnano_interfacei__DOT__double_clicki__DOT__btn_down) 
               || (IData)(vlSelfRef.toplevel__DOT__dnano_interfacei__DOT__double_clicki__DOT__collect));
    } else {
        vlSelfRef.toplevel__DOT__dnano_interfacei__DOT__double_clicki__DOT__click_cnt = 0U;
        vlSelfRef.toplevel__DOT__dnano_interfacei__DOT__double_clicki__DOT__dbl_click_cnt = 0x7ffffU;
        vlSelfRef.toplevel__DOT__dnano_interfacei__DOT__double_clicki__DOT__collect = 0U;
    }
    if (vlSelfRef.__Vcellinp__toplevel__rst_n_pad_i) {
        vlSelfRef.toplevel__DOT__dnano_interfacei__DOT__led_cnt 
            = (0xfffffU & ((IData)(1U) + vlSelfRef.toplevel__DOT__dnano_interfacei__DOT__led_cnt));
        vlSelfRef.toplevel__DOT__dnano_interfacei__DOT__rd_data_r 
            = ((IData)(vlSelfRef.toplevel__DOT__rddata_fifoi__DOT__rd_fifo_cnt)
                ? (IData)(vlSelfRef.toplevel__DOT__rddata_fifo)
                : (IData)(vlSelfRef.toplevel__DOT__dnano_interfacei__DOT__rd_data_r));
        if (vlSelfRef.toplevel__DOT__wr_enable) {
            vlSelfRef.toplevel__DOT__wr_fifoi__DOT__wr_fifo_cnt = 1U;
            vlSelfRef.toplevel__DOT__wr_fifoi__DOT__wr_data_r 
                = (((QData)((IData)((((IData)(vlSelfRef.__Vcellinp__toplevel__gpio1_i) 
                                      << 0x1cU) | (
                                                   ((IData)(vlSelfRef.__Vcellinp__toplevel__gpio1_i) 
                                                    << 0x18U) 
                                                   | (((IData)(vlSelfRef.__Vcellinp__toplevel__gpio1_i) 
                                                       << 0x14U) 
                                                      | (((IData)(vlSelfRef.__Vcellinp__toplevel__gpio1_i) 
                                                          << 0x10U) 
                                                         | (((IData)(vlSelfRef.__Vcellinp__toplevel__gpio1_i) 
                                                             << 0xcU) 
                                                            | (((IData)(vlSelfRef.__Vcellinp__toplevel__gpio1_i) 
                                                                << 8U) 
                                                               | (((IData)(vlSelfRef.__Vcellinp__toplevel__gpio1_i) 
                                                                   << 4U) 
                                                                  | (IData)(vlSelfRef.__Vcellinp__toplevel__gpio1_i)))))))))) 
                    << 8U) | (QData)((IData)((0xffU 
                                              & ((0xf0U 
                                                  & ((~ (IData)(vlSelfRef.__Vcellinp__toplevel__gpio1_i)) 
                                                     << 4U)) 
                                                 | (0xfU 
                                                    & (~ (IData)(vlSelfRef.__Vcellinp__toplevel__gpio1_i))))))));
            vlSelfRef.toplevel__DOT__wr_fifoi__DOT__wr_r = 1U;
        }
        if ((1U == (((IData)(vlSelfRef.toplevel__DOT__wr_fifoi__DOT__rd_syn2) 
                     << 1U) | (IData)(vlSelfRef.toplevel__DOT__wr_fifoi__DOT__rd_syn1)))) {
            vlSelfRef.toplevel__DOT__wr_fifoi__DOT__wr_fifo_cnt = 0U;
        }
        vlSelfRef.__Vdly__toplevel__DOT__wr_fifoi__DOT__rd_syn2 
            = vlSelfRef.toplevel__DOT__wr_fifoi__DOT__rd_syn1;
        if (vlSelfRef.toplevel__DOT__rd_enable) {
            vlSelfRef.toplevel__DOT__rdaddr_fifoi__DOT__wr_fifo_cnt = 1U;
            vlSelfRef.toplevel__DOT__rdaddr_fifoi__DOT__wr_data_r 
                = (0xffffffU & (((IData)(vlSelfRef.__Vcellinp__toplevel__gpio1_i) 
                                 << 0x14U) | (((IData)(vlSelfRef.__Vcellinp__toplevel__gpio1_i) 
                                               << 0x10U) 
                                              | (((IData)(vlSelfRef.__Vcellinp__toplevel__gpio1_i) 
                                                  << 0xcU) 
                                                 | (((IData)(vlSelfRef.__Vcellinp__toplevel__gpio1_i) 
                                                     << 8U) 
                                                    | (((IData)(vlSelfRef.__Vcellinp__toplevel__gpio1_i) 
                                                        << 4U) 
                                                       | (IData)(vlSelfRef.__Vcellinp__toplevel__gpio1_i)))))));
            vlSelfRef.toplevel__DOT__rdaddr_fifoi__DOT__wr_r = 1U;
        }
        if ((1U == (((IData)(vlSelfRef.toplevel__DOT__rdaddr_fifoi__DOT__rd_syn2) 
                     << 1U) | (IData)(vlSelfRef.toplevel__DOT__rdaddr_fifoi__DOT__rd_syn1)))) {
            vlSelfRef.toplevel__DOT__rdaddr_fifoi__DOT__wr_fifo_cnt = 0U;
        }
        vlSelfRef.__Vdly__toplevel__DOT__rdaddr_fifoi__DOT__rd_syn2 
            = vlSelfRef.toplevel__DOT__rdaddr_fifoi__DOT__rd_syn1;
        if (vlSelfRef.toplevel__DOT__dnano_interfacei__DOT__rd_ack_r) {
            vlSelfRef.toplevel__DOT__rddata_fifoi__DOT__rd_r = 1U;
            __Vdly__toplevel__DOT__rddata_fifoi__DOT__rd_fifo_cnt = 0U;
        } else if (vlSelfRef.toplevel__DOT__rddata_fifoi__DOT__rd_ack2) {
            vlSelfRef.toplevel__DOT__rddata_fifoi__DOT__rd_r = 0U;
        }
        if (vlSelfRef.toplevel__DOT__rdaddr_fifoi__DOT__wr_ack2) {
            vlSelfRef.toplevel__DOT__rdaddr_fifoi__DOT__wr_r = 0U;
        }
        if (vlSelfRef.toplevel__DOT__wr_fifoi__DOT__wr_ack2) {
            vlSelfRef.toplevel__DOT__wr_fifoi__DOT__wr_r = 0U;
        }
        if ((1U == (((IData)(vlSelfRef.toplevel__DOT__rddata_fifoi__DOT__wr_syn2) 
                     << 1U) | (IData)(vlSelfRef.toplevel__DOT__rddata_fifoi__DOT__wr_syn1)))) {
            __Vdly__toplevel__DOT__rddata_fifoi__DOT__rd_fifo_cnt = 1U;
        }
        if (vlSelfRef.toplevel__DOT__rddata_fifoi__DOT__wr_syn2) {
            vlSelfRef.toplevel__DOT__rddata_fifo = vlSelfRef.toplevel__DOT__rddata_fifoi__DOT__wr_data_r;
        }
        vlSelfRef.__Vdly__toplevel__DOT__rddata_fifoi__DOT__wr_syn2 
            = vlSelfRef.toplevel__DOT__rddata_fifoi__DOT__wr_syn1;
    } else {
        vlSelfRef.toplevel__DOT__dnano_interfacei__DOT__led_cnt = 0U;
        vlSelfRef.toplevel__DOT__dnano_interfacei__DOT__rd_data_r = 0U;
        vlSelfRef.toplevel__DOT__wr_fifoi__DOT__wr_fifo_cnt = 0U;
        vlSelfRef.__Vdly__toplevel__DOT__wr_fifoi__DOT__rd_syn2 = 0U;
        vlSelfRef.toplevel__DOT__rdaddr_fifoi__DOT__wr_fifo_cnt = 0U;
        vlSelfRef.__Vdly__toplevel__DOT__rdaddr_fifoi__DOT__rd_syn2 = 0U;
        __Vdly__toplevel__DOT__rddata_fifoi__DOT__rd_fifo_cnt = 0U;
        vlSelfRef.__Vdly__toplevel__DOT__rddata_fifoi__DOT__wr_syn2 = 0U;
    }
    vlSelfRef.toplevel__DOT__wr_enable = ((0U == vlSelfRef.toplevel__DOT__dnano_interfacei__DOT__double_clicki__DOT__dbl_click_cnt) 
                                          & (1U == (IData)(vlSelfRef.toplevel__DOT__dnano_interfacei__DOT__double_clicki__DOT__click_cnt)));
    vlSelfRef.toplevel__DOT__rd_enable = ((0U == vlSelfRef.toplevel__DOT__dnano_interfacei__DOT__double_clicki__DOT__dbl_click_cnt) 
                                          & (1U != (IData)(vlSelfRef.toplevel__DOT__dnano_interfacei__DOT__double_clicki__DOT__click_cnt)));
    VL_ASSIGN_SII(8, vlSelfRef.gpio0_io, (0xffU & (
                                                   (0x80000U 
                                                    & vlSelfRef.toplevel__DOT__dnano_interfacei__DOT__led_cnt)
                                                    ? 
                                                   ((IData)(vlSelfRef.toplevel__DOT__dnano_interfacei__DOT__rd_data_r) 
                                                    >> 8U)
                                                    : (IData)(vlSelfRef.toplevel__DOT__dnano_interfacei__DOT__rd_data_r))));
    vlSelfRef.toplevel__DOT__wr_fifoi__DOT__rd_syn1 
        = ((IData)(vlSelfRef.__Vcellinp__toplevel__rst_n_pad_i) 
           && (IData)(vlSelfRef.toplevel__DOT__wr_fifoi__DOT__rd_r));
    vlSelfRef.toplevel__DOT__dnano_interfacei__DOT__dbl_clck_rst_n 
        = ((~ ((IData)(vlSelfRef.toplevel__DOT__rdaddr_fifoi__DOT__wr_fifo_cnt) 
               | (IData)(vlSelfRef.toplevel__DOT__wr_fifoi__DOT__wr_fifo_cnt))) 
           & (IData)(vlSelfRef.__Vcellinp__toplevel__rst_n_pad_i));
    vlSelfRef.toplevel__DOT__rdaddr_fifoi__DOT__rd_syn1 
        = ((IData)(vlSelfRef.__Vcellinp__toplevel__rst_n_pad_i) 
           && (IData)(vlSelfRef.toplevel__DOT__rdaddr_fifoi__DOT__rd_r));
    vlSelfRef.toplevel__DOT__rddata_fifoi__DOT__rd_ack2 
        = ((IData)(vlSelfRef.__Vcellinp__toplevel__rst_n_pad_i) 
           && (IData)(vlSelfRef.toplevel__DOT__rddata_fifoi__DOT__rd_ack1));
    vlSelfRef.toplevel__DOT__rdaddr_fifoi__DOT__wr_ack2 
        = ((IData)(vlSelfRef.__Vcellinp__toplevel__rst_n_pad_i) 
           && (IData)(vlSelfRef.toplevel__DOT__rdaddr_fifoi__DOT__wr_ack1));
    vlSelfRef.toplevel__DOT__wr_fifoi__DOT__wr_ack2 
        = ((IData)(vlSelfRef.__Vcellinp__toplevel__rst_n_pad_i) 
           && (IData)(vlSelfRef.toplevel__DOT__wr_fifoi__DOT__wr_ack1));
    VL_ASSIGN_ISI(8, vlSelfRef.__Vcellinpt__toplevel__gpio0_io, vlSelfRef.gpio0_io);
    vlSelfRef.toplevel__DOT__rddata_fifoi__DOT__wr_syn1 
        = ((IData)(vlSelfRef.__Vcellinp__toplevel__rst_n_pad_i) 
           && (IData)(vlSelfRef.toplevel__DOT__rddata_fifoi__DOT__wr_r));
    vlSelfRef.toplevel__DOT__dnano_interfacei__DOT__rd_ack_r 
        = ((IData)(vlSelfRef.__Vcellinp__toplevel__rst_n_pad_i) 
           && (IData)(vlSelfRef.toplevel__DOT__rddata_fifoi__DOT__rd_fifo_cnt));
    vlSelfRef.toplevel__DOT__rddata_fifoi__DOT__rd_ack1 
        = ((IData)(vlSelfRef.__Vcellinp__toplevel__rst_n_pad_i) 
           && (IData)(vlSelfRef.toplevel__DOT__rddata_fifoi__DOT__rd_syn2));
    vlSelfRef.toplevel__DOT__rdaddr_fifoi__DOT__wr_ack1 
        = ((IData)(vlSelfRef.__Vcellinp__toplevel__rst_n_pad_i) 
           && (IData)(vlSelfRef.toplevel__DOT__rdaddr_fifoi__DOT__wr_syn2));
    vlSelfRef.toplevel__DOT__wr_fifoi__DOT__wr_ack1 
        = ((IData)(vlSelfRef.__Vcellinp__toplevel__rst_n_pad_i) 
           && (IData)(vlSelfRef.toplevel__DOT__wr_fifoi__DOT__wr_syn2));
    vlSelfRef.toplevel__DOT__rddata_fifoi__DOT__rd_fifo_cnt 
        = __Vdly__toplevel__DOT__rddata_fifoi__DOT__rd_fifo_cnt;
}

VL_INLINE_OPT void Vtoplevel___024root___nba_sequent__TOP__2(Vtoplevel___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel___024root___nba_sequent__TOP__2\n"); );
    Vtoplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.toplevel__DOT__dnano_interfacei__DOT__double_clicki__DOT__btn_last 
        = ((IData)(vlSelfRef.toplevel__DOT__dnano_interfacei__DOT__dbl_clck_rst_n) 
           && (IData)(vlSelfRef.toplevel__DOT__dnano_interfacei__DOT__double_clicki__DOT__btn_now));
    vlSelfRef.toplevel__DOT__dnano_interfacei__DOT__double_clicki__DOT__btn_now 
        = ((IData)(vlSelfRef.toplevel__DOT__dnano_interfacei__DOT__dbl_clck_rst_n) 
           && (1U & (~ (IData)(vlSelfRef.__Vcellinp__toplevel__btn_n_pad_i))));
    vlSelfRef.toplevel__DOT__dnano_interfacei__DOT__double_clicki__DOT__btn_down 
        = ((~ (IData)(vlSelfRef.toplevel__DOT__dnano_interfacei__DOT__double_clicki__DOT__btn_last)) 
           & (IData)(vlSelfRef.toplevel__DOT__dnano_interfacei__DOT__double_clicki__DOT__btn_now));
}

VL_INLINE_OPT void Vtoplevel___024root___nba_sequent__TOP__3(Vtoplevel___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel___024root___nba_sequent__TOP__3\n"); );
    Vtoplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.toplevel__DOT__rddata_fifoi__DOT__rd_syn2 
        = vlSelfRef.__Vdly__toplevel__DOT__rddata_fifoi__DOT__rd_syn2;
    vlSelfRef.toplevel__DOT__rdaddr_fifoi__DOT__wr_syn2 
        = vlSelfRef.__Vdly__toplevel__DOT__rdaddr_fifoi__DOT__wr_syn2;
    vlSelfRef.toplevel__DOT__wr_fifoi__DOT__wr_syn2 
        = vlSelfRef.__Vdly__toplevel__DOT__wr_fifoi__DOT__wr_syn2;
    if (vlSelfRef.__Vcellinp__toplevel__rst_n_pad_i) {
        if (vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__rd_ready_r) {
            vlSelfRef.toplevel__DOT__rddata_fifoi__DOT__wr_data_r 
                = vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__rd_data_r;
            vlSelfRef.toplevel__DOT__rddata_fifoi__DOT__wr_r = 1U;
        }
        if (vlSelfRef.toplevel__DOT__ctrl_busy) {
            vlSelfRef.toplevel__DOT__wr_fifoi__DOT__rd_r = 1U;
            vlSelfRef.toplevel__DOT__rdaddr_fifoi__DOT__rd_r = 1U;
        } else {
            if (vlSelfRef.toplevel__DOT__wr_fifoi__DOT__rd_ack2) {
                vlSelfRef.toplevel__DOT__wr_fifoi__DOT__rd_r = 0U;
            }
            if (vlSelfRef.toplevel__DOT__rdaddr_fifoi__DOT__rd_ack2) {
                vlSelfRef.toplevel__DOT__rdaddr_fifoi__DOT__rd_r = 0U;
            }
        }
        if (vlSelfRef.toplevel__DOT__rddata_fifoi__DOT__wr_ack2) {
            vlSelfRef.toplevel__DOT__rddata_fifoi__DOT__wr_r = 0U;
        }
        if ((0x14U == (IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state))) {
            vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__rd_data_r 
                = vlSelfRef.__Vcellinpt__toplevel__sdram_dq_pad_io;
            vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__rd_ready_r = 1U;
        } else {
            vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__rd_ready_r = 0U;
        }
        vlSelfRef.toplevel__DOT__ctrl_busy = (1U & 
                                              ((IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state) 
                                               >> 4U));
        vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state 
            = vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__next;
    } else {
        vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__rd_data_r = 0U;
        vlSelfRef.toplevel__DOT__ctrl_busy = 0U;
        vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state = 8U;
    }
    vlSelfRef.toplevel__DOT__wr_fifoi__DOT__rd_ack2 
        = ((IData)(vlSelfRef.__Vcellinp__toplevel__rst_n_pad_i) 
           && (IData)(vlSelfRef.toplevel__DOT__wr_fifoi__DOT__rd_ack1));
    vlSelfRef.toplevel__DOT__rdaddr_fifoi__DOT__rd_ack2 
        = ((IData)(vlSelfRef.__Vcellinp__toplevel__rst_n_pad_i) 
           && (IData)(vlSelfRef.toplevel__DOT__rdaddr_fifoi__DOT__rd_ack1));
    vlSelfRef.toplevel__DOT__rddata_fifoi__DOT__wr_ack2 
        = ((IData)(vlSelfRef.__Vcellinp__toplevel__rst_n_pad_i) 
           && (IData)(vlSelfRef.toplevel__DOT__rddata_fifoi__DOT__wr_ack1));
    vlSelfRef.toplevel__DOT__wr_fifoi__DOT__rd_ack1 
        = ((IData)(vlSelfRef.__Vcellinp__toplevel__rst_n_pad_i) 
           && (IData)(vlSelfRef.toplevel__DOT__wr_fifoi__DOT__rd_syn2));
    vlSelfRef.toplevel__DOT__rdaddr_fifoi__DOT__rd_ack1 
        = ((IData)(vlSelfRef.__Vcellinp__toplevel__rst_n_pad_i) 
           && (IData)(vlSelfRef.toplevel__DOT__rdaddr_fifoi__DOT__rd_syn2));
    vlSelfRef.toplevel__DOT__rddata_fifoi__DOT__wr_ack1 
        = ((IData)(vlSelfRef.__Vcellinp__toplevel__rst_n_pad_i) 
           && (IData)(vlSelfRef.toplevel__DOT__rddata_fifoi__DOT__wr_syn2));
    VL_ASSIGN_SII(2, vlSelfRef.sdram_dqm_pad_o, ((2U 
                                                  & ((~ 
                                                      ((IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state) 
                                                       >> 4U)) 
                                                     << 1U)) 
                                                 | (1U 
                                                    & (~ 
                                                       ((IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state) 
                                                        >> 4U)))));
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
    VL_ASSIGN_SII(16, vlSelfRef.sdram_dq_pad_io, ((
                                                   ((0x1aU 
                                                     == (IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state))
                                                     ? 0xffffU
                                                     : 0U) 
                                                   & (((0x1aU 
                                                        == (IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state))
                                                        ? (IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__wr_data_r)
                                                        : 0U) 
                                                      & ((0x1aU 
                                                          == (IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state))
                                                          ? 0xffffU
                                                          : 0U))) 
                                                  & ((0x1aU 
                                                      == (IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state))
                                                      ? 0xffffU
                                                      : 0U)));
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
    VL_ASSIGN_ISI(16, vlSelfRef.__Vcellinpt__toplevel__sdram_dq_pad_io, vlSelfRef.sdram_dq_pad_io);
    VL_ASSIGN_SII(2, vlSelfRef.sdram_ba_pad_o, (3U 
                                                & ((0x10U 
                                                    & (IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state))
                                                    ? (IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__bank_addr_r)
                                                    : 
                                                   ((IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__command) 
                                                    >> 1U))));
    VL_ASSIGN_SII(13, vlSelfRef.sdram_a_pad_o, ((IData)(
                                                        (((IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state) 
                                                          >> 4U) 
                                                         | (0xeU 
                                                            == (IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state))))
                                                 ? (IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__addr_r)
                                                 : 
                                                (0x400U 
                                                 & ((IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__command) 
                                                    << 0xaU))));
}

VL_INLINE_OPT void Vtoplevel___024root___nba_sequent__TOP__4(Vtoplevel___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel___024root___nba_sequent__TOP__4\n"); );
    Vtoplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.toplevel__DOT__wr_fifoi__DOT__rd_syn2 
        = vlSelfRef.__Vdly__toplevel__DOT__wr_fifoi__DOT__rd_syn2;
    vlSelfRef.toplevel__DOT__rdaddr_fifoi__DOT__rd_syn2 
        = vlSelfRef.__Vdly__toplevel__DOT__rdaddr_fifoi__DOT__rd_syn2;
    vlSelfRef.toplevel__DOT__rddata_fifoi__DOT__wr_syn2 
        = vlSelfRef.__Vdly__toplevel__DOT__rddata_fifoi__DOT__wr_syn2;
}

void Vtoplevel___024root___eval_triggers__act(Vtoplevel___024root* vlSelf);

bool Vtoplevel___024root___eval_phase__act(Vtoplevel___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel___024root___eval_phase__act\n"); );
    Vtoplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<3> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtoplevel___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vtoplevel___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtoplevel___024root___eval_phase__nba(Vtoplevel___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel___024root___eval_phase__nba\n"); );
    Vtoplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtoplevel___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtoplevel___024root___dump_triggers__ico(Vtoplevel___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtoplevel___024root___dump_triggers__nba(Vtoplevel___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtoplevel___024root___dump_triggers__act(Vtoplevel___024root* vlSelf);
#endif  // VL_DEBUG

void Vtoplevel___024root___eval(Vtoplevel___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel___024root___eval\n"); );
    Vtoplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY(((0x64U < __VicoIterCount)))) {
#ifdef VL_DEBUG
            Vtoplevel___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("rtl/toplevel.v", 30, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vtoplevel___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelfRef.__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtoplevel___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("rtl/toplevel.v", 30, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtoplevel___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("rtl/toplevel.v", 30, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vtoplevel___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vtoplevel___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtoplevel___024root___eval_debug_assertions(Vtoplevel___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel___024root___eval_debug_assertions\n"); );
    Vtoplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
