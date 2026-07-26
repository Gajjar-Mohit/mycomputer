# Welcome to the CPU-from-Scratch-in-C Wiki!

[![C Language](https://img.shields.io/badge/C-C11-blue.svg)](https://en.wikipedia.org/wiki/C11_(C_standard_revision))
[![License](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)
[![Build Status](https://img.shields.io/badge/Build-Passing-brightgreen.svg)]()

> **The primary mission of this project is to construct a fully functional Central Processing Unit (CPU / Processor) from scratch in ANSI C, using fundamental gate-level logic circuits and digital design principles.**

---

## 📚 Wiki Table of Contents

| Section | Description |
| :--- | :--- |
| 1. [CPU Architecture & Roadmap](CPU-Architecture-&-Roadmap.md) | High-level CPU design, instruction cycle, register file, and control unit. |
| 2. [Logic Gates & Arithmetic Unit](Logic-Gates-&-Arithmetic-Unit.md) | Boolean logic primitives, Half/Full Adders, and Half/Full Subtractors (ALU). |
| 3. [Data Routing & Code Converters](Data-Routing-&-Code-Converters.md) | Multiplexers (MUX), Demultiplexers (DEMUX), 8-to-3 Encoders, and 3-to-7 Decoders. |
| 4. [Sequential Memory & Clock](Sequential-Memory-&-Clock.md) | Bistable SR Latches, Clocked SR Flip-Flops, JK Flip-Flops, and System Clock timing. |
| 5. [Build & Verification Guide](Build-&-Verification-Guide.md) | GNU Makefile build automation, compilation setup, and running automated test suites. |

---

## 🎯 Project Overview

This repository models a **computer processor** starting from physical semiconductor Boolean logic functions up through complex computer architecture subsystems:

```text
+-------------------------------------------------------------------+
|                        FULL CPU PROCESSOR                         |
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

## 🛠 Quick Build & Run

Ensure you have `gcc` and `make` installed, then execute:

```bash
# Compile and run all tests immediately
make run
```
