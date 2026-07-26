# CPU Architecture & Roadmap

This page details the architectural design, Register-Transfer Level (RTL) hierarchy, and execution pipeline for the **CPU Processor in C**.

---

## 🏛 CPU Design Overview

The CPU is constructed using a classic **Von Neumann / Harvard Architecture** paradigm, comprising five core subsystems built entirely from gate-level C circuits:

1. **Arithmetic Logic Unit (ALU)**: Performs 8-bit binary arithmetic (Addition, Subtraction) and logical operations (AND, OR, XOR, NOT).
2. **Control Unit (CU)**: Decodes instruction opcodes using the 3-to-7 line decoder (`BCD_TO_BIN_DECODER`) to generate control signals.
3. **Register File (REG)**: Built from JK Flip-Flops and SR Latches to store accumulator data, program counter, and flag registers.
4. **Data Bus Routing**: Multiplexers (`MUX`) and Demultiplexers (`DEMUX`) steer data between registers, memory, and the ALU.
5. **System Clock**: Synchronizes state updates during the Fetch-Decode-Execute pipeline.

---

## 🔄 Fetch-Decode-Execute Pipeline

```text
  +--------------------------------------------------------+
  |                   1. FETCH STAGE                       |
  |  Fetch instruction address from Program Counter (PC)   |
  +--------------------------------------------------------+
                             |
                             v
  +--------------------------------------------------------+
  |                  2. DECODE STAGE                       |
  | Decode instruction opcode using 3-to-7 Decoder module   |
  +--------------------------------------------------------+
                             |
                             v
  +--------------------------------------------------------+
  |                  3. EXECUTE STAGE                      |
  |  Execute ALU operation and write back result to REG    |
  +--------------------------------------------------------+
```

---

## 📋 Subsystem Mapping to C Code

| CPU Subsystem | C Source Files | Functional Description |
| :--- | :--- | :--- |
| **Logic Primitives** | `gates.h`, `gates.c` | Gate-level Boolean evaluations (`AND`, `OR`, `NOT`, `XOR`, etc.) |
| **ALU Core** | `adder.c`, `substractor.c` | Half/Full Adders & Half/Full Subtractors for arithmetic |
| **Bus Control** | `multiplexer.c`, `demultiplexer.c` | Data multiplexing and demultiplexing for CPU bus routing |
| **Instruction Decoder** | `encoder.c`, `decoder.c` | Opcode translation (`BIN_TO_BCD_ENCODER`, `BCD_TO_BIN_DECODER`) |
| **Register Memory** | `latchs.c`, `flipflops.c` | Memory cells (SR Latches, Gated SR, JK Flip-Flops) |
| **Clock Generator** | `clock.c`, `clock.h` | Timing pulse generator for state synchronization |
| **Execution Test Harness**| `main.c` | Integration harness and execution verification |
