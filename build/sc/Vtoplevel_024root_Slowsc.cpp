// Verilated -*- SystemC -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtoplevel.h for the primary calling header

#include "Vtoplevel__pch.h"
#include "Vtoplevel__Syms.h"
#include "Vtoplevel___024root.h"

void Vtoplevel___024root___ctor_var_reset(Vtoplevel___024root* vlSelf);

Vtoplevel___024root::Vtoplevel___024root(Vtoplevel__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , sys_clk_pad_i("sys_clk_pad_i")
    , rst_n_pad_i("rst_n_pad_i")
    , btn_n_pad_i("btn_n_pad_i")
    , sdram_ba_pad_o("sdram_ba_pad_o")
    , sdram_cs_n_pad_o("sdram_cs_n_pad_o")
    , sdram_ras_pad_o("sdram_ras_pad_o")
    , sdram_cas_pad_o("sdram_cas_pad_o")
    , sdram_we_pad_o("sdram_we_pad_o")
    , sdram_dqm_pad_o("sdram_dqm_pad_o")
    , sdram_cke_pad_o("sdram_cke_pad_o")
    , sdram_clk_pad_o("sdram_clk_pad_o")
    , gpio0_io("gpio0_io")
    , gpio1_i("gpio1_i")
    , sdram_a_pad_o("sdram_a_pad_o")
    , sdram_dq_pad_io("sdram_dq_pad_io")
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtoplevel___024root___ctor_var_reset(this);
}

void Vtoplevel___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtoplevel___024root::~Vtoplevel___024root() {
}
