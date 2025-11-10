// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary model header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef VERILATED_VTOPLEVEL_H_
#define VERILATED_VTOPLEVEL_H_  // guard

#include "verilated.h"

class Vtoplevel__Syms;
class Vtoplevel___024root;
class VerilatedVcdC;

// This class is the main interface to the Verilated model
class alignas(VL_CACHE_LINE_BYTES) Vtoplevel VL_NOT_FINAL : public VerilatedModel {
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
    VL_IN8(&sys_clk_pad_i,0,0);
    VL_IN8(&rst_n_pad_i,0,0);
    VL_IN8(&btn_n_pad_i,0,0);
    VL_OUT8(&sdram_ba_pad_o,1,0);
    VL_OUT8(&sdram_cs_n_pad_o,0,0);
    VL_OUT8(&sdram_ras_pad_o,0,0);
    VL_OUT8(&sdram_cas_pad_o,0,0);
    VL_OUT8(&sdram_we_pad_o,0,0);
    VL_OUT8(&sdram_dqm_pad_o,1,0);
    VL_OUT8(&sdram_cke_pad_o,0,0);
    VL_OUT8(&sdram_clk_pad_o,0,0);
    VL_INOUT8(&gpio0_io,7,0);
    VL_IN8(&gpio1_i,3,0);
    VL_OUT16(&sdram_a_pad_o,12,0);
    VL_INOUT16(&sdram_dq_pad_io,15,0);

    // CELLS
    // Public to allow access to /* verilator public */ items.
    // Otherwise the application code can consider these internals.

    // Root instance pointer to allow access to model internals,
    // including inlined /* verilator public_flat_* */ items.
    Vtoplevel___024root* const rootp;

    // CONSTRUCTORS
    /// Construct the model; called by application code
    /// If contextp is null, then the model will use the default global context
    /// If name is "", then makes a wrapper with a
    /// single model invisible with respect to DPI scope names.
    explicit Vtoplevel(VerilatedContext* contextp, const char* name = "TOP");
    explicit Vtoplevel(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    virtual ~Vtoplevel();
  private:
    VL_UNCOPYABLE(Vtoplevel);  ///< Copying not allowed

  public:
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    /// Are there scheduled events to handle?
    bool eventsPending();
    /// Returns time at next time slot. Aborts if !eventsPending()
    uint64_t nextTimeSlot();
    /// Trace signals in the model; called by application code
    void trace(VerilatedTraceBaseC* tfp, int levels, int options = 0) { contextp()->trace(tfp, levels, options); }
    /// Retrieve name of this model instance (as passed to constructor).
    const char* name() const;

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
