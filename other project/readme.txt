单纯有个txt方便建文件夹
方便交流

V3

    rand sdram_cmd_e      cmd;
                   |
xmvlog: *E,PKGDOCU (../sdram/sdram_pkg.sv,10|19): SV package not allowed to access items declared in Compilation unit scope.
    uvm_analysis_port#(sdram_rsp_t) rsp_ap;
                                 |
xmvlog: *E,PKGDOCU (../sdram/sdram_pkg.sv,92|33): SV package not allowed to access items declared in Compilation unit scope.
      sdram_rsp_t rsp;
                |
xmvlog: *E,PKGDOCU (../sdram/sdram_pkg.sv,100|16): SV package not allowed to access items declared in Compilation unit scope.
      seq.randomize() with { num_txns == 4; };
                  |
xmvlog: *W,FUNTSK (../sdram/sdram_pkg.sv,178|18): function called as a task without void'().
  import sdram_pkg::*;
                 |
xmvlog: *E,NOPBIND (../sdram/sdram_tb_top.sv,8|17): Package sdram_pkg could not be bound.
xrun: *E,VLGERR: An error occurred during parsing.  Review the log file for errors with the code *E and fix those identified problems to proceed.  Exiting with code (status 1).




V2
Generating SDRAM DPI headers
xmvlog: *W,SPDUSD: Include directory .. given but not used.
        Top level design units:
                $unit_0x2b178cf3
                uvm_pkg
                cdns_uvmapi
                cdns_assert2uvm_pkg
                cdns_uvm_pkg
                sdram_model_if
xrun: *W,BADPRF: The -linedebug option may have an adverse performance impact.
xrun: *W,CSSF: HDL source files with -R option will be ignored.
xrun: *E,NOSTUP: A problem was detected in the setup for simulation. Simulation can be done only after successfully completing design file parsing and elaboration. Check the command line for any unintentional errors, like the omission of the -name or the -xmlibdirname option or the -xmlibdirpath option, if these were used for parsing earlier.


Environment Modules used! Type  "module av" to show all available modules.
Loading analog_design/ad_ic_ncls
  Loading requirement: VIRTUOSO_CONF/DEFAULT useful_alias_def CALIBRE/aoi_cal_2019.1_18.11 PVS/16.1
    ASSURA/4.15.111-617_lnx86 SPECTRE/23.1 EXT/18.2 IC/6.1.8 SSV/18.1 LIBERATE/17.1
Loading digital_design/dd_ncls
  Loading requirement: INCISIVE/EMPTY XCELIUM/24.09.004 VMANAGER/24.09.001 CONFORMAL/18.2 GENUS/21.1
    INNOVUS/18.1 QUARTUS/21.1 XILINX_LIC/CLS VIVADO/2023.2 QUESTA/2023.3_2 SYNPLIFY/N-2018.03-SP1
    IDENTIFY/N-2018.03-SP1 SPYGLASS/S-2021.09-SP2 DIAMOND/3.12 RADIANT/2022.1
 Start testbench...
/sw/CDS/XCELIUM_24_09_004/tools/bin/xmsc_run
/sw/CDS/XCELIUM_24_09_004/tools/bin/xrun
Generating SDRAM DPI headers
xmvlog: *W,SPDUSD: Include directory .. given but not used.
        Top level design units:
                $unit_0x2b178cf3
                uvm_pkg
                cdns_uvmapi
                cdns_assert2uvm_pkg
                cdns_uvm_pkg
                sdram_model_if
xrun: *W,BADPRF: The -linedebug option may have an adverse performance impact.
xrun: *W,CSSF: HDL source files with -R option will be ignored.
xrun: *E,NOSTUP: A problem was detected in the setup for simulation. Simulation can be done only after successfully completing design file parsing and elaboration. Check the command line for any unintentional errors, like the omission of the -name or the -xmlibdirname option or the -xmlibdirpath option, if these were used for parsing earlier.










V1
# C++ search paths (for C++ files)
-I../sdram
-I../sim
-I../sc-standalone
-I../sc-standalone/verilator_include
-I.

# SystemVerilog include paths (for `include statements)
# Note: +incdir is for SystemVerilog, -I is for C++
+incdir+../sdram
+incdir+..
+incdir+.

-scautoshell verilog
-scautoshell SYSTEMC

V1
xmvlog: *E,COFILX (../sdram/sdram_model_if.sv,5|31): cannot open include file 'sdram/sdram_types.svh'.
  mailbox #(sdram_rsp_t) rsp_mbx = new();
                      |
xmvlog: *E,SVNOTY (../sdram/sdram_model_if.sv,11|22): Syntactically this identifier appears to begin a datatype but it does not refer to a visible datatype in the current scope.
    sdram_cmd_e      cmd,
              |
xmvlog: *E,SVNOTY (../sdram/sdram_model_if.sv,43|14): Syntactically this identifier appears to begin a datatype but it does not refer to a visible datatype in the current scope.
  task automatic wait_for_response(output sdram_rsp_t rsp);
                                                    |
xmvlog: *E,SVNOTY (../sdram/sdram_model_if.sv,69|52): Syntactically this identifier appears to begin a datatype but it does not refer to a visible datatype in the current scope.
    sdram_rsp_t rsp;
              |
xmvlog: *E,NOIPRT (../sdram/sdram_model_if.sv,79|14): Unrecognized declaration 'sdram_rsp_t' could be an unsupported keyword, a spelling mistake or missing instance port list '()' [SystemVerilog].
    sdram_rsp_t rsp;
              |
xmvlog: *E,NOTINF (../sdram/sdram_model_if.sv,79|14): Interfaces are not allowed within tasks [SystemVerilog].
    sdram_rsp_t rsp;
                  |
xmvlog: *E,ILLPDL (../sdram/sdram_model_if.sv,79|18): Mixing of ansi & non-ansi style port declaration is not legal.
    rsp.addr      = addr;
      |
xmvlog: *E,EXPRPA (../sdram/sdram_model_if.sv,80|6): expecting a right parenthesis (')') [A.2.6(IEEE)].
xmvlog: *W,NOTOPL: no top-level unit found, must have recursive instances.
xrun: *E,VLGERR: An error occurred during parsing.  Review the log file for errors with the code *E and fix those identified problems to proceed.  Exiting with code (status 1).
xrun: *W,BADPRF: The -linedebug option may have an adverse performance impact.
xrun: *W,CSSF: HDL source files with -R option will be ignored.
xrun: *E,NOSTUP: A problem was detected in the setup for simulation. Simulation can be done only after successfully completing design file parsing and elaboration. Check the command line for any unintentional errors, like the omission of the -name or the -xmlibdirname option or the -xmlibdirpath option, if these were used for parsing earlier.
