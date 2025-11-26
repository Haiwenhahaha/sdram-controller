单纯有个txt方便建文件夹
方便交流

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
