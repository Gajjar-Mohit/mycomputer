# Building a CPU Processor from Scratch in C

[![C Language](https://img.shields.io/badge/C-C11-blue.svg)](https://en.wikipedia.org/wiki/C11_(C_standard_revision))
[![License](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)
[![Build Status](https://img.shields.io/badge/Build-Passing-brightgreen.svg)]()
[![SEO Optimized](https://img.shields.io/badge/Search_Indexed-CPU_Project-orange.svg)]()

> **The ultimate goal of this project is to construct a fully functional Central Processing Unit (CPU / Processor) from scratch in C. Built strictly from first principles starting with primitive logic gates, the architecture builds up through combinational circuits, sequential memory elements, ALUs, register files, instruction decoders, and clock cycles to simulate a complete computer processor.**

---

## 🎯 Main Goal & Project Vision

This project is a bottom-up hardware design simulation of a **CPU (Central Processing Unit)** written entirely in standard C (C11).

Instead of relying on high-level abstractions or external hardware emulators, every component of the CPU is built ground-up from **Boolean Logic Gates**:

```text
[ Logic Gates ] ──> [ Combinational Circuits ] ──> [ ALUs & Encoders ]
                                                         │
[ Clock & Memory ] ──> [ Registers & Control Unit ] ──────┼──> [ FULL CPU PROCESSOR ]
```

### CPU Development Roadmap:
1. **Gate-Level Primitive Layer**: AND, OR, NOT, NAND, NOR, XOR, XNOR logic gates.
2. **Arithmetic Logic Unit (ALU)**: Adders, Subtractors, Bitwise operations, Status Flags.
3. **Data Routing Units**: Multiplexers (MUX) and Demultiplexers (DEMUX) for bus routing.
4. **Instruction & State Decoders**: Encoders and Decoders for opcodes and instruction decoding.
5. **Memory & Register File**: Bistable SR Latches, Clocked SR Flip-Flops, JK Flip-Flops, Registers.
6. **Clock & Control Unit**: Clock pulse generator, Instruction Fetch-Decode-Execute pipeline, Program Counter (PC), Accumulator (ACC), and Control Unit (CU).

---

## 🚀 Key Modules & Implemented Hardware Components

### 1. Primitive Logic Gates (`gates.c` / `gates.h`)
First-principles logic gate evaluation using bitwise operations:
* **AND, OR, NOT, NAND, NOR, XOR, XNOR**

### 2. Combinational Arithmetic Unit (`adder.c`, `substractor.c`)
Core ALU arithmetic building blocks:
* **Half-Adder (HA)** & **Full-Adder (FA)**
* **Half-Subtractor (HS)** & **Full-Subtractor (FS)**

### 3. Data Routing & Bus Control (`multiplexer.c`, `demultiplexer.c`)
Used for CPU internal bus switching, register selection, and data routing:
* **2-to-1 Multiplexer (MUX 2x1)** & **4-to-1 Multiplexer (MUX 4x1)**
* **1-to-2 Demultiplexer (DEMUX 1x2)** & **1-to-4 Demultiplexer (DEMUX 1x4)**

### 4. Code Converters & Instruction Decoders (`encoder.c`, `decoder.c`)
Decodes instruction opcodes and converts signals:
* **8-to-3 Line Encoder / Binary-to-BCD Encoder (`BIN_TO_BCD_ENCODER`)**: Converts 8 input lines (Y7-Y0) into a 3-bit binary address (A2, A1, A0).
* **3-to-7 Active-HIGH Decoder (`BCD_TO_BIN_DECODER`)**: Decodes 3-bit binary addresses (I2, I1, I0) into 7 distinct active-HIGH control lines (O7-O1).

### 5. Sequential Memory Elements & Registers (`latchs.c`, `flipflops.c`)
Stores CPU state, flag bits, and register values:
* **Active-Low NAND SR Latch**: Bistable memory cell.
* **Gated SR Flip-Flop**: Clock-synchronized bit store.
* **JK Flip-Flop**: Toggle-capable register bit with zero invalid states.

### 6. System Clock & Timing (`clock.c`)
* **Clock Pulse Generator**: Synchronizes state transitions during instruction execution cycles.

---

## 📁 Repository Directory Structure

```text
.
├── Makefile          # Dynamic compilation script for all C components
├── README.md         # Master CPU project documentation & roadmap
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

## 📐 Circuit Specifications & Logic Tables

### 8-to-3 Encoder Boolean Logic (`BIN_TO_BCD_ENCODER`)
* **A2 = Y4 + Y5 + Y6 + Y7**
* **A1 = Y2 + Y3 + Y6 + Y7**
* **A0 = Y1 + Y3 + Y5 + Y7**

### 3-to-7 Line Decoder Logic (`BCD_TO_BIN_DECODER`)
* **O1 = (NOT I2) * (NOT I1) * I0** (Active for Binary 001 = 1)
* **O2 = (NOT I2) * I1 * (NOT I0)** (Active for Binary 010 = 2)
* **O3 = (NOT I2) * I1 * I0** (Active for Binary 011 = 3)
* **O4 = I2 * (NOT I1) * (NOT I0)** (Active for Binary 100 = 4)
* **O5 = I2 * (NOT I1) * I0** (Active for Binary 101 = 5)
* **O6 = I2 * I1 * (NOT I0)** (Active for Binary 110 = 6)
* **O7 = I2 * I1 * I0** (Active for Binary 111 = 7)

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

## 📄 License & Attribution

This open-source project is licensed under the **MIT License**. Built for computer engineering students, system programmers, and computer architecture enthusiasts building CPUs from scratch.
