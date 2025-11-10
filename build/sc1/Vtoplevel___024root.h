// Verilated -*- SystemC -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtoplevel.h for the primary calling header

#ifndef VERILATED_VTOPLEVEL___024ROOT_H_
#define VERILATED_VTOPLEVEL___024ROOT_H_  // guard

#include "systemc"
#include "verilated_sc.h"
#include "verilated.h"


class Vtoplevel__Syms;		// 前向声明：符号表类
// 根模块类，按缓存行对齐，继承 VerilatedModule
class alignas(VL_CACHE_LINE_BYTES) Vtoplevel___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ __Vcellinp__toplevel__sys_clk_pad_i;
        CData/*0:0*/ toplevel__DOT__clk1m;                 // 1位：内部1MHz时钟（示例命名）
        CData/*3:0*/ __Vcellinp__toplevel__gpio1_i;        // 4位：缓存的 gpio1_i 输入低4位
        CData/*7:0*/ __Vcellinpt__toplevel__gpio0_io;      // 8位：缓存的 gpio0_io（双向）低8位
        CData/*0:0*/ __Vcellinp__toplevel__btn_n_pad_i;    // 1位：缓存的按键输入
        CData/*0:0*/ __Vcellinp__toplevel__rst_n_pad_i;    // 1位：缓存的复位输入（低有效）
        CData/*0:0*/ toplevel__DOT__wr_enable;             // 1位：内部写使能
        CData/*0:0*/ toplevel__DOT__ctrl_busy;             // 1位：内部控制忙标志
        CData/*0:0*/ toplevel__DOT__rd_enable;             // 1位：内部读使能
        CData/*0:0*/ toplevel__DOT__wr_fifoi__DOT__wr_r;   // 1位：写FIFO域内寄存/标志
        CData/*0:0*/ toplevel__DOT__wr_fifoi__DOT__wr_syn1;// 1位：CDC同步级1（写域）
        CData/*0:0*/ toplevel__DOT__wr_fifoi__DOT__wr_syn2;// 1位：CDC同步级2（写域）
        CData/*0:0*/ toplevel__DOT__wr_fifoi__DOT__wr_ack1;// 1位：写ACK同步1
        CData/*0:0*/ toplevel__DOT__wr_fifoi__DOT__wr_ack2;// 1位：写ACK同步2
        CData/*0:0*/ toplevel__DOT__wr_fifoi__DOT__rd_r;   // 1位：读侧寄存到写侧
        CData/*0:0*/ toplevel__DOT__wr_fifoi__DOT__rd_syn1;// 1位：读->写同步1
        CData/*0:0*/ toplevel__DOT__wr_fifoi__DOT__rd_syn2;// 1位：读->写同步2
        CData/*0:0*/ toplevel__DOT__wr_fifoi__DOT__rd_ack1;// 1位：读ACK同步1
        CData/*0:0*/ toplevel__DOT__wr_fifoi__DOT__rd_ack2;// 1位：读ACK同步2
        CData/*0:0*/ toplevel__DOT__wr_fifoi__DOT__wr_fifo_cnt; // 1位：写FIFO计数（低位/标志）
        CData/*0:0*/ toplevel__DOT__wr_fifoi__DOT__rd_fifo_cnt; // 1位：读FIFO计数（低位/标志）
        CData/*0:0*/ toplevel__DOT__rdaddr_fifoi__DOT__wr_r;    // 1位：读地址FIFO写侧寄存
        CData/*0:0*/ toplevel__DOT__rdaddr_fifoi__DOT__wr_syn1; // 1位：CDC同步1（写侧）
        CData/*0:0*/ toplevel__DOT__rdaddr_fifoi__DOT__wr_syn2; // 1位：CDC同步2（写侧）
        CData/*0:0*/ toplevel__DOT__rdaddr_fifoi__DOT__wr_ack1; // 1位：写ACK同步1
        CData/*0:0*/ toplevel__DOT__rdaddr_fifoi__DOT__wr_ack2; // 1位：写ACK同步2
        CData/*0:0*/ toplevel__DOT__rdaddr_fifoi__DOT__rd_r;    // 1位：读侧寄存
        CData/*0:0*/ toplevel__DOT__rdaddr_fifoi__DOT__rd_syn1; // 1位：读侧CDC同步1
        CData/*0:0*/ toplevel__DOT__rdaddr_fifoi__DOT__rd_syn2; // 1位：读侧CDC同步2
        CData/*0:0*/ toplevel__DOT__rdaddr_fifoi__DOT__rd_ack1; // 1位：读ACK同步1
        CData/*0:0*/ toplevel__DOT__rdaddr_fifoi__DOT__rd_ack2; // 1位：读ACK同步2
        CData/*0:0*/ toplevel__DOT__rdaddr_fifoi__DOT__wr_fifo_cnt;// 1位：写计数低位/标志
        CData/*0:0*/ toplevel__DOT__rdaddr_fifoi__DOT__rd_fifo_cnt;// 1位：读计数低位/标志
        CData/*0:0*/ toplevel__DOT__rddata_fifoi__DOT__wr_r;     // 1位：读数据FIFO写侧寄存
        CData/*0:0*/ toplevel__DOT__rddata_fifoi__DOT__wr_syn1;  // 1位：CDC同步1
        CData/*0:0*/ toplevel__DOT__rddata_fifoi__DOT__wr_syn2;  // 1位：CDC同步2
        CData/*0:0*/ toplevel__DOT__rddata_fifoi__DOT__wr_ack1;  // 1位：写ACK同步1
        CData/*0:0*/ toplevel__DOT__rddata_fifoi__DOT__wr_ack2;  // 1位：写ACK同步2
        CData/*0:0*/ toplevel__DOT__rddata_fifoi__DOT__rd_r;     // 1位：读侧寄存
        CData/*0:0*/ toplevel__DOT__rddata_fifoi__DOT__rd_syn1;  // 1位：读侧CDC同步1
        CData/*0:0*/ toplevel__DOT__rddata_fifoi__DOT__rd_syn2;  // 1位：读侧CDC同步2
        CData/*0:0*/ toplevel__DOT__rddata_fifoi__DOT__rd_ack1;  // 1位：读ACK同步1
        CData/*0:0*/ toplevel__DOT__rddata_fifoi__DOT__rd_ack2;  // 1位：读ACK同步2
        CData/*0:0*/ toplevel__DOT__rddata_fifoi__DOT__wr_fifo_cnt;// 1位：写计数低位/标志
        CData/*0:0*/ toplevel__DOT__rddata_fifoi__DOT__rd_fifo_cnt;// 1位：读计数低位/标志
        CData/*1:0*/ toplevel__DOT__sdram_controlleri__DOT__bank_addr_r; // 2位：SDRAM bank 地址寄存
        CData/*0:0*/ toplevel__DOT__sdram_controlleri__DOT__rd_ready_r;  // 1位：SDRAM 读就绪
        CData/*3:0*/ toplevel__DOT__sdram_controlleri__DOT__state_cnt;   // 4位：状态计数
        CData/*7:0*/ toplevel__DOT__sdram_controlleri__DOT__command;     // 8位：当前命令编码
        CData/*4:0*/ toplevel__DOT__sdram_controlleri__DOT__state;       // 5位：控制器状态
        CData/*7:0*/ toplevel__DOT__sdram_controlleri__DOT__command_nxt; // 8位：下一命令
        CData/*3:0*/ toplevel__DOT__sdram_controlleri__DOT__state_cnt_nxt;// 4位：下一状态计数
        CData/*4:0*/ toplevel__DOT__sdram_controlleri__DOT__next;        // 5位：状态机 next
        CData/*0:0*/ toplevel__DOT__dnano_interfacei__DOT__rd_ack_r;     // 1位：接口读应答
        CData/*0:0*/ toplevel__DOT__dnano_interfacei__DOT__dbl_clck_rst_n;// 1位：双击逻辑复位
        CData/*0:0*/ toplevel__DOT__dnano_interfacei__DOT__double_clicki__DOT__btn_now;// 1位：当前按键
        CData/*0:0*/ toplevel__DOT__dnano_interfacei__DOT__double_clicki__DOT__btn_last;// 1位：上次按键
        CData/*0:0*/ toplevel__DOT__dnano_interfacei__DOT__double_clicki__DOT__collect;// 1位：收集窗口使能
        CData/*2:0*/ toplevel__DOT__dnano_interfacei__DOT__double_clicki__DOT__click_cnt;// 3位：点击计数
        CData/*0:0*/ toplevel__DOT__dnano_interfacei__DOT__double_clicki__DOT__btn_down;// 1位：按下沿检测
        CData/*0:0*/ __Vdly__toplevel__DOT__wr_fifoi__DOT__wr_syn2;      // 1位：wr_syn2 的“下一值”
        CData/*0:0*/ __Vdly__toplevel__DOT__rdaddr_fifoi__DOT__wr_syn2;  // 1位：rdaddr wr_syn2 下一值
        CData/*0:0*/ __Vdly__toplevel__DOT__rddata_fifoi__DOT__rd_syn2;  // 1位：rddata rd_syn2 下一值
        CData/*0:0*/ __Vdly__toplevel__DOT__wr_fifoi__DOT__rd_syn2;      // 1位：wr_fifo rd_syn2 下一值
    };
    struct {
        CData/*0:0*/ __Vdly__toplevel__DOT__rdaddr_fifoi__DOT__rd_syn2;  // 1位：rdaddr rd_syn2 下一值
        CData/*0:0*/ __Vdly__toplevel__DOT__rddata_fifoi__DOT__wr_syn2;  // 1位：rddata wr_syn2 下一值
        CData/*0:0*/ __VstlFirstIteration;                               // 1位：settle区域首次迭代标志
        CData/*0:0*/ __VicoFirstIteration;                               // 1位：initial-comb区域首次迭代标志
        CData/*0:0*/ __Vtrigprevexpr___TOP____Vcellinp__toplevel__sys_clk_pad_i__0; // 1位：上次时钟值（边沿检测）
        CData/*0:0*/ __Vtrigprevexpr___TOP__toplevel__DOT__clk1m__0;     // 1位：上次内部1MHz时钟值
        CData/*0:0*/ __VactContinue;                                     // 1位：active区域是否需继续迭代
        SData/*15:0*/ __Vcellinpt__toplevel__sdram_dq_pad_io;            // 16位：缓存的 SDRAM 数据线低16位
        SData/*15:0*/ toplevel__DOT__rddata_fifo;                        // 16位：读数据FIFO输出
        SData/*15:0*/ toplevel__DOT__rddata_fifoi__DOT__wr_data_r;       // 16位：读数据FIFO写侧数据寄存
        SData/*15:0*/ toplevel__DOT__sdram_controlleri__DOT__wr_data_r;  // 16位：SDRAM写数据寄存
        SData/*15:0*/ toplevel__DOT__sdram_controlleri__DOT__rd_data_r;  // 16位：SDRAM读数据寄存
        SData/*12:0*/ toplevel__DOT__sdram_controlleri__DOT__addr_r;     // 13位：SDRAM地址寄存
        SData/*9:0*/ toplevel__DOT__sdram_controlleri__DOT__refresh_cnt; // 10位：刷新计数器
        SData/*15:0*/ toplevel__DOT__dnano_interfacei__DOT__rd_data_r;   // 16位：接口读数据寄存
        IData/*23:0*/ toplevel__DOT__rdao_fifo;                          // 24位：读地址输出FIFO（打包）
        IData/*31:0*/ toplevel__DOT__pll_1mi__DOT__cnt;                  // 32位：分频/PLL 1MHz计数器
        IData/*23:0*/ toplevel__DOT__rdaddr_fifoi__DOT__wr_data_r;       // 24位：读地址FIFO写侧数据寄存
        IData/*23:0*/ toplevel__DOT__sdram_controlleri__DOT__haddr_r;    // 24位：高位地址寄存
        IData/*19:0*/ toplevel__DOT__dnano_interfacei__DOT__led_cnt;     // 20位：LED节拍计数
        IData/*18:0*/ toplevel__DOT__dnano_interfacei__DOT__double_clicki__DOT__dbl_click_cnt;// 19位：双击时间窗口计数
        IData/*31:0*/ __VactIterCount;                                   // 32位：active区域迭代计数（调试/防死循环）
        QData/*39:0*/ toplevel__DOT__wro_fifo;                           // 40位：写数据输出FIFO（打包）
        QData/*39:0*/ toplevel__DOT__wr_fifoi__DOT__wr_data_r;           // 40位：写FIFO写侧数据寄存
        VlUnpacked<CData/*0:0*/, 7> __Vm_traceActivity;                   // 7组迹波活动标志
    };
    sc_core::sc_in<bool> sys_clk_pad_i;           // SystemC端口：输入时钟
    sc_core::sc_in<bool> rst_n_pad_i;             // SystemC端口：低有效复位
    sc_core::sc_in<bool> btn_n_pad_i;             // SystemC端口：按键输入（低有效）
    sc_core::sc_out<uint32_t> sdram_ba_pad_o;     // 输出：SDRAM bank地址（外部声明为32位，内部只用低位）
    sc_core::sc_out<bool> sdram_cs_n_pad_o;       // 输出：SDRAM CS#（片选）
    sc_core::sc_out<bool> sdram_ras_pad_o;        // 输出：SDRAM RAS#
    sc_core::sc_out<bool> sdram_cas_pad_o;        // 输出：SDRAM CAS#
    sc_core::sc_out<bool> sdram_we_pad_o;         // 输出：SDRAM WE#
    sc_core::sc_out<uint32_t> sdram_dqm_pad_o;    // 输出：SDRAM DQM（掩码）
    sc_core::sc_out<bool> sdram_cke_pad_o;        // 输出：SDRAM CKE
    sc_core::sc_out<bool> sdram_clk_pad_o;        // 输出：SDRAM 时钟
    sc_core::sc_inout<uint32_t> gpio0_io;         // 双向：GPIO0（外部32位，内部可能部分使用）
    sc_core::sc_in<uint32_t> gpio1_i;             // 输入：GPIO1
    sc_core::sc_out<uint32_t> sdram_a_pad_o;      // 输出：SDRAM 地址
    sc_core::sc_inout<uint32_t> sdram_dq_pad_io;  // 双向：SDRAM 数据
    VlTriggerVec<1> __VstlTriggered;              // settle区域触发向量
    VlTriggerVec<1> __VicoTriggered;              // initial-comb区域触发向量
    VlTriggerVec<3> __VactTriggered;              // active区域触发向量（最多3类触发）
    VlTriggerVec<3> __VnbaTriggered;              // 非阻塞赋值区域触发向量

    // INTERNAL VARIABLES
    Vtoplevel__Syms* const vlSymsp;               // 指向符号表（上下文/状态容器）

    // CONSTRUCTORS
    Vtoplevel___024root(Vtoplevel__Syms* symsp, const char* v__name); // 构造：由符号表与实例名初始化
    ~Vtoplevel___024root();                        // 析构：释放内部资源（按成员自动析构）
    VL_UNCOPYABLE(Vtoplevel___024root);            // 禁止拷贝/赋值

    // INTERNAL METHODS
    void __Vconfigure(bool first);                 // 内部配置：建立回指、初始化公开项；first指示是否首次配置
};


#endif  // guard
