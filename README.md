# Logic Gate & Combinational Circuit Simulation Framework

> **An Academic C Implementation of Discrete Digital Logic Synthesis, Gate-Level Building Blocks, and Combinational Computer Architecture Units.**

---

## Abstract

This repository presents a structural ANSI C implementation of a discrete gate-level simulator modeling fundamental digital logic elements and combinational sub-components. Built from first principles, the framework synthesizes basic Boolean primitives—such as AND, OR, NOT, NAND, NOR, XOR, and XNOR gates—into higher-order computational units including half/full adders, half/full subtractors, and multi-channel multiplexers ($2\times1$ and $4\times1$). 

The architecture strictly adheres to modular software engineering principles by encapsulating state outputs into discrete C structures (`struct`), isolating gate implementations from component logic, and executing deterministic truth-table verification suites.

---

## Architectural Taxonomy

The simulation framework is organized hierarchically into three distinct functional tiers:

```
+-------------------------------------------------------------------+
|                     Execution & Verification                      |
|                            (main.c)                               |
+-------------------------------------------------------------------+
                                  |
                                  v
+-------------------------------------------------------------------+
|                  Combinational Circuit Layer                      |
|       +-------------------+---------------+------------------+    |
|       | Arithmetic Units  | Subtraction   | Data Selection   |    |
|       | (adder.c/.h)      | (substractor) | (multiplexer)    |    |
|       +-------------------+---------------+------------------+    |
+-------------------------------------------------------------------+
                                  |
                                  v
+-------------------------------------------------------------------+
|                       Boolean Primitive Layer                     |
|                            (gates.c/.h)                           |
+-------------------------------------------------------------------+
```

1. **Primitive Layer (`gates.h`, `gates.c`)**: Low-level function primitives evaluating binary logic values $x, y \in \{0, 1\}$.
2. **Combinational Layer (`adder.c`, `substractor.c`, `multiplexer.c`)**: Higher-order digital modules constructed strictly through composition of primitive logic functions.
3. **Verification Layer (`main.c`)**: Standardized verification suite rendering tabular truth table outputs across full input spaces.

---

## Formal Boolean Formulations & Mathematical Specifications

### 1. Primitive Logic Gates

Each primitive logic function processes single-bit boolean operands $A, B \in \{0, 1\}$.

| Logic Gate | Formal Boolean Expression | ANSI C Implementation Logic |
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
A two-input binary adder computing the sum bit $S$ and output carry $C$.

$$\begin{aligned}
S &= A \oplus B \\
C &= A \cdot B
\end{aligned}$$

#### Full-Adder ($\text{FA}$)
A three-input adder accepting inputs $A, B$ and carry-in $C_{in}$. Implemented compositionally using two cascaded Half-Adders:

$$\begin{aligned}
S &= A \oplus B \oplus C_{in} \\
C_{out} &= (A \cdot B) + (C_{in} \cdot (A \oplus B))
\end{aligned}$$

```c
typedef struct {
  int sum;
  int carry;
} FullAdderOutput;
```

---

### 3. Combinational Subtraction Circuits

#### Half-Subtractor ($\text{HS}$)
Computes difference $D$ and borrow-out $B_{out}$ for two binary inputs $A$ and $B$:

$$\begin{aligned}
D &= A \oplus B \\
B_{out} &= \overline{A} \cdot B
\end{aligned}$$

#### Full-Subtractor ($\text{FS}$)
Processes minuend $A$, subtrahend $B$, and borrow-in $B_{in}$. Synthesized via two cascaded Half-Subtractors:

$$\begin{aligned}
D &= A \oplus B \oplus B_{in} \\
B_{out} &= (\overline{A} \cdot B) + (\overline{A \oplus B} \cdot B_{in})
\end{aligned}$$

```c
typedef struct {
  int borrow;
  int substraction;
} FullSubstractorOutput;
```

---

### 4. Data Multiplexing Units

#### $2 \times 1$ Multiplexer ($\text{MUX}_{2\times1}$)
Selects between data inputs $I_1$ and $I_2$ controlled by select signal $S_0$:

$$Y = (\overline{S_0} \cdot I_1) + (S_0 \cdot I_2)$$

#### $4 \times 1$ Multiplexer ($\text{MUX}_{4\times1}$)
Selects one of four data inputs $\{I_1, I_2, I_3, I_4\}$ using select signals $(S_0, S_1)$:

$$Y = (\overline{S_0} \cdot \overline{S_1} \cdot I_1) + (S_0 \cdot \overline{S_1} \cdot I_2) + (\overline{S_0} \cdot S_1 \cdot I_3) + (S_0 \cdot S_1 \cdot I_4)$$

---

## Directory & File Structure

```text
.
├── README.md         # Project technical & academic documentation
├── main.c            # Test suite execution harness and formatted ASCII renderer
├── gates.h           # Declarations for primitive Boolean logic functions
├── gates.c           # Implementations of logic gate primitives
├── adder.h           # Struct definitions and declarations for Half/Full Adders
├── adder.c           # Compositional implementation of Adder units
├── substractor.h     # Struct definitions and declarations for Half/Full Subtractors
├── substractor.c     # Compositional implementation of Subtractor units
├── multiplexer.h     # Declarations for 2:1 and 4:1 Multiplexers
└── multiplexer.c     # Gate-level implementations of Multiplexer units
```

---

## Compilation & Execution Guide

### Prerequisites
- GCC Compiler toolchain (ANSI C standard compliant)
- POSIX-compliant shell interface

### Build Command

Compile all source modules and link them into a single unified binary:

```bash
gcc -Wall -Wextra -std=c99 main.c gates.c adder.c substractor.c multiplexer.c demultiplexer.c -o main
```

### Execution

Run the compiled executable to execute the truth-table verification suite:

```bash
./main
```

---

## Sample Truth Table Output

Below is an excerpt of the formatted ASCII truth-table output generated by the test harness:

```text
==================================================
            MULTIPLEXER CIRCUITS TEST             
==================================================

--- 4 X 1 MUX Circuit ---
 I1 | I2 | I3 | I4 | S0 | S1 | Output
----+----+----+----+----+----+--------
  1 |  0 |  1 |  0 |  0 |  0 |   1
  1 |  0 |  1 |  0 |  1 |  0 |   0
  1 |  0 |  1 |  0 |  0 |  1 |   1
  1 |  0 |  1 |  0 |  1 |  1 |   0
```

---

## Academic References

1. **M. Morris Mano & Michael D. Ciletti**, *Digital Design: With an Introduction to the Verilog HDL, VHDL, and SystemVerilog*, 6th Edition, Pearson, 2017.
2. **Charles H. Roth Jr. & Larry L. Kinney**, *Fundamentals of Logic Design*, 7th Edition, Cengage Learning, 2013.
3. **Kernighan, B. W., & Ritchie, D. M.**, *The C Programming Language*, 2nd Edition, Prentice Hall, 1988.

---

> [!NOTE]
> All combinational functions in this simulation avoid hardware abstraction libraries and evaluate signals exclusively through primitive logic functions to demonstrate structural synthesis.
