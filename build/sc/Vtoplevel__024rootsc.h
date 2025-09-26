// Verilated -*- SystemC -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtoplevel.h for the primary calling header

#ifndef VERILATED_VTOPLEVEL___024ROOT_H_
#define VERILATED_VTOPLEVEL___024ROOT_H_  // guard

#include "systemc"
#include "verilated_sc.h"
#include "verilated.h"


class Vtoplevel__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtoplevel___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ __Vcellinp__toplevel__sys_clk_pad_i;
        CData/*0:0*/ toplevel__DOT__clk1m;
        CData/*3:0*/ __Vcellinp__toplevel__gpio1_i;
        CData/*7:0*/ __Vcellinpt__toplevel__gpio0_io;
        CData/*0:0*/ __Vcellinp__toplevel__btn_n_pad_i;
        CData/*0:0*/ __Vcellinp__toplevel__rst_n_pad_i;
        CData/*0:0*/ toplevel__DOT__wr_enable;
        CData/*0:0*/ toplevel__DOT__ctrl_busy;
        CData/*0:0*/ toplevel__DOT__rd_enable;
        CData/*0:0*/ toplevel__DOT__wr_fifoi__DOT__wr_r;
        CData/*0:0*/ toplevel__DOT__wr_fifoi__DOT__wr_syn1;
        CData/*0:0*/ toplevel__DOT__wr_fifoi__DOT__wr_syn2;
        CData/*0:0*/ toplevel__DOT__wr_fifoi__DOT__wr_ack1;
        CData/*0:0*/ toplevel__DOT__wr_fifoi__DOT__wr_ack2;
        CData/*0:0*/ toplevel__DOT__wr_fifoi__DOT__rd_r;
        CData/*0:0*/ toplevel__DOT__wr_fifoi__DOT__rd_syn1;
        CData/*0:0*/ toplevel__DOT__wr_fifoi__DOT__rd_syn2;
        CData/*0:0*/ toplevel__DOT__wr_fifoi__DOT__rd_ack1;
        CData/*0:0*/ toplevel__DOT__wr_fifoi__DOT__rd_ack2;
        CData/*0:0*/ toplevel__DOT__wr_fifoi__DOT__wr_fifo_cnt;
        CData/*0:0*/ toplevel__DOT__wr_fifoi__DOT__rd_fifo_cnt;
        CData/*0:0*/ toplevel__DOT__rdaddr_fifoi__DOT__wr_r;
        CData/*0:0*/ toplevel__DOT__rdaddr_fifoi__DOT__wr_syn1;
        CData/*0:0*/ toplevel__DOT__rdaddr_fifoi__DOT__wr_syn2;
        CData/*0:0*/ toplevel__DOT__rdaddr_fifoi__DOT__wr_ack1;
        CData/*0:0*/ toplevel__DOT__rdaddr_fifoi__DOT__wr_ack2;
        CData/*0:0*/ toplevel__DOT__rdaddr_fifoi__DOT__rd_r;
        CData/*0:0*/ toplevel__DOT__rdaddr_fifoi__DOT__rd_syn1;
        CData/*0:0*/ toplevel__DOT__rdaddr_fifoi__DOT__rd_syn2;
        CData/*0:0*/ toplevel__DOT__rdaddr_fifoi__DOT__rd_ack1;
        CData/*0:0*/ toplevel__DOT__rdaddr_fifoi__DOT__rd_ack2;
        CData/*0:0*/ toplevel__DOT__rdaddr_fifoi__DOT__wr_fifo_cnt;
        CData/*0:0*/ toplevel__DOT__rdaddr_fifoi__DOT__rd_fifo_cnt;
        CData/*0:0*/ toplevel__DOT__rddata_fifoi__DOT__wr_r;
        CData/*0:0*/ toplevel__DOT__rddata_fifoi__DOT__wr_syn1;
        CData/*0:0*/ toplevel__DOT__rddata_fifoi__DOT__wr_syn2;
        CData/*0:0*/ toplevel__DOT__rddata_fifoi__DOT__wr_ack1;
        CData/*0:0*/ toplevel__DOT__rddata_fifoi__DOT__wr_ack2;
        CData/*0:0*/ toplevel__DOT__rddata_fifoi__DOT__rd_r;
        CData/*0:0*/ toplevel__DOT__rddata_fifoi__DOT__rd_syn1;
        CData/*0:0*/ toplevel__DOT__rddata_fifoi__DOT__rd_syn2;
        CData/*0:0*/ toplevel__DOT__rddata_fifoi__DOT__rd_ack1;
        CData/*0:0*/ toplevel__DOT__rddata_fifoi__DOT__rd_ack2;
        CData/*0:0*/ toplevel__DOT__rddata_fifoi__DOT__wr_fifo_cnt;
        CData/*0:0*/ toplevel__DOT__rddata_fifoi__DOT__rd_fifo_cnt;
        CData/*1:0*/ toplevel__DOT__sdram_controlleri__DOT__bank_addr_r;
        CData/*0:0*/ toplevel__DOT__sdram_controlleri__DOT__rd_ready_r;
        CData/*3:0*/ toplevel__DOT__sdram_controlleri__DOT__state_cnt;
        CData/*7:0*/ toplevel__DOT__sdram_controlleri__DOT__command;
        CData/*4:0*/ toplevel__DOT__sdram_controlleri__DOT__state;
        CData/*7:0*/ toplevel__DOT__sdram_controlleri__DOT__command_nxt;
        CData/*3:0*/ toplevel__DOT__sdram_controlleri__DOT__state_cnt_nxt;
        CData/*4:0*/ toplevel__DOT__sdram_controlleri__DOT__next;
        CData/*0:0*/ toplevel__DOT__dnano_interfacei__DOT__rd_ack_r;
        CData/*0:0*/ toplevel__DOT__dnano_interfacei__DOT__dbl_clck_rst_n;
        CData/*0:0*/ toplevel__DOT__dnano_interfacei__DOT__double_clicki__DOT__btn_now;
        CData/*0:0*/ toplevel__DOT__dnano_interfacei__DOT__double_clicki__DOT__btn_last;
        CData/*0:0*/ toplevel__DOT__dnano_interfacei__DOT__double_clicki__DOT__collect;
        CData/*2:0*/ toplevel__DOT__dnano_interfacei__DOT__double_clicki__DOT__click_cnt;
        CData/*0:0*/ toplevel__DOT__dnano_interfacei__DOT__double_clicki__DOT__btn_down;
        CData/*0:0*/ __Vdly__toplevel__DOT__wr_fifoi__DOT__wr_syn2;
        CData/*0:0*/ __Vdly__toplevel__DOT__rdaddr_fifoi__DOT__wr_syn2;
        CData/*0:0*/ __Vdly__toplevel__DOT__rddata_fifoi__DOT__rd_syn2;
        CData/*0:0*/ __Vdly__toplevel__DOT__wr_fifoi__DOT__rd_syn2;
    };
    struct {
        CData/*0:0*/ __Vdly__toplevel__DOT__rdaddr_fifoi__DOT__rd_syn2;
        CData/*0:0*/ __Vdly__toplevel__DOT__rddata_fifoi__DOT__wr_syn2;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __VicoFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP____Vcellinp__toplevel__sys_clk_pad_i__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__toplevel__DOT__clk1m__0;
        CData/*0:0*/ __VactContinue;
        SData/*15:0*/ __Vcellinpt__toplevel__sdram_dq_pad_io;
        SData/*15:0*/ toplevel__DOT__rddata_fifo;
        SData/*15:0*/ toplevel__DOT__rddata_fifoi__DOT__wr_data_r;
        SData/*15:0*/ toplevel__DOT__sdram_controlleri__DOT__wr_data_r;
        SData/*15:0*/ toplevel__DOT__sdram_controlleri__DOT__rd_data_r;
        SData/*12:0*/ toplevel__DOT__sdram_controlleri__DOT__addr_r;
        SData/*9:0*/ toplevel__DOT__sdram_controlleri__DOT__refresh_cnt;
        SData/*15:0*/ toplevel__DOT__dnano_interfacei__DOT__rd_data_r;
        IData/*23:0*/ toplevel__DOT__rdao_fifo;
        IData/*31:0*/ toplevel__DOT__pll_1mi__DOT__cnt;
        IData/*23:0*/ toplevel__DOT__rdaddr_fifoi__DOT__wr_data_r;
        IData/*23:0*/ toplevel__DOT__sdram_controlleri__DOT__haddr_r;
        IData/*19:0*/ toplevel__DOT__dnano_interfacei__DOT__led_cnt;
        IData/*18:0*/ toplevel__DOT__dnano_interfacei__DOT__double_clicki__DOT__dbl_click_cnt;
        IData/*31:0*/ __VactIterCount;
        QData/*39:0*/ toplevel__DOT__wro_fifo;
        QData/*39:0*/ toplevel__DOT__wr_fifoi__DOT__wr_data_r;
        VlUnpacked<CData/*0:0*/, 7> __Vm_traceActivity;
    };
    sc_core::sc_in<bool> sys_clk_pad_i;
    sc_core::sc_in<bool> rst_n_pad_i;
    sc_core::sc_in<bool> btn_n_pad_i;
    sc_core::sc_out<uint32_t> sdram_ba_pad_o;
    sc_core::sc_out<bool> sdram_cs_n_pad_o;
    sc_core::sc_out<bool> sdram_ras_pad_o;
    sc_core::sc_out<bool> sdram_cas_pad_o;
    sc_core::sc_out<bool> sdram_we_pad_o;
    sc_core::sc_out<uint32_t> sdram_dqm_pad_o;
    sc_core::sc_out<bool> sdram_cke_pad_o;
    sc_core::sc_out<bool> sdram_clk_pad_o;
    sc_core::sc_inout<uint32_t> gpio0_io;
    sc_core::sc_in<uint32_t> gpio1_i;
    sc_core::sc_out<uint32_t> sdram_a_pad_o;
    sc_core::sc_inout<uint32_t> sdram_dq_pad_io;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<3> __VactTriggered;
    VlTriggerVec<3> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtoplevel__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtoplevel___024root(Vtoplevel__Syms* symsp, const char* v__name);
    ~Vtoplevel___024root();
    VL_UNCOPYABLE(Vtoplevel___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
