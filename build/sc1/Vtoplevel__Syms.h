// Verilated -*- SystemC -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VTOPLEVEL__SYMS_H_
#define VERILATED_VTOPLEVEL__SYMS_H_  // guard

#include "systemc"
#include "verilated_sc.h"
#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vtoplevel.h"	

// INCLUDE MODULE CLASSES
#include "Vtoplevel___024root.h"		// 引入顶层根模块类（实际电路实现类）

// SYMS CLASS (contains all model state)	
class alignas(VL_CACHE_LINE_BYTES)Vtoplevel__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vtoplevel* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vtoplevel___024root            TOP;	// 根模块实例（包含所有端口/内部信号/子模块）

    // CONSTRUCTORS
    Vtoplevel__Syms(VerilatedContext* contextp, const char* namep, Vtoplevel* modelp);// 构造函数：传入上下文、实例名、模型指针
    ~Vtoplevel__Syms();

    // METHODS
    const char* name() { return TOP.name(); }// 返回根实例名（供外部查询层级名）
};

#endif  // guard
