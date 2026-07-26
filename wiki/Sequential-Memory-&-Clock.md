# Sequential Memory & Clock Systems

This page documents bistable multivibrators, latches, flip-flops, and clock pulse timing components used to construct the CPU Register File.

---

## 💾 Latches & Flip-Flops (`latchs.c`, `flipflops.c`)

### Active-Low NAND SR Latch
$$Q = \text{NAND}(\overline{S}, \overline{Q}), \quad \overline{Q} = \text{NAND}(\overline{R}, Q)$$

---

### JK Flip-Flop (Register Memory Element)

$$S' = \text{NAND}(\text{AND}(J, \text{CLK}), \overline{Q}_{\text{prev}})$$

$$R' = \text{NAND}(\text{AND}(K, \text{CLK}), Q_{\text{prev}})$$

#### Truth Table:
| State Description | $\text{CLK}$ | $J$ | $K$ | $Q_{\text{next}}$ | $\overline{Q}_{\text{next}}$ | Operation |
| :--- | :---: | :---: | :---: | :---: | :---: | :--- |
| **Clock Off** | $0$ | $X$ | $X$ | $Q_{\text{prev}}$ | $\overline{Q}_{\text{prev}}$ | Memory Hold |
| **No Change** | $1$ | $0$ | $0$ | $Q_{\text{prev}}$ | $\overline{Q}_{\text{prev}}$ | Memory Hold |
| **Reset** | $1$ | $0$ | $1$ | $0$ | $1$ | Reset ($Q=0$) |
| **Set** | $1$ | $1$ | $0$ | $1$ | $0$ | Set ($Q=1$) |
| **Toggle** | $1$ | $1$ | $1$ | $\overline{Q}_{\text{prev}}$ | $Q_{\text{prev}}$ | State Inversion (Toggle) |

---

## ⏰ Clock Generator (`clock.c`, `clock.h`)

Provides system-wide pulse synchronization for register writes and instruction cycle execution.
