// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtoplevel__Syms.h"


VL_ATTR_COLD void Vtoplevel___024root__trace_init_sub__TOP__0(Vtoplevel___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel___024root__trace_init_sub__TOP__0\n"); );
    Vtoplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->pushPrefix("$rootio", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+76,0,"sys_clk_pad_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+77,0,"rst_n_pad_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+78,0,"btn_n_pad_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+79,0,"sdram_ba_pad_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+80,0,"sdram_a_pad_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBit(c+81,0,"sdram_cs_n_pad_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+82,0,"sdram_ras_pad_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+83,0,"sdram_cas_pad_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+84,0,"sdram_we_pad_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+85,0,"sdram_dq_pad_io",-1, VerilatedTraceSigDirection::INOUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+86,0,"sdram_dqm_pad_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+87,0,"sdram_cke_pad_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+88,0,"sdram_clk_pad_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+89,0,"gpio0_io",-1, VerilatedTraceSigDirection::INOUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+90,0,"gpio1_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->popPrefix();
    tracep->pushPrefix("toplevel", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+76,0,"sys_clk_pad_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+77,0,"rst_n_pad_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+78,0,"btn_n_pad_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+79,0,"sdram_ba_pad_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+80,0,"sdram_a_pad_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBit(c+81,0,"sdram_cs_n_pad_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+82,0,"sdram_ras_pad_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+83,0,"sdram_cas_pad_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+84,0,"sdram_we_pad_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+85,0,"sdram_dq_pad_io",-1, VerilatedTraceSigDirection::INOUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+86,0,"sdram_dqm_pad_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+87,0,"sdram_cke_pad_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+88,0,"sdram_clk_pad_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+89,0,"gpio0_io",-1, VerilatedTraceSigDirection::INOUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+90,0,"gpio1_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+76,0,"clk100m",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"clk1m",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+91,0,"wr_fifo",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 39,0);
    tracep->declBit(c+19,0,"wr_enable",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+20,0,"wr_full",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+2,0,"wro_fifo",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 39,0);
    tracep->declBit(c+50,0,"ctrl_busy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+4,0,"ctrl_wr_enable",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+21,0,"rd_enable",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+22,0,"rdaddr_full",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+5,0,"rdao_fifo",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBit(c+6,0,"ctrl_rd_enable",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+51,0,"rddo_fifo",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+52,0,"ctrl_rd_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+23,0,"rddata_fifo",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+24,0,"rd_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+25,0,"rd_ack",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+7,0,"unused_fifo_full",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+26,0,"busy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("dnano_interfacei", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+97,0,"HADDR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+98,0,"DOUBlE_CLICK_WAIT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+99,0,"LED_BLINK",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+78,0,"button_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+90,0,"dip",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+89,0,"leds",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+93,0,"haddr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+94,0,"wr_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+23,0,"rd_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+26,0,"busy",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+21,0,"rd_enable",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+24,0,"rd_rdy",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+25,0,"rd_ack",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+19,0,"wr_enable",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+77,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+27,0,"rd_data_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+28,0,"led_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 19,0);
    tracep->declBit(c+25,0,"rd_ack_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+95,0,"dbl_clck_rst_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("double_clicki", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+98,0,"WAIT_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+96,0,"button",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+19,0,"single",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+21,0,"double",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+95,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+47,0,"btn_now",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+48,0,"btn_last",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+29,0,"collect",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+30,0,"click_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+31,0,"dbl_click_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 18,0);
    tracep->declBit(c+49,0,"btn_down",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("pll_100mi", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+76,0,"inclk0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+76,0,"c0",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("pll_1mi", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+76,0,"inclk0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"c0",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+100,0,"HALF",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+8,0,"cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("rdaddr_fifoi", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+97,0,"BUS_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+93,0,"wr_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBit(c+1,0,"wr_clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+21,0,"wr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+22,0,"full",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+5,0,"rd_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBit(c+76,0,"rd_clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+50,0,"rd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+6,0,"empty_n",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+77,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+32,0,"wr_data_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBit(c+33,0,"wr_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+9,0,"wr_syn1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+53,0,"wr_syn2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+34,0,"wr_ack1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+35,0,"wr_ack2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+54,0,"rd_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+36,0,"rd_syn1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+73,0,"rd_syn2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+55,0,"rd_ack1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+56,0,"rd_ack2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+22,0,"wr_fifo_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+6,0,"rd_fifo_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("rddata_fifoi", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+101,0,"BUS_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+51,0,"wr_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+76,0,"wr_clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+52,0,"wr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+7,0,"full",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+23,0,"rd_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+1,0,"rd_clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+25,0,"rd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+24,0,"empty_n",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+77,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+57,0,"wr_data_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+58,0,"wr_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+37,0,"wr_syn1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+74,0,"wr_syn2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+59,0,"wr_ack1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+60,0,"wr_ack2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+38,0,"rd_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+10,0,"rd_syn1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+61,0,"rd_syn2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+39,0,"rd_ack1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+40,0,"rd_ack2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+7,0,"wr_fifo_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+24,0,"rd_fifo_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("sdram_controlleri", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+102,0,"ROW_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+103,0,"COL_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+104,0,"BANK_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+102,0,"SDRADDR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+97,0,"HADDR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+105,0,"CLK_FREQUENCY",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+106,0,"REFRESH_TIME",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+107,0,"REFRESH_COUNT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+108,0,"CYCLES_BETWEEN_REFRESH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+109,0,"IDLE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+110,0,"INIT_NOP1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+111,0,"INIT_PRE1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+112,0,"INIT_NOP1_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+113,0,"INIT_REF1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+114,0,"INIT_NOP2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+115,0,"INIT_REF2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+116,0,"INIT_NOP3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+117,0,"INIT_LOAD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+118,0,"INIT_NOP4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+119,0,"REF_PRE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+120,0,"REF_NOP1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+121,0,"REF_REF",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+122,0,"REF_NOP2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+123,0,"READ_ACT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+124,0,"READ_NOP1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+125,0,"READ_CAS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+126,0,"READ_NOP2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+127,0,"READ_READ",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+128,0,"WRIT_ACT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+129,0,"WRIT_NOP1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+130,0,"WRIT_CAS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+131,0,"WRIT_NOP2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+132,0,"CMD_PALL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+133,0,"CMD_REF",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+134,0,"CMD_NOP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+135,0,"CMD_MRS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+136,0,"CMD_BACT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+137,0,"CMD_READ",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+138,0,"CMD_WRIT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+11,0,"wr_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+12,0,"wr_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+4,0,"wr_enable",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+5,0,"rd_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+51,0,"rd_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+6,0,"rd_enable",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+52,0,"rd_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+50,0,"busy",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+77,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+76,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+80,0,"addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+79,0,"bank_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+85,0,"data",-1, VerilatedTraceSigDirection::INOUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+87,0,"clock_enable",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+81,0,"cs_n",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+82,0,"ras_n",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+83,0,"cas_n",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+84,0,"we_n",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+62,0,"data_mask_low",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+62,0,"data_mask_high",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+13,0,"haddr_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+14,0,"wr_data_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+51,0,"rd_data_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+62,0,"data_mask_low_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+62,0,"data_mask_high_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+63,0,"addr_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+64,0,"bank_addr_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+52,0,"rd_ready_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+15,0,"state_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+16,0,"refresh_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBus(c+17,0,"command",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+65,0,"state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+66,0,"command_nxt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+67,0,"state_cnt_nxt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+68,0,"next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->popPrefix();
    tracep->pushPrefix("wr_fifoi", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+139,0,"BUS_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+91,0,"wr_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 39,0);
    tracep->declBit(c+1,0,"wr_clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+19,0,"wr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+20,0,"full",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+2,0,"rd_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 39,0);
    tracep->declBit(c+76,0,"rd_clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+50,0,"rd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+4,0,"empty_n",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+77,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+41,0,"wr_data_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 39,0);
    tracep->declBit(c+43,0,"wr_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+18,0,"wr_syn1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+69,0,"wr_syn2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+44,0,"wr_ack1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+45,0,"wr_ack2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+70,0,"rd_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+46,0,"rd_syn1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+75,0,"rd_syn2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+71,0,"rd_ack1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+72,0,"rd_ack2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+20,0,"wr_fifo_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+4,0,"rd_fifo_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vtoplevel___024root__trace_init_top(Vtoplevel___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel___024root__trace_init_top\n"); );
    Vtoplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtoplevel___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vtoplevel___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vtoplevel___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtoplevel___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtoplevel___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vtoplevel___024root__trace_register(Vtoplevel___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel___024root__trace_register\n"); );
    Vtoplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vtoplevel___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vtoplevel___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vtoplevel___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vtoplevel___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vtoplevel___024root__trace_const_0_sub_0(Vtoplevel___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtoplevel___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel___024root__trace_const_0\n"); );
    // Init
    Vtoplevel___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtoplevel___024root*>(voidSelf);
    Vtoplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtoplevel___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtoplevel___024root__trace_const_0_sub_0(Vtoplevel___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel___024root__trace_const_0_sub_0\n"); );
    Vtoplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+97,(0x18U),32);
    bufp->fullIData(oldp+98,(0x13U),32);
    bufp->fullIData(oldp+99,(0x14U),32);
    bufp->fullIData(oldp+100,(0x19U),32);
    bufp->fullIData(oldp+101,(0x10U),32);
    bufp->fullIData(oldp+102,(0xdU),32);
    bufp->fullIData(oldp+103,(9U),32);
    bufp->fullIData(oldp+104,(2U),32);
    bufp->fullIData(oldp+105,(0x85U),32);
    bufp->fullIData(oldp+106,(0x20U),32);
    bufp->fullIData(oldp+107,(0x2000U),32);
    bufp->fullIData(oldp+108,(0x207U),32);
    bufp->fullCData(oldp+109,(0U),5);
    bufp->fullCData(oldp+110,(8U),5);
    bufp->fullCData(oldp+111,(9U),5);
    bufp->fullCData(oldp+112,(5U),5);
    bufp->fullCData(oldp+113,(0xaU),5);
    bufp->fullCData(oldp+114,(0xbU),5);
    bufp->fullCData(oldp+115,(0xcU),5);
    bufp->fullCData(oldp+116,(0xdU),5);
    bufp->fullCData(oldp+117,(0xeU),5);
    bufp->fullCData(oldp+118,(0xfU),5);
    bufp->fullCData(oldp+119,(1U),5);
    bufp->fullCData(oldp+120,(2U),5);
    bufp->fullCData(oldp+121,(3U),5);
    bufp->fullCData(oldp+122,(4U),5);
    bufp->fullCData(oldp+123,(0x10U),5);
    bufp->fullCData(oldp+124,(0x11U),5);
    bufp->fullCData(oldp+125,(0x12U),5);
    bufp->fullCData(oldp+126,(0x13U),5);
    bufp->fullCData(oldp+127,(0x14U),5);
    bufp->fullCData(oldp+128,(0x18U),5);
    bufp->fullCData(oldp+129,(0x19U),5);
    bufp->fullCData(oldp+130,(0x1aU),5);
    bufp->fullCData(oldp+131,(0x1bU),5);
    bufp->fullCData(oldp+132,(0x91U),8);
    bufp->fullCData(oldp+133,(0x88U),8);
    bufp->fullCData(oldp+134,(0xb8U),8);
    bufp->fullCData(oldp+135,(0x80U),8);
    bufp->fullCData(oldp+136,(0x98U),8);
    bufp->fullCData(oldp+137,(0xa9U),8);
    bufp->fullCData(oldp+138,(0xa1U),8);
    bufp->fullIData(oldp+139,(0x28U),32);
}

VL_ATTR_COLD void Vtoplevel___024root__trace_full_0_sub_0(Vtoplevel___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtoplevel___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel___024root__trace_full_0\n"); );
    // Init
    Vtoplevel___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtoplevel___024root*>(voidSelf);
    Vtoplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtoplevel___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtoplevel___024root__trace_full_0_sub_0(Vtoplevel___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel___024root__trace_full_0_sub_0\n"); );
    Vtoplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,(vlSelfRef.toplevel__DOT__clk1m));
    bufp->fullQData(oldp+2,(vlSelfRef.toplevel__DOT__wro_fifo),40);
    bufp->fullBit(oldp+4,(vlSelfRef.toplevel__DOT__wr_fifoi__DOT__rd_fifo_cnt));
    bufp->fullIData(oldp+5,(vlSelfRef.toplevel__DOT__rdao_fifo),24);
    bufp->fullBit(oldp+6,(vlSelfRef.toplevel__DOT__rdaddr_fifoi__DOT__rd_fifo_cnt));
    bufp->fullBit(oldp+7,(vlSelfRef.toplevel__DOT__rddata_fifoi__DOT__wr_fifo_cnt));
    bufp->fullIData(oldp+8,(vlSelfRef.toplevel__DOT__pll_1mi__DOT__cnt),32);
    bufp->fullBit(oldp+9,(vlSelfRef.toplevel__DOT__rdaddr_fifoi__DOT__wr_syn1));
    bufp->fullBit(oldp+10,(vlSelfRef.toplevel__DOT__rddata_fifoi__DOT__rd_syn1));
    bufp->fullIData(oldp+11,((0xffffffU & (IData)((vlSelfRef.toplevel__DOT__wro_fifo 
                                                   >> 0x10U)))),24);
    bufp->fullSData(oldp+12,((0xffffU & (IData)(vlSelfRef.toplevel__DOT__wro_fifo))),16);
    bufp->fullIData(oldp+13,(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__haddr_r),24);
    bufp->fullSData(oldp+14,(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__wr_data_r),16);
    bufp->fullCData(oldp+15,(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state_cnt),4);
    bufp->fullSData(oldp+16,(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__refresh_cnt),10);
    bufp->fullCData(oldp+17,(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__command),8);
    bufp->fullBit(oldp+18,(vlSelfRef.toplevel__DOT__wr_fifoi__DOT__wr_syn1));
    bufp->fullBit(oldp+19,(vlSelfRef.toplevel__DOT__wr_enable));
    bufp->fullBit(oldp+20,(vlSelfRef.toplevel__DOT__wr_fifoi__DOT__wr_fifo_cnt));
    bufp->fullBit(oldp+21,(vlSelfRef.toplevel__DOT__rd_enable));
    bufp->fullBit(oldp+22,(vlSelfRef.toplevel__DOT__rdaddr_fifoi__DOT__wr_fifo_cnt));
    bufp->fullSData(oldp+23,(vlSelfRef.toplevel__DOT__rddata_fifo),16);
    bufp->fullBit(oldp+24,(vlSelfRef.toplevel__DOT__rddata_fifoi__DOT__rd_fifo_cnt));
    bufp->fullBit(oldp+25,(vlSelfRef.toplevel__DOT__dnano_interfacei__DOT__rd_ack_r));
    bufp->fullBit(oldp+26,(((IData)(vlSelfRef.toplevel__DOT__rdaddr_fifoi__DOT__wr_fifo_cnt) 
                            | (IData)(vlSelfRef.toplevel__DOT__wr_fifoi__DOT__wr_fifo_cnt))));
    bufp->fullSData(oldp+27,(vlSelfRef.toplevel__DOT__dnano_interfacei__DOT__rd_data_r),16);
    bufp->fullIData(oldp+28,(vlSelfRef.toplevel__DOT__dnano_interfacei__DOT__led_cnt),20);
    bufp->fullBit(oldp+29,(vlSelfRef.toplevel__DOT__dnano_interfacei__DOT__double_clicki__DOT__collect));
    bufp->fullCData(oldp+30,(vlSelfRef.toplevel__DOT__dnano_interfacei__DOT__double_clicki__DOT__click_cnt),3);
    bufp->fullIData(oldp+31,(vlSelfRef.toplevel__DOT__dnano_interfacei__DOT__double_clicki__DOT__dbl_click_cnt),19);
    bufp->fullIData(oldp+32,(vlSelfRef.toplevel__DOT__rdaddr_fifoi__DOT__wr_data_r),24);
    bufp->fullBit(oldp+33,(vlSelfRef.toplevel__DOT__rdaddr_fifoi__DOT__wr_r));
    bufp->fullBit(oldp+34,(vlSelfRef.toplevel__DOT__rdaddr_fifoi__DOT__wr_ack1));
    bufp->fullBit(oldp+35,(vlSelfRef.toplevel__DOT__rdaddr_fifoi__DOT__wr_ack2));
    bufp->fullBit(oldp+36,(vlSelfRef.toplevel__DOT__rdaddr_fifoi__DOT__rd_syn1));
    bufp->fullBit(oldp+37,(vlSelfRef.toplevel__DOT__rddata_fifoi__DOT__wr_syn1));
    bufp->fullBit(oldp+38,(vlSelfRef.toplevel__DOT__rddata_fifoi__DOT__rd_r));
    bufp->fullBit(oldp+39,(vlSelfRef.toplevel__DOT__rddata_fifoi__DOT__rd_ack1));
    bufp->fullBit(oldp+40,(vlSelfRef.toplevel__DOT__rddata_fifoi__DOT__rd_ack2));
    bufp->fullQData(oldp+41,(vlSelfRef.toplevel__DOT__wr_fifoi__DOT__wr_data_r),40);
    bufp->fullBit(oldp+43,(vlSelfRef.toplevel__DOT__wr_fifoi__DOT__wr_r));
    bufp->fullBit(oldp+44,(vlSelfRef.toplevel__DOT__wr_fifoi__DOT__wr_ack1));
    bufp->fullBit(oldp+45,(vlSelfRef.toplevel__DOT__wr_fifoi__DOT__wr_ack2));
    bufp->fullBit(oldp+46,(vlSelfRef.toplevel__DOT__wr_fifoi__DOT__rd_syn1));
    bufp->fullBit(oldp+47,(vlSelfRef.toplevel__DOT__dnano_interfacei__DOT__double_clicki__DOT__btn_now));
    bufp->fullBit(oldp+48,(vlSelfRef.toplevel__DOT__dnano_interfacei__DOT__double_clicki__DOT__btn_last));
    bufp->fullBit(oldp+49,(vlSelfRef.toplevel__DOT__dnano_interfacei__DOT__double_clicki__DOT__btn_down));
    bufp->fullBit(oldp+50,(vlSelfRef.toplevel__DOT__ctrl_busy));
    bufp->fullSData(oldp+51,(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__rd_data_r),16);
    bufp->fullBit(oldp+52,(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__rd_ready_r));
    bufp->fullBit(oldp+53,(vlSelfRef.toplevel__DOT__rdaddr_fifoi__DOT__wr_syn2));
    bufp->fullBit(oldp+54,(vlSelfRef.toplevel__DOT__rdaddr_fifoi__DOT__rd_r));
    bufp->fullBit(oldp+55,(vlSelfRef.toplevel__DOT__rdaddr_fifoi__DOT__rd_ack1));
    bufp->fullBit(oldp+56,(vlSelfRef.toplevel__DOT__rdaddr_fifoi__DOT__rd_ack2));
    bufp->fullSData(oldp+57,(vlSelfRef.toplevel__DOT__rddata_fifoi__DOT__wr_data_r),16);
    bufp->fullBit(oldp+58,(vlSelfRef.toplevel__DOT__rddata_fifoi__DOT__wr_r));
    bufp->fullBit(oldp+59,(vlSelfRef.toplevel__DOT__rddata_fifoi__DOT__wr_ack1));
    bufp->fullBit(oldp+60,(vlSelfRef.toplevel__DOT__rddata_fifoi__DOT__wr_ack2));
    bufp->fullBit(oldp+61,(vlSelfRef.toplevel__DOT__rddata_fifoi__DOT__rd_syn2));
    bufp->fullBit(oldp+62,((1U & (~ ((IData)(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state) 
                                     >> 4U)))));
    bufp->fullSData(oldp+63,(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__addr_r),13);
    bufp->fullCData(oldp+64,(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__bank_addr_r),2);
    bufp->fullCData(oldp+65,(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state),5);
    bufp->fullCData(oldp+66,(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__command_nxt),8);
    bufp->fullCData(oldp+67,(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__state_cnt_nxt),4);
    bufp->fullCData(oldp+68,(vlSelfRef.toplevel__DOT__sdram_controlleri__DOT__next),5);
    bufp->fullBit(oldp+69,(vlSelfRef.toplevel__DOT__wr_fifoi__DOT__wr_syn2));
    bufp->fullBit(oldp+70,(vlSelfRef.toplevel__DOT__wr_fifoi__DOT__rd_r));
    bufp->fullBit(oldp+71,(vlSelfRef.toplevel__DOT__wr_fifoi__DOT__rd_ack1));
    bufp->fullBit(oldp+72,(vlSelfRef.toplevel__DOT__wr_fifoi__DOT__rd_ack2));
    bufp->fullBit(oldp+73,(vlSelfRef.toplevel__DOT__rdaddr_fifoi__DOT__rd_syn2));
    bufp->fullBit(oldp+74,(vlSelfRef.toplevel__DOT__rddata_fifoi__DOT__wr_syn2));
    bufp->fullBit(oldp+75,(vlSelfRef.toplevel__DOT__wr_fifoi__DOT__rd_syn2));
    bufp->fullBit(oldp+76,(vlSelfRef.sys_clk_pad_i));
    bufp->fullBit(oldp+77,(vlSelfRef.rst_n_pad_i));
    bufp->fullBit(oldp+78,(vlSelfRef.btn_n_pad_i));
    bufp->fullCData(oldp+79,(vlSelfRef.sdram_ba_pad_o),2);
    bufp->fullSData(oldp+80,(vlSelfRef.sdram_a_pad_o),13);
    bufp->fullBit(oldp+81,(vlSelfRef.sdram_cs_n_pad_o));
    bufp->fullBit(oldp+82,(vlSelfRef.sdram_ras_pad_o));
    bufp->fullBit(oldp+83,(vlSelfRef.sdram_cas_pad_o));
    bufp->fullBit(oldp+84,(vlSelfRef.sdram_we_pad_o));
    bufp->fullSData(oldp+85,(vlSelfRef.sdram_dq_pad_io),16);
    bufp->fullCData(oldp+86,(vlSelfRef.sdram_dqm_pad_o),2);
    bufp->fullBit(oldp+87,(vlSelfRef.sdram_cke_pad_o));
    bufp->fullBit(oldp+88,(vlSelfRef.sdram_clk_pad_o));
    bufp->fullCData(oldp+89,(vlSelfRef.gpio0_io),8);
    bufp->fullCData(oldp+90,(vlSelfRef.gpio1_i),4);
    bufp->fullQData(oldp+91,((((QData)((IData)((((IData)(vlSelfRef.gpio1_i) 
                                                 << 0x1cU) 
                                                | (((IData)(vlSelfRef.gpio1_i) 
                                                    << 0x18U) 
                                                   | (((IData)(vlSelfRef.gpio1_i) 
                                                       << 0x14U) 
                                                      | (((IData)(vlSelfRef.gpio1_i) 
                                                          << 0x10U) 
                                                         | (((IData)(vlSelfRef.gpio1_i) 
                                                             << 0xcU) 
                                                            | (((IData)(vlSelfRef.gpio1_i) 
                                                                << 8U) 
                                                               | (((IData)(vlSelfRef.gpio1_i) 
                                                                   << 4U) 
                                                                  | (IData)(vlSelfRef.gpio1_i)))))))))) 
                               << 8U) | (QData)((IData)(
                                                        (0xffU 
                                                         & ((0xf0U 
                                                             & ((~ (IData)(vlSelfRef.gpio1_i)) 
                                                                << 4U)) 
                                                            | (0xfU 
                                                               & (~ (IData)(vlSelfRef.gpio1_i))))))))),40);
    bufp->fullIData(oldp+93,((0xffffffU & (((IData)(vlSelfRef.gpio1_i) 
                                            << 0x14U) 
                                           | (((IData)(vlSelfRef.gpio1_i) 
                                               << 0x10U) 
                                              | (((IData)(vlSelfRef.gpio1_i) 
                                                  << 0xcU) 
                                                 | (((IData)(vlSelfRef.gpio1_i) 
                                                     << 8U) 
                                                    | (((IData)(vlSelfRef.gpio1_i) 
                                                        << 4U) 
                                                       | (IData)(vlSelfRef.gpio1_i)))))))),24);
    bufp->fullSData(oldp+94,(((0xff00U & (((IData)(vlSelfRef.gpio1_i) 
                                           << 0xcU) 
                                          | ((IData)(vlSelfRef.gpio1_i) 
                                             << 8U))) 
                              | (0xffU & ((0xf0U & 
                                           ((~ (IData)(vlSelfRef.gpio1_i)) 
                                            << 4U)) 
                                          | (0xfU & 
                                             (~ (IData)(vlSelfRef.gpio1_i))))))),16);
    bufp->fullBit(oldp+95,(vlSelfRef.toplevel__DOT__dnano_interfacei__DOT__dbl_clck_rst_n));
    bufp->fullBit(oldp+96,((1U & (~ (IData)(vlSelfRef.btn_n_pad_i)))));
}
