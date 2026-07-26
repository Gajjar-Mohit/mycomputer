# Building a CPU Processor from Scratch in C

[![C Language](https://img.shields.io/badge/C-C11-blue.svg)](https://en.wikipedia.org/wiki/C11_(C_standard_revision))
[![License](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)
[![Build Status](https://img.shields.io/badge/Build-Passing-brightgreen.svg)]()
[![SEO Optimized](https://img.shields.io/badge/Search_Indexed-CPU_Project-orange.svg)]()

> **The primary goal of this project is to construct a fully functional Central Processing Unit (CPU / Processor) from scratch in ANSI C. Built strictly from first principles starting with primitive logic gates, the architecture synthesizes combinational circuits, sequential memory elements, Arithmetic Logic Units (ALU), register files, instruction decoders, and clock execution cycles to simulate a complete computer processor.**

---

## 🎯 Main Goal & System Architecture Roadmap

This repository represents a bottom-up hardware design simulation of a **CPU (Central Processing Unit)** written entirely in standard C (C11).

Instead of using high-level abstractions, every component of the CPU is constructed ground-up from fundamental **Boolean Logic Gates**:

```text
+-------------------------------------------------------------------+
|                       FULL CPU PROCESSOR                          |
|  +-------------------+-------------------+---------------------+  |
|  | Program Counter   | Control Unit (CU) | Register File (REG) |  |
|  | (PC / Accumulator)| (Decoder & Logic) | (JK / SR Memory)    |  |
|  +-------------------+-------------------+---------------------+  |
+-------------------------------------------------------------------+
                                  ^
                                  |
+-------------------------------------------------------------------+
|               Arithmetic Logic Unit & Bus Routing (ALU)           |
|  +----------------+----------------+----------------+----------+  |
|  | Arithmetic     | Data Routing   | Encoders &     | System   |  |
|  | (Adders/Sub)   | (MUX / DEMUX)  | Decoders       | Clock    |  |
|  +----------------+----------------+----------------+----------+  |
+-------------------------------------------------------------------+
                                  ^
                                  |
+-------------------------------------------------------------------+
|                      Primitive Logic Gate Layer                   |
|                            (gates.c / .h)                         |
+-------------------------------------------------------------------+
```

---

## 🔬 Formal Mathematical Specifications & Boolean Formulations

### 1. Primitive Logic Gates (`gates.c`)

Processing binary signals $A, B \in \{0, 1\}$:

| Gate | Formal Boolean Function | ANSI C Implementation |
| :--- | :--- | :--- |
| **AND** | $Y = A \cdot B$ | `a & b` |
| **OR** | $Y = A + B$ | `a \|\| b` |
| **NOT** | $Y = \overline{A}$ | `!a` |
| **NAND** | $Y = \overline{A \cdot B}$ | `!AND(a, b)` |
| **NOR** | $Y = \overline{A + B}$ | `!OR(a, b)` |
| **XOR** | $Y = A \oplus B = \overline{A}B + A\overline{B}$ | `OR(AND(!a, b), AND(a, !b))` |
| **XNOR** | $Y = \overline{A \oplus B} = AB + \overline{A}\overline{B}$ | `OR(AND(a, b), AND(!a, !b))` |

---

### 2. Arithmetic Logic Unit (ALU) Components (`adder.c`, `substractor.c`)

#### Half-Adder ($\text{HA}$)

$$S = A \oplus B$$

$$C_{\text{out}} = A \cdot B$$

#### Full-Adder ($\text{FA}$)

$$S = A \oplus B \oplus C_{\text{in}}$$

$$C_{\text{out}} = (A \cdot B) + (C_{\text{in}} \cdot (A \oplus B))$$

#### Half-Subtractor ($\text{HS}$)

$$D = A \oplus B$$

$$B_{\text{out}} = \overline{A} \cdot B$$

#### Full-Subtractor ($\text{FS}$)

$$D = A \oplus B \oplus B_{\text{in}}$$

$$B_{\text{out}} = (\overline{A} \cdot B) + (\overline{A \oplus B} \cdot B_{\text{in}})$$

---

### 3. Data Routing & Bus Control (`multiplexer.c`, `demultiplexer.c`)

#### $2\times1$ Multiplexer ($\text{MUX}_{2\times1}$)

$$Y = (\overline{S_0} \cdot I_1) + (S_0 \cdot I_2)$$

#### $4\times1$ Multiplexer ($\text{MUX}_{4\times1}$)

$$Y = (\overline{S_0} \cdot \overline{S_1} \cdot I_1) + (S_0 \cdot \overline{S_1} \cdot I_2) + (\overline{S_0} \cdot S_1 \cdot I_3) + (S_0 \cdot S_1 \cdot I_4)$$

#### $1\times2$ Demultiplexer ($\text{DEMUX}_{1\times2}$)

$$O_1 = \overline{S_0} \cdot I, \quad O_2 = S_0 \cdot I$$

#### $1\times4$ Demultiplexer ($\text{DEMUX}_{1\times4}$)

$$O_1 = \overline{S_0}\cdot\overline{S_1}\cdot I, \quad O_2 = S_0\cdot\overline{S_1}\cdot I, \quad O_3 = \overline{S_0}\cdot S_1\cdot I, \quad O_4 = S_0\cdot S_1\cdot I$$

---

### 4. Instruction & Address Decoders (`encoder.c`, `decoder.c`)

#### 8-to-3 Line Encoder ($\text{ENC}_{8\times3}$) / Binary-to-BCD Encoder

Converts 8 input lines ($Y_7$ to $Y_0$) into a 3-bit binary code ($A_2, A_1, A_0$):

$$A_2 = Y_4 + Y_5 + Y_6 + Y_7$$

$$A_1 = Y_2 + Y_3 + Y_6 + Y_7$$

$$A_0 = Y_1 + Y_3 + Y_5 + Y_7$$

#### 3-to-7 Active-HIGH Line Decoder ($\text{DEC}_{3\times7}$)

Decodes a 3-bit instruction address ($I_2, I_1, I_0$) into 7 active-HIGH control signals ($O_7$ to $O_1$):

$$O_1 = \overline{I_2} \cdot \overline{I_1} \cdot I_0 \quad (\text{Binary } 001_2 = 1)$$

$$O_2 = \overline{I_2} \cdot I_1 \cdot \overline{I_0} \quad (\text{Binary } 010_2 = 2)$$

$$O_3 = \overline{I_2} \cdot I_1 \cdot I_0 \quad (\text{Binary } 011_2 = 3)$$

$$O_4 = I_2 \cdot \overline{I_1} \cdot \overline{I_0} \quad (\text{Binary } 100_2 = 4)$$

$$O_5 = I_2 \cdot \overline{I_1} \cdot I_0 \quad (\text{Binary } 101_2 = 5)$$

$$O_6 = I_2 \cdot I_1 \cdot \overline{I_0} \quad (\text{Binary } 110_2 = 6)$$

$$O_7 = I_2 \cdot I_1 \cdot I_0 \quad (\text{Binary } 111_2 = 7)$$

---

### 5. Sequential Memory & Register File Elements (`flipflops.c`, `latchs.c`)

#### Active-Low NAND SR Latch

$$Q = \text{NAND}(\overline{S}, \overline{Q}), \quad \overline{Q} = \text{NAND}(\overline{R}, Q)$$

#### Gated SR Flip-Flop

$$S' = \text{NAND}(S, \text{CLK}), \quad R' = \text{NAND}(R, \text{CLK})$$

#### JK Flip-Flop (Register Memory Bit)

$$S' = \text{NAND}(\text{AND}(J, \text{CLK}), \overline{Q}_{\text{prev}})$$

$$R' = \text{NAND}(\text{AND}(K, \text{CLK}), Q_{\text{prev}})$$

| State Transition | $J$ | $K$ | $\text{CLK}$ | $Q_{\text{next}}$ | $\overline{Q}_{\text{next}}$ | Characteristic Operation |
| :--- | :---: | :---: | :---: | :---: | :---: | :--- |
| **Clock Off** | $X$ | $X$ | $0$ | $Q_{\text{prev}}$ | $\overline{Q}_{\text{prev}}$ | Memory Hold |
| **No Change** | $0$ | $0$ | $1$ | $Q_{\text{prev}}$ | $\overline{Q}_{\text{prev}}$ | Memory Hold |
| **Reset** | $0$ | $1$ | $1$ | $0$ | $1$ | Reset ($Q=0$) |
| **Set** | $1$ | $0$ | $1$ | $1$ | $0$ | Set ($Q=1$) |
| **Toggle** | $1$ | $1$ | $1$ | $\overline{Q}_{\text{prev}}$ | $Q_{\text{prev}}$ | State Inversion (Toggle) |

---

## 📁 Repository Directory Structure

```text
.
├── Makefile          # Automated compilation script for all C components
├── README.md         # Academic CPU project documentation & formal specs
├── main.c            # Test suite execution harness and CPU verification
├── gates.h / .c      # Primitive Boolean logic gates
├── adder.h / .c      # Arithmetic Adders for ALU
├── substractor.h/.c  # Arithmetic Subtractors for ALU
├── multiplexer.h/.c  # Bus routing data Multiplexers
├── demultiplexer.h/.c# Bus routing data Demultiplexers
├── encoder.h / .c    # Instruction & address Encoders
├── decoder.h / .c    # Control Unit Instruction Decoders
├── latchs.h / .c     # Bistable memory latches
├── flipflops.h / .c  # Clocked flip-flop memory registers
└── clock.h / .c      # System clock timing module
```

---

## 🛠 Compilation & Build Instructions

Compile and run the CPU logic test suite using the dynamic Makefile:

```bash
# Compile and build the binary
make

# Build and execute tests immediately
make run

# Clean build artifacts
make clean
```

---

## 🔍 Search Engine Indexing & Trending Keywords

`Build a CPU in C` `How to Write a Processor in C` `CPU Architecture from Scratch` `Gate-Level CPU Emulator` `C Language Processor Design` `Building a Computer in C` `ALU Design in C` `Custom CPU Simulator C Code` `Register-Transfer Level RTL C Simulator` `Binary to BCD Encoder C` `3 to 7 Decoder Circuit C` `JK Flip Flop Register C` `Computer Organization and Architecture Simulator` `Makefile C CPU Project`

---

## 📄 License & Academic References

1. **M. Morris Mano & Michael D. Ciletti**, *Digital Design: With an Introduction to the Verilog HDL, VHDL, and SystemVerilog*, 6th Edition, Pearson, 2017.
2. **Charles H. Roth Jr. & Larry L. Kinney**, *Fundamentals of Logic Design*, 7th Edition, Cengage Learning, 2013.

This open-source project is licensed under the **MIT License**. Built for computer science students, system programmers, and computer architecture enthusiasts building CPUs from scratch.
