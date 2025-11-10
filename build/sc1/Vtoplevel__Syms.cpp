// Verilated -*- SystemC -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtoplevel__pch.h"// 预编译头（聚合常用生成文件）
#include "Vtoplevel.h"
#include "Vtoplevel___024root.h"

// FUNCTIONS
Vtoplevel__Syms::~Vtoplevel__Syms()
{
}	// 空析构：资源由成员自身管理（如 TOP 自动析构）

Vtoplevel__Syms::Vtoplevel__Syms(VerilatedContext* contextp, const char* namep, Vtoplevel* modelp)
    : VerilatedSyms{contextp}                     // 基类 VerilatedSyms 构造，保存上下文
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}                         // 保存模型指针（供回调/互访）
    // Setup module instances
    , TOP{this, namep}                            // 构造根模块 TOP，传入符号表指针与实例名
{
        // Check resources
        Verilated::stackCheck(35);                // 运行时栈检查（调试/健壮性）
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);                // 设置仿真时间单位为 10^-12 秒（ps）
    _vm_contextp__->timeprecision(-12);           // 设置仿真时间精度为 10^-12 秒（ps）
    // Setup each module's pointers to their submodules
                                                  // 若有子模块，这里通常会建立指针关系（本例由 root 管理）
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);                       // 配置根模块：建立回指到符号表、完成公开项配置
}