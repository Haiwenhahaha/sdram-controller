# SDRAM 控制器测试平台编译和运行指南

## 概述

本指南介绍如何编译和运行 SDRAM 控制器的 Verilator 测试平台。项目包含多个测试文件，每个都有不同的特点和用途。

## 文件说明

### 原始文件
- `sc_main.cpp` - 基础 SystemC 测试文件（简单版本）
- `sc_main2.cpp` - SystemC 测试文件（有波形输出）
- `sim_main.cpp` - 纯 Verilator C++ 测试文件

### 改进文件
- `sc_main2_improved.cpp` - 改进的 SystemC 测试文件
- `sim_main_improved.cpp` - 改进的纯 Verilator 测试文件
- `advanced_testbench.cpp` - 高级测试平台（完整测试套件）

## 环境要求

### 必需软件
1. **Verilator** (版本 4.0 或更高)
   ```bash
   # Ubuntu/Debian
   sudo apt-get install verilator
   
   # CentOS/RHEL
   sudo yum install verilator
   
   # 从源码编译（推荐）
   git clone https://github.com/verilator/verilator.git
   cd verilator
   autoconf && ./configure && make && sudo make install
   ```

2. **SystemC** (仅 SystemC 版本需要)
   ```bash
   # Ubuntu/Debian
   sudo apt-get install libsystemc-dev
   
   # 从源码编译
   wget https://www.accellera.org/images/downloads/standards/systemc/systemc-2.3.3.tgz
   tar -xzf systemc-2.3.3.tgz
   cd systemc-2.3.3
   mkdir build && cd build
   ../configure --prefix=/usr/local
   make && sudo make install
   ```

3. **C++ 编译器** (GCC 7.0 或更高，或 Clang)
   ```bash
   # Ubuntu/Debian
   sudo apt-get install build-essential
   
   # CentOS/RHEL
   sudo yum groupinstall "Development Tools"
   ```

4. **GTKWave** (用于查看波形)
   ```bash
   # Ubuntu/Debian
   sudo apt-get install gtkwave
   
   # CentOS/RHEL
   sudo yum install gtkwave
   ```

## 编译步骤

### 步骤 1: 生成 Verilator 模型

首先需要从 Verilog 文件生成 C++ 模型：

```bash
# 生成纯 C++ 模型
verilator --cc --exe --build --trace \
    --top-module toplevel \
    toplevel.v sdram_controller.v fifo.v dnano_interface.v double_click.v \
    sim_main.cpp

# 生成 SystemC 模型
verilator --sc --exe --build --trace \
    --top-module toplevel \
    toplevel.v sdram_controller.v fifo.v dnano_interface.v double_click.v \
    sc_main2.cpp
```

### 步骤 2: 编译改进版本

#### 编译纯 Verilator 改进版本
```bash
# 生成模型
verilator --cc --exe --build --trace \
    --top-module toplevel \
    toplevel.v sdram_controller.v fifo.v dnano_interface.v double_click.v \
    sim_main_improved.cpp

# 或者手动编译
verilator --cc --trace toplevel.v sdram_controller.v fifo.v dnano_interface.v double_click.v
cd obj_dir
make -f Vtoplevel.mk
g++ -I/usr/share/verilator/include \
    -I/usr/share/verilator/include/vltstd \
    -I./obj_dir \
    sim_main_improved.cpp \
    obj_dir/Vtoplevel__ALL.a \
    -o sim_improved
```

#### 编译 SystemC 改进版本
```bash
# 生成 SystemC 模型
verilator --sc --exe --build --trace \
    --top-module toplevel \
    toplevel.v sdram_controller.v fifo.v dnano_interface.v double_click.v \
    sc_main2_improved.cpp

# 或者手动编译
verilator --sc --trace toplevel.v sdram_controller.v fifo.v dnano_interface.v double_click.v
cd obj_dir
make -f Vtoplevel.mk
g++ -I/usr/share/verilator/include \
    -I/usr/share/verilator/include/vltstd \
    -I./obj_dir \
    -I/usr/local/include/systemc \
    -L/usr/local/lib-linux64 \
    sc_main2_improved.cpp \
    obj_dir/Vtoplevel__ALL.a \
    -lsystemc -o sc_improved
```

#### 编译高级测试平台
```bash
# 生成模型
verilator --cc --exe --build --trace \
    --top-module toplevel \
    toplevel.v sdram_controller.v fifo.v dnano_interface.v double_click.v \
    advanced_testbench.cpp

# 或者手动编译
verilator --cc --trace toplevel.v sdram_controller.v fifo.v dnano_interface.v double_click.v
cd obj_dir
make -f Vtoplevel.mk
g++ -I/usr/share/verilator/include \
    -I/usr/share/verilator/include/vltstd \
    -I./obj_dir \
    advanced_testbench.cpp \
    obj_dir/Vtoplevel__ALL.a \
    -o advanced_test
```

### 步骤 3: 创建 Makefile（可选）

创建 `Makefile` 简化编译过程：

```makefile
# Makefile for SDRAM Controller Testbench

# 编译器设置
CXX = g++
VERILATOR = verilator
VERILATOR_ROOT = $(shell $(VERILATOR) --getenv VERILATOR_ROOT)

# 源文件
VERILOG_SOURCES = toplevel.v sdram_controller.v fifo.v dnano_interface.v double_click.v
CPP_SOURCES = sim_main_improved.cpp sc_main2_improved.cpp advanced_testbench.cpp

# 目标文件
TARGETS = sim_improved sc_improved advanced_test

# 默认目标
all: $(TARGETS)

# 纯 Verilator 版本
sim_improved: $(VERILOG_SOURCES) sim_main_improved.cpp
	$(VERILATOR) --cc --exe --build --trace \
		--top-module toplevel \
		$(VERILOG_SOURCES) sim_main_improved.cpp
	cp obj_dir/Vtoplevel sim_improved

# SystemC 版本
sc_improved: $(VERILOG_SOURCES) sc_main2_improved.cpp
	$(VERILATOR) --sc --exe --build --trace \
		--top-module toplevel \
		$(VERILOG_SOURCES) sc_main2_improved.cpp
	cp obj_dir/Vtoplevel sc_improved

# 高级测试平台
advanced_test: $(VERILOG_SOURCES) advanced_testbench.cpp
	$(VERILATOR) --cc --exe --build --trace \
		--top-module toplevel \
		$(VERILOG_SOURCES) advanced_testbench.cpp
	cp obj_dir/Vtoplevel advanced_test

# 清理
clean:
	rm -rf obj_dir *.vcd *.txt $(TARGETS)

# 运行测试
run-sim: sim_improved
	./sim_improved

run-sc: sc_improved
	./sc_improved

run-advanced: advanced_test
	./advanced_test

# 查看波形
view-wave:
	gtkwave wave_verilator.vcd &

.PHONY: all clean run-sim run-sc run-advanced view-wave
```

## 运行测试

### 基本运行

```bash
# 运行纯 Verilator 版本
./sim_improved

# 运行 SystemC 版本
./sc_improved

# 运行高级测试平台
./advanced_test
```

### 带参数运行

```bash
# 禁用波形跟踪
./sim_improved --no-trace

# 指定波形文件名
./sim_improved --trace-file=my_wave.vcd

# 指定观察周期数
./sim_improved --cycles=5000

# 启用错误注入测试
./advanced_test --enable-error-injection

# 禁用时序检查
./advanced_test --disable-timing-check

# 查看帮助
./advanced_test --help
```

### 使用 Makefile 运行

```bash
# 编译所有版本
make all

# 运行特定版本
make run-sim
make run-sc
make run-advanced

# 查看波形
make view-wave

# 清理
make clean
```

## 波形分析

### 使用 GTKWave 查看波形

```bash
# 查看波形文件
gtkwave wave_verilator.vcd

# 或者使用 GUI 界面
gtkwave wave_systemc.vcd &
```

### 推荐的信号查看

在 GTKWave 中，建议查看以下信号：

1. **时钟信号**
   - `top.sys_clk_pad_i` - 系统时钟
   - `top.sdram_clk_pad_o` - SDRAM 时钟

2. **控制信号**
   - `top.rst_n_pad_i` - 复位信号
   - `top.btn_n_pad_i` - 按键信号

3. **SDRAM 控制信号**
   - `top.sdram_cs_n_pad_o` - 片选信号
   - `top.sdram_ras_pad_o` - 行地址选通
   - `top.sdram_cas_pad_o` - 列地址选通
   - `top.sdram_we_pad_o` - 写使能信号
   - `top.sdram_cke_pad_o` - 时钟使能信号

4. **地址和数据信号**
   - `top.sdram_ba_pad_o` - 存储体地址
   - `top.sdram_a_pad_o` - 地址总线
   - `top.sdram_dq_pad_io` - 数据总线

## 故障排除

### 常见问题

1. **编译错误：找不到 Verilator**
   ```bash
   # 检查 Verilator 安装
   which verilator
   verilator --version
   
   # 设置环境变量
   export PATH=/usr/local/bin:$PATH
   ```

2. **SystemC 链接错误**
   ```bash
   # 检查 SystemC 安装
   pkg-config --cflags --libs systemc
   
   # 设置库路径
   export LD_LIBRARY_PATH=/usr/local/lib:$LD_LIBRARY_PATH
   ```

3. **波形文件无法生成**
   ```bash
   # 检查权限
   ls -la *.vcd
   
   # 检查磁盘空间
   df -h .
   ```

4. **仿真运行缓慢**
   ```bash
   # 减少跟踪深度
   # 在代码中修改 trace(tfp, 99) 为 trace(tfp, 10)
   
   # 禁用波形跟踪
   ./sim_improved --no-trace
   ```

### 调试技巧

1. **使用 GDB 调试**
   ```bash
   g++ -g -O0 sim_main_improved.cpp -o sim_debug
   gdb ./sim_debug
   ```

2. **添加调试输出**
   ```cpp
   // 在代码中添加
   #define DEBUG
   #ifdef DEBUG
   printf("Debug: cycle=%llu, signal=%d\n", cycle, signal);
   #endif
   ```

3. **检查 Verilator 警告**
   ```bash
   # 重新生成模型时查看警告
   verilator --cc --trace --Wall toplevel.v ...
   ```

## 性能优化

### 编译优化

```bash
# 使用优化选项
g++ -O3 -DNDEBUG sim_main_improved.cpp ...

# 减少调试信息
verilator --cc --trace --no-timing ...
```

### 仿真优化

```cpp
// 在代码中
#define VM_TRACE 0  // 禁用波形跟踪
#define VM_COVERAGE 0  // 禁用覆盖率收集
```

## 扩展功能

### 添加新的测试用例

1. 在测试文件中添加新的测试函数
2. 在主函数中调用新测试
3. 更新验证逻辑

### 集成到 CI/CD

```yaml
# GitHub Actions 示例
name: SDRAM Test
on: [push, pull_request]
jobs:
  test:
    runs-on: ubuntu-latest
    steps:
    - uses: actions/checkout@v2
    - name: Install dependencies
      run: |
        sudo apt-get update
        sudo apt-get install verilator gtkwave
    - name: Build and test
      run: |
        make all
        ./advanced_test --cycles=1000
```

## 总结

本指南提供了完整的编译和运行流程。建议从简单的 `sim_main_improved.cpp` 开始，然后逐步使用更复杂的高级测试平台。每个版本都有其特定的用途和优势，可以根据需要选择合适的版本。
