// Verilated -*- SystemC -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_sc.h"
#include "Vtoplevel__Syms.h"


void Vtoplevel___024root__trace_chg_0_sub_0(Vtoplevel___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtoplevel___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel___024root__trace_chg_0\n"); );
    // Init
    Vtoplevel___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtoplevel___024root*>(voidSelf);
    Vtoplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtoplevel___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtoplevel___024root__trace_chg_0_sub_0(Vtoplevel___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel___024root__trace_chg_0_sub_0\n"); );
    Vtoplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[1U]))) {
        bufp->chgBit(oldp+0,(vlSelfRef.__Vcellinp__toplevel__sys_clk_pad_i));
        bufp->chgBit(oldp+1,(vlSelfRef.__Vcellinp__toplevel__rst_n_pad_i));
        bufp->chgBit(oldp+2,(vlSelfRef.__Vcellinp__toplevel__btn_n_pad_i));
        bufp->chgCData(oldp+3,(vlSelfRef.__Vcellinp__toplevel__gpio1_i),4);
        bufp->chgQData(oldp+4,((((QData)((IData)((((IData)(vlSelfRef.__Vcellinp__toplevel__gpio1_i) 
                                                   << 0x1cU) 
                                                  | (((IData)(vlSelfRef.__Vcellinp__toplevel__gpio1_i) 
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
                                 << 8U) | (QData)((IData)(
                                                          (0xffU 
                                                           & ((0xf0U 
                                                               & ((~ (IData)(vlSelfRef.__Vcellinp__toplevel__gpio1_i)) 
                                                                  << 4U)) 
                                                              | (0xfU 
                                                                 & (~ (IData)(vlSelfRef.__Vcellinp__toplevel__gpio1_i))))))))),40);
        bufp->chgIData(oldp+6,((0xffffffU & (((IData)(vlSelfRef.__Vcellinp__toplevel__gpio1_i) 
                                              << 0x14U) 
                                             | (((IData)(vlSelfRef.__Vcellinp__toplevel__gpio1_i) 
                                                 << 0x10U) 
                                                | (((IData)(vlSelfRef.__Vcellinp__toplevel__gpio1_i) 
                                                    << 0xcU) 
                                                   | (((IData)(vlSelfRef.__Vcellinp__toplevel__gpio1_i) 
                                                       << 8U) 
                                                      | (((IData)(vlSelfRef.__Vcellinp__toplevel__gpio1_i) 
                                                          << 4U) 
                                                         | (IData)(vlSelfRef.__Vcellinp__toplevel__gpio1_i)))))))),24);
        bufp->chgSData(oldp+7,(((0xff00U & (((IData)(vlSelfRef.__Vcellinp__toplevel__gpio1_i) 
                                             << 0xcU) 
                                            | ((IData)(vlSelfRef.__Vcellinp__toplevel__gpio1_i) 
                                               << 8U))) 
                                | (0xffU & ((0xf0U 
                                             & ((~ (IData)(vlSelfRef.__Vcellinp__toplevel__gpio1_i)) 
                                                << 4U)) 
                                            | (0xfU 
                                               & (~ (IData)(vlSelfRef.__Vcellinp__toplevel__gpio1_i))))))),16);
        bufp->chgBit(oldp+8,((1U & (~ (IData)(vlSelfRef.__Vcellinp__toplevel__btn_n_pad_i)))));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[2U]))) {
        bufp->chgBit(oldp+9,((1U & ((IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__command) 
                                    >> 6U))));
        bufp->chgBit(oldp+10,((1U & ((IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__command) 
                                     >> 5U))));
        bufp->chgBit(oldp+11,((1U & ((IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__command) 
                                     >> 4U))));
        bufp->chgBit(oldp+12,((1U & ((IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__command) 
                                     >> 3U))));
        bufp->chgBit(oldp+13,((1U & ((IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__command) 
                                     >> 7U))));
        bufp->chgBit(oldp+14,(vlSelfRef.toplevel__DOT__clk1m));
        bufp->chgQData(oldp+15,(vlSelfRef.toplevel__DOT__wro_fifo),40);
        bufp->chgBit(oldp+17,(vlSelfRef.toplevel__DOT__wr_fifoi__DOT__rd_fifo_cnt));
        bufp->chgIData(oldp+18,(vlSelfRef.toplevel__DOT__rdao_fifo),24);
        bufp->chgBit(oldp+19,(vlSelfRef.toplevel__DOT__rdaddr_fifoi__DOT__rd_fifo_cnt));
        bufp->chgBit(oldp+20,(vlSelfRef.toplevel__DOT__rddata_fifoi__DOT__wr_fifo_cnt));
        bufp->chgIData(oldp+21,(vlSelfRef.toplevel__DOT__pll_1mi__DOT__cnt),32);
        bufp->chgBit(oldp+22,(vlSelfRef.toplevel__DOT__rdaddr_fifoi__DOT__wr_syn1));
        bufp->chgBit(oldp+23,(vlSelfRef.toplevel__DOT__rddata_fifoi__DOT__rd_syn1));
        bufp->chgIData(oldp+24,((0xffffffU & (IData)(
                                                     (vlSelfRef.toplevel__DOT__wro_fifo 
                                                      >> 0x10U)))),24);
        bufp->chgSData(oldp+25,((0xffffU & (IData)(vlSelfRef.toplevel__DOT__wro_fifo))),16);
        bufp->chgIData(oldp+26,(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__haddr_r),24);
        bufp->chgSData(oldp+27,(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__wr_data_r),16);
        bufp->chgCData(oldp+28,(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state_cnt),4);
        bufp->chgSData(oldp+29,(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__refresh_cnt),10);
        bufp->chgCData(oldp+30,(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__command),8);
        bufp->chgBit(oldp+31,(vlSelfRef.toplevel__DOT__wr_fifoi__DOT__wr_syn1));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[3U]))) {
        bufp->chgBit(oldp+32,(vlSelfRef.toplevel__DOT__wr_enable));
        bufp->chgBit(oldp+33,(vlSelfRef.toplevel__DOT__wr_fifoi__DOT__wr_fifo_cnt));
        bufp->chgBit(oldp+34,(vlSelfRef.toplevel__DOT__rd_enable));
        bufp->chgBit(oldp+35,(vlSelfRef.toplevel__DOT__rdaddr_fifoi__DOT__wr_fifo_cnt));
        bufp->chgSData(oldp+36,(vlSelfRef.toplevel__DOT__rddata_fifo),16);
        bufp->chgBit(oldp+37,(vlSelfRef.toplevel__DOT__rddata_fifoi__DOT__rd_fifo_cnt));
        bufp->chgBit(oldp+38,(vlSelfRef.toplevel__DOT__dnano_interfacei__DOT__rd_ack_r));
        bufp->chgBit(oldp+39,(((IData)(vlSelfRef.toplevel__DOT__rdaddr_fifoi__DOT__wr_fifo_cnt) 
                               | (IData)(vlSelfRef.toplevel__DOT__wr_fifoi__DOT__wr_fifo_cnt))));
        bufp->chgCData(oldp+40,((0xffU & ((0x80000U 
                                           & vlSelfRef.toplevel__DOT__dnano_interfacei__DOT__led_cnt)
                                           ? ((IData)(vlSelfRef.toplevel__DOT__dnano_interfacei__DOT__rd_data_r) 
                                              >> 8U)
                                           : (IData)(vlSelfRef.toplevel__DOT__dnano_interfacei__DOT__rd_data_r)))),8);
        bufp->chgSData(oldp+41,(vlSelfRef.toplevel__DOT__dnano_interfacei__DOT__rd_data_r),16);
        bufp->chgIData(oldp+42,(vlSelfRef.toplevel__DOT__dnano_interfacei__DOT__led_cnt),20);
        bufp->chgBit(oldp+43,(vlSelfRef.toplevel__DOT__dnano_interfacei__DOT__double_clicki__DOT__collect));
        bufp->chgCData(oldp+44,(vlSelfRef.toplevel__DOT__dnano_interfacei__DOT__double_clicki__DOT__click_cnt),3);
        bufp->chgIData(oldp+45,(vlSelfRef.toplevel__DOT__dnano_interfacei__DOT__double_clicki__DOT__dbl_click_cnt),19);
        bufp->chgIData(oldp+46,(vlSelfRef.toplevel__DOT__rdaddr_fifoi__DOT__wr_data_r),24);
        bufp->chgBit(oldp+47,(vlSelfRef.toplevel__DOT__rdaddr_fifoi__DOT__wr_r));
        bufp->chgBit(oldp+48,(vlSelfRef.toplevel__DOT__rdaddr_fifoi__DOT__wr_ack1));
        bufp->chgBit(oldp+49,(vlSelfRef.toplevel__DOT__rdaddr_fifoi__DOT__wr_ack2));
        bufp->chgBit(oldp+50,(vlSelfRef.toplevel__DOT__rdaddr_fifoi__DOT__rd_syn1));
        bufp->chgBit(oldp+51,(vlSelfRef.toplevel__DOT__rddata_fifoi__DOT__wr_syn1));
        bufp->chgBit(oldp+52,(vlSelfRef.toplevel__DOT__rddata_fifoi__DOT__rd_r));
        bufp->chgBit(oldp+53,(vlSelfRef.toplevel__DOT__rddata_fifoi__DOT__rd_ack1));
        bufp->chgBit(oldp+54,(vlSelfRef.toplevel__DOT__rddata_fifoi__DOT__rd_ack2));
        bufp->chgQData(oldp+55,(vlSelfRef.toplevel__DOT__wr_fifoi__DOT__wr_data_r),40);
        bufp->chgBit(oldp+57,(vlSelfRef.toplevel__DOT__wr_fifoi__DOT__wr_r));
        bufp->chgBit(oldp+58,(vlSelfRef.toplevel__DOT__wr_fifoi__DOT__wr_ack1));
        bufp->chgBit(oldp+59,(vlSelfRef.toplevel__DOT__wr_fifoi__DOT__wr_ack2));
        bufp->chgBit(oldp+60,(vlSelfRef.toplevel__DOT__wr_fifoi__DOT__rd_syn1));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[4U]))) {
        bufp->chgBit(oldp+61,(vlSelfRef.toplevel__DOT__dnano_interfacei__DOT__double_clicki__DOT__btn_now));
        bufp->chgBit(oldp+62,(vlSelfRef.toplevel__DOT__dnano_interfacei__DOT__double_clicki__DOT__btn_last));
        bufp->chgBit(oldp+63,(vlSelfRef.toplevel__DOT__dnano_interfacei__DOT__double_clicki__DOT__btn_down));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[5U]))) {
        bufp->chgCData(oldp+64,(((2U & ((~ ((IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state) 
                                            >> 4U)) 
                                        << 1U)) | (1U 
                                                   & (~ 
                                                      ((IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state) 
                                                       >> 4U))))),2);
        bufp->chgBit(oldp+65,(vlSelfRef.toplevel__DOT__ctrl_busy));
        bufp->chgSData(oldp+66,(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__rd_data_r),16);
        bufp->chgBit(oldp+67,(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__rd_ready_r));
        bufp->chgBit(oldp+68,(vlSelfRef.toplevel__DOT__rdaddr_fifoi__DOT__wr_syn2));
        bufp->chgBit(oldp+69,(vlSelfRef.toplevel__DOT__rdaddr_fifoi__DOT__rd_r));
        bufp->chgBit(oldp+70,(vlSelfRef.toplevel__DOT__rdaddr_fifoi__DOT__rd_ack1));
        bufp->chgBit(oldp+71,(vlSelfRef.toplevel__DOT__rdaddr_fifoi__DOT__rd_ack2));
        bufp->chgSData(oldp+72,(vlSelfRef.toplevel__DOT__rddata_fifoi__DOT__wr_data_r),16);
        bufp->chgBit(oldp+73,(vlSelfRef.toplevel__DOT__rddata_fifoi__DOT__wr_r));
        bufp->chgBit(oldp+74,(vlSelfRef.toplevel__DOT__rddata_fifoi__DOT__wr_ack1));
        bufp->chgBit(oldp+75,(vlSelfRef.toplevel__DOT__rddata_fifoi__DOT__wr_ack2));
        bufp->chgBit(oldp+76,(vlSelfRef.toplevel__DOT__rddata_fifoi__DOT__rd_syn2));
        bufp->chgBit(oldp+77,((1U & (~ ((IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state) 
                                        >> 4U)))));
        bufp->chgSData(oldp+78,(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__addr_r),13);
        bufp->chgCData(oldp+79,(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__bank_addr_r),2);
        bufp->chgCData(oldp+80,(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state),5);
        bufp->chgCData(oldp+81,(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__command_nxt),8);
        bufp->chgCData(oldp+82,(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state_cnt_nxt),4);
        bufp->chgCData(oldp+83,(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__next),5);
        bufp->chgBit(oldp+84,(vlSelfRef.toplevel__DOT__wr_fifoi__DOT__wr_syn2));
        bufp->chgBit(oldp+85,(vlSelfRef.toplevel__DOT__wr_fifoi__DOT__rd_r));
        bufp->chgBit(oldp+86,(vlSelfRef.toplevel__DOT__wr_fifoi__DOT__rd_ack1));
        bufp->chgBit(oldp+87,(vlSelfRef.toplevel__DOT__wr_fifoi__DOT__rd_ack2));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[6U]))) {
        bufp->chgBit(oldp+88,(vlSelfRef.toplevel__DOT__rdaddr_fifoi__DOT__rd_syn2));
        bufp->chgBit(oldp+89,(vlSelfRef.toplevel__DOT__rddata_fifoi__DOT__wr_syn2));
        bufp->chgBit(oldp+90,(vlSelfRef.toplevel__DOT__wr_fifoi__DOT__rd_syn2));
    }
    bufp->chgCData(oldp+91,((3U & ((0x10U & (IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state))
                                    ? (IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__bank_addr_r)
                                    : ((IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__command) 
                                       >> 1U)))),2);
    bufp->chgSData(oldp+92,(((IData)((((IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state) 
                                       >> 4U) | (0xeU 
                                                 == (IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state))))
                              ? (IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__addr_r)
                              : (0x400U & ((IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__command) 
                                           << 0xaU)))),13);
    bufp->chgSData(oldp+93,(vlSelfRef.__Vcellinpt__toplevel__sdram_dq_pad_io),16);
    bufp->chgCData(oldp+94,(vlSelfRef.__Vcellinpt__toplevel__gpio0_io),8);
    bufp->chgBit(oldp+95,(vlSelfRef.toplevel__DOT__dnano_interfacei__DOT__dbl_clck_rst_n));
}

void Vtoplevel___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel___024root__trace_cleanup\n"); );
    // Init
    Vtoplevel___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtoplevel___024root*>(voidSelf);
    Vtoplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[4U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[5U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[6U] = 0U;
}
