# Digital Logic Circuit Simulation & Hardware Emulator in C

[![C Standard](https://img.shields.io/badge/C-C99%2FANSI-blue.svg)](https://en.wikipedia.org/wiki/C99)
[![License](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)
[![Build Status](https://img.shields.io/badge/Build-Passing-brightgreen.svg)]()

> **An academic-grade, gate-level hardware simulator in ANSI C modeling discrete digital logic synthesis, combinational arithmetic units, data routing multiplexers/demultiplexers, and sequential flip-flop memory elements.**

---

## Abstract & Technical Overview

This repository provides a structural, first-principles implementation of a **digital logic simulator** and **computer architecture framework** written in standard ANSI C. The system models physical semiconductor logic components by synthesizing primitive Boolean logic gates into complex **combinational** and **sequential digital circuits**.

Engineered for academic research, digital design education, and low-level hardware design simulation, the architecture features:
* **Combinational Logic Circuits**: Binary Adders, Subtractors, Data Multiplexers ($\text{MUX}$), and Demultiplexers ($\text{DEMUX}$).
* **Sequential Logic & Memory Circuits**: Active-Low Bistable NAND SR Latches, Gated Clocked SR Flip-Flops, and Master-Slave/Steered JK Flip-Flops.
* **Deterministic Output Verification**: Tabular truth-table execution harness rendering state changes in formatted ASCII representation.

---

## System Architecture & Hierarchical Layering

The framework follows a strict **Register-Transfer Level (RTL)** layered hierarchy:

```text
+-------------------------------------------------------------------+
|                     Execution & Verification                      |
|                            (main.c)                               |
+-------------------------------------------------------------------+
                                  |
                                  v
+-------------------------------------------------------------------+
|                     Digital Circuit Layer                         |
|  +----------------+----------------+----------------+----------+  |
|  | Arithmetic     | Data Routing   | Memory Units   | Latches  |  |
|  | (Adders/Sub)   | (MUX / DEMUX)  | (Flip-Flops)   | (SR)     |  |
|  +----------------+----------------+----------------+----------+  |
+-------------------------------------------------------------------+
                                  |
                                  v
+-------------------------------------------------------------------+
|                       Boolean Primitive Layer                     |
|                            (gates.c/.h)                           |
+-------------------------------------------------------------------+
```

---

## Formal Mathematical Specifications & Boolean Formulations

### 1. Primitive Logic Gates

Processing single-bit binary signals $A, B \in \{0, 1\}$:

| Gate | Formal Boolean Function | ANSI C Implementation |
| :--- | :--- | :--- |
| **AND** | $Y = A \cdot B$ | `a & b` |
| **OR** | $Y = A + B$ | `a \|\| b` |
| **NOT** | $Y = \overline{A}$ | `!a` |
| **NOR** | $Y = \overline{A + B}$ | `!OR(a, b)` |
| **NAND** | $Y = \overline{A \cdot B}$ | `!AND(a, b)` |
| **XOR** | $Y = A \oplus B = \overline{A}B + A\overline{B}$ | `OR(AND(!a, b), AND(a, !b))` |
| **XNOR** | $Y = \overline{A \oplus B} = AB + \overline{A}\overline{B}$ | `OR(AND(a, b), AND(!a, !b))` |

---

### 2. Combinational Arithmetic Circuits

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

### 3. Data Routing Circuits (Multiplexers & Demultiplexers)

#### $2\times1$ Multiplexer ($\text{MUX}_{2\times1}$)

$$Y = (\overline{S_0} \cdot I_1) + (S_0 \cdot I_2)$$

#### $4\times1$ Multiplexer ($\text{MUX}_{4\times1}$)

$$Y = (\overline{S_0} \cdot \overline{S_1} \cdot I_1) + (S_0 \cdot \overline{S_1} \cdot I_2) + (\overline{S_0} \cdot S_1 \cdot I_3) + (S_0 \cdot S_1 \cdot I_4)$$

#### $1\times2$ Demultiplexer ($\text{DEMUX}_{1\times2}$)

$$O_1 = \overline{S_0} \cdot I, \quad O_2 = S_0 \cdot I$$

#### $1\times4$ Demultiplexer ($\text{DEMUX}_{1\times4}$)

$$O_1 = \overline{S_0}\cdot\overline{S_1}\cdot I, \quad O_2 = S_0\cdot\overline{S_1}\cdot I, \quad O_3 = \overline{S_0}\cdot S_1\cdot I, \quad O_4 = S_0\cdot S_1\cdot I$$

---

### 4. Sequential Memory Elements (Latches & Flip-Flops)

#### Active-Low NAND SR Latch
Feedback-stabilized bistable multivibrator evaluating active-low inputs $\overline{S}$ and $\overline{R}$:

$$Q = \text{NAND}(\overline{S}, \overline{Q})$$

$$\overline{Q} = \text{NAND}(\overline{R}, Q)$$

#### Gated SR Flip-Flop
Synchronized by clock enable signal $\text{CLK}$:

$$S' = \text{NAND}(S, \text{CLK})$$

$$R' = \text{NAND}(R, \text{CLK})$$

#### JK Flip-Flop (Toggle-Capable Memory)
Eliminates invalid states by steering inputs using current state feedback $Q$ and $\overline{Q}$:

$$S' = \text{NAND}(\text{AND}(J, \text{CLK}), \overline{Q}_{\text{prev}})$$

$$R' = \text{NAND}(\text{AND}(K, \text{CLK}), Q_{\text{prev}})$$

| State Transition | $J$ | $K$ | $\text{CLK}$ | $Q_{\text{next}}$ | Characteristic Operation |
| :--- | :---: | :---: | :---: | :---: | :--- |
| **Clock Off** | $X$ | $X$ | $0$ | $Q_{\text{prev}}$ | Memory Hold |
| **No Change** | $0$ | $0$ | $1$ | $Q_{\text{prev}}$ | Memory Hold |
| **Reset** | $0$ | $1$ | $1$ | $0$ | Reset State ($Q=0$) |
| **Set** | $1$ | $0$ | $1$ | $1$ | Set State ($Q=1$) |
| **Toggle** | $1$ | $1$ | $1$ | $\overline{Q}_{\text{prev}}$ | State Inversion (Toggle) |

---

## Directory & Source Code Structure

```text
.
├── README.md         # Technical & academic project documentation
├── main.c            # Test suite execution harness and ASCII renderer
├── gates.h / .c      # Primitive Boolean logic gate evaluations
├── adder.h / .c      # Half-Adder and Full-Adder circuit implementations
├── substractor.h / .c# Half-Subtractor and Full-Subtractor circuit implementations
├── multiplexer.h / .c# 2:1 and 4:1 Data Multiplexer units
├── demultiplexer.h/.c# 1:2 and 1:4 Data Demultiplexer units
├── latchs.h / .c     # Bistable Active-Low NAND SR Latch implementation
└── flipflops.h / .c  # Clocked SR Flip-Flop and JK Flip-Flop implementations
```

---

## Compilation & Execution Guide

### Toolchain Requirements
* **Compiler**: GCC / Clang (C99 / ANSI C compliant)
* **Shell Environment**: POSIX Terminal / macOS zsh / Linux bash

### Compilation

Compile all modular C sources and generate the target executable:

```bash
gcc -Wall -Wextra -std=c99 main.c gates.c adder.c substractor.c multiplexer.c demultiplexer.c latchs.c flipflops.c -o main
```

### Execution

Execute the binary to run the automated truth-table test harness:

```bash
./main
```

---

## Sample Execution Output

```text
==================================================
             FLIP-FLOPS / LATCHES TEST            
==================================================

--- SR LATCH (NAND Active-Low) ---
 S | R | Qn | Qn_bar | State Description
---+---+----+--------+-------------------
 0 | 1 |  1 |   0    | Set (Q=1)
 1 | 1 |  1 |   0    | Hold (Retains Q=1)
 1 | 0 |  0 |   1    | Reset (Q=0)
 1 | 1 |  0 |   1    | Hold (Retains Q=0)
 0 | 0 |  1 |   1    | Invalid (Forbidden)

--- SR FLIP-FLOP (Gated Clock) ---
 CLK | S | R | Qn | Qn_bar | State Description
-----+---+---+----+--------+-------------------
  0  | 1 | 0 |  0 |   1    | Clock Off (Holds state)
  1  | 1 | 0 |  1 |   0    | Set (Q=1)
  1  | 0 | 0 |  1 |   0    | Hold (Retains Q=1)
  1  | 0 | 1 |  0 |   1    | Reset (Q=0)
  1  | 0 | 0 |  0 |   1    | Hold (Retains Q=0)
  1  | 1 | 1 |  1 |   1    | Invalid (Forbidden)

--- JK FLIP-FLOP ---
 CLK | J | K | Qn | Qn_bar | State Description
-----+---+---+----+--------+-------------------
  0  | 1 | 0 |  0 |   1    | Clock Off
  1  | 0 | 0 |  0 |   1    | Hold
  1  | 1 | 0 |  1 |   0    | Set (Q=1)
  1  | 0 | 1 |  0 |   1    | Reset (Q=0)
  1  | 1 | 1 |  1 |   0    | Toggle
```

---

## Keywords & Related Concepts

`Digital Logic Simulator` `Computer Architecture in C` `Boolean Algebra Emulator` `Gate-Level Synthesis` `RTL Simulation` `JK Flip Flop C Implementation` `SR Latch Logic Gates` `Multiplexer Demultiplexer Circuit` `Sequential Logic Simulation` `Combinational Circuit Design`

---

## Academic References

1. **M. Morris Mano & Michael D. Ciletti**, *Digital Design: With an Introduction to the Verilog HDL, VHDL, and SystemVerilog*, 6th Edition, Pearson, 2017.
2. **Charles H. Roth Jr. & Larry L. Kinney**, *Fundamentals of Logic Design*, 7th Edition, Cengage Learning, 2013.
3. **Brian W. Kernighan & Dennis M. Ritchie**, *The C Programming Language*, 2nd Edition, Prentice Hall, 1988.

---

> [!NOTE]
> This simulation framework evaluates discrete Boolean signals through structural gate functions without external hardware emulation dependencies.
