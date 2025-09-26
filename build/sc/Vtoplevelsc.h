// Verilated -*- SystemC -*-
// DESCRIPTION: Verilator output: Primary model header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef VERILATED_VTOPLEVEL_H_
#define VERILATED_VTOPLEVEL_H_  // guard

#include "systemc"
#include "verilated_sc.h"
#include "verilated.h"

class Vtoplevel__Syms;
class Vtoplevel___024root;
class VerilatedVcdSc;

// This class is the main interface to the Verilated model
class alignas(VL_CACHE_LINE_BYTES) Vtoplevel VL_NOT_FINAL : public ::sc_core::sc_module, public VerilatedModel {
  private:
    // Symbol table holding complete model state (owned by this class)
    Vtoplevel__Syms* const vlSymsp;

  public:

    // CONSTEXPR CAPABILITIES
    // Verilated with --trace?
    static constexpr bool traceCapable = true;

    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    sc_core::sc_in<bool> &sys_clk_pad_i;
    sc_core::sc_in<bool> &rst_n_pad_i;
    sc_core::sc_in<bool> &btn_n_pad_i;
    sc_core::sc_out<uint32_t> &sdram_ba_pad_o;
    sc_core::sc_out<bool> &sdram_cs_n_pad_o;
    sc_core::sc_out<bool> &sdram_ras_pad_o;
    sc_core::sc_out<bool> &sdram_cas_pad_o;
    sc_core::sc_out<bool> &sdram_we_pad_o;
    sc_core::sc_out<uint32_t> &sdram_dqm_pad_o;
    sc_core::sc_out<bool> &sdram_cke_pad_o;
    sc_core::sc_out<bool> &sdram_clk_pad_o;
    sc_core::sc_inout<uint32_t> &gpio0_io;
    sc_core::sc_in<uint32_t> &gpio1_i;
    sc_core::sc_out<uint32_t> &sdram_a_pad_o;
    sc_core::sc_inout<uint32_t> &sdram_dq_pad_io;

    // CELLS
    // Public to allow access to /* verilator public */ items.
    // Otherwise the application code can consider these internals.

    // Root instance pointer to allow access to model internals,
    // including inlined /* verilator public_flat_* */ items.
    Vtoplevel___024root* const rootp;

    // CONSTRUCTORS
    SC_CTOR(Vtoplevel);
    virtual ~Vtoplevel();
  private:
    VL_UNCOPYABLE(Vtoplevel);  ///< Copying not allowed

  public:
    // API METHODS
  private:
    void eval() { eval_step(); }
    void eval_step();
  public:
    void final();
    /// Are there scheduled events to handle?
    bool eventsPending();
    /// Returns time at next time slot. Aborts if !eventsPending()
    uint64_t nextTimeSlot();
    /// Trace signals in the model; called by application code
    void trace(VerilatedTraceBaseC* tfp, int levels, int options = 0) { contextp()->trace(tfp, levels, options); }
    /// SC tracing; avoid overloaded virtual function lint warning
    void trace(sc_core::sc_trace_file* tfp) const override { ::sc_core::sc_module::trace(tfp); }

    // Abstract methods from VerilatedModel
    const char* hierName() const override final;
    const char* modelName() const override final;
    unsigned threads() const override final;
    /// Prepare for cloning the model at the process level (e.g. fork in Linux)
    /// Release necessary resources. Called before cloning.
    void prepareClone() const;
    /// Re-init after cloning the model at the process level (e.g. fork in Linux)
    /// Re-allocate necessary resources. Called after cloning.
    void atClone() const;
    std::unique_ptr<VerilatedTraceConfig> traceConfig() const override final;
  private:
    // Internal functions - trace registration
    void traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options);
};

#endif  // guard
