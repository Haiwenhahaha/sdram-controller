#!/usr/bin/env bash

# run_verilator.sh 

set -euo pipefail

# Defaults (can be overridden by CLI options or environment variables)

TOP=${TOP:-toplevel}
FILES=${FILES:-files.rtl.f}
CPP_TB=${CPP_TB:-sim/c_main.cpp}
MDIR_CPP=${MDIR_CPP:-build/cpp}
MDIR_SC=${MDIR_SC:-build/sc}
WAVE=${WAVE:-${MDIR_CPP}/wave_verilator.vcd}
JOBS=${JOBS:-0}
DO_SC=0
DO_RUN=0
DO_WAVE=0

usage() {
  cat <<EOF
Usage: $0 [-t TOP] [-f FILELIST] [-e CPP_TB] [-j JOBS] [-s] [-r] [-w]
  -t  Top module name (default: ${TOP})
  -f  RTL file list (default: ${FILES})
  -e  C++ testbench file (default: ${CPP_TB})
  -j  Build parallel jobs (default: ${JOBS}, 0=all cores)
  -s  generate SystemC model
  -r  Run simulation after build
  -w  Open waveform with GTKWave after run (${WAVE})
Examples:
	./run_verilator.sh -e sim/c_main.cpp -r -w
Note:
  Verilator uses --top-module (not --top).
EOF
}
# Environment variables:
#   VERILATOR_FLAGS  Extra flags appended to verilator
#   MDIR_CPP/MDIR_SC Override output directories
#   WAVE             Override waveform file path
# Examples:
# ./run_verilator.sh -e sim/c_main.cpp -r -w
#   $0 -t toplevel -f files.rtl.f -e sim/c_main.cpp -r -w


while getopts ":t:f:e:j:srwh" opt; do
  case $opt in
    t) TOP="$OPTARG" ;;
    f) FILES="$OPTARG" ;;
    e) CPP_TB="$OPTARG" ;;
    j) JOBS="$OPTARG" ;;
    s) DO_SC=1 ;;
    r) DO_RUN=1 ;;
    w) DO_WAVE=1 ;;
    h) usage; exit 0 ;;
    \?) echo "Unknown option: -$OPTARG"; usage; exit 2 ;;
  esac
done

# 0) Basic checks and setup

command -v verilator >/dev/null 2>&1 || { echo "Error: verilator not found in PATH"; exit 1; }
[[ -f "$FILES" ]] || { echo "Error: file list not found: $FILES"; exit 1; }
[[ -f "$CPP_TB" ]] || { echo "Error: C++ testbench not found: $CPP_TB"; exit 1; }

mkdir -p "$MDIR_CPP" "$MDIR_SC"


if [[ $DO_SC -eq 1 ]]; then
#	echo "==> 1/4 Generate C++ model"
#	verilator -cc \
#	  --top "$TOP" \
#	  -f "$FILES" \
#	  -Wall --trace \
#	  --Mdir "$MDIR_CPP" \
#	  ${VERILATOR_FLAGS:-}
#	  
#else
  echo "==>  Generate SystemC model"
  verilator -sc \
    --top "$TOP" \
    -f "$FILES" \
    -Wall --trace \
    --Mdir "$MDIR_SC" \
    ${VERILATOR_FLAGS:-}
fi


echo "==>  Build and link C++ executable"
#verilator -cc --top toplevel -f files.rtl.f -Wall --trace --Mdir build/cpp --build --exe -j 0 sim/c_main.cpp
verilator -cc \
  --top "$TOP" \
  -f "$FILES" \
  -Wall --trace \
  --Mdir "$MDIR_CPP" \
  --build --exe -j "$JOBS" "$CPP_TB" \
  ${VERILATOR_FLAGS:-}

exe="${MDIR_CPP}/V${TOP}"

if [[ $DO_RUN -eq 1 ]]; then
  echo "==>  Run simulation: $exe"
  "$exe"
fi

if [[ $DO_WAVE -eq 1 ]]; then
  if command -v gtkwave >/dev/null 2>&1; then
    if [[ -f "$WAVE" ]]; then
      echo "==> Open waveform: $WAVE"
      gtkwave "$WAVE" &
    else
      echo "Hint: Waveform file not found: $WAVE. Check your testbench's VCD path or set WAVE env var."
    fi
  else
    echo "Hint: gtkwave not found. Install it to view waveform: $WAVE"
  fi
fi

echo "Done. Executable: $exe"
