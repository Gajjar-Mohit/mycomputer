# Logic Gates & Arithmetic Unit (ALU)

This page provides the mathematical specification and C implementations of primitive logic gates and ALU arithmetic circuits.

---

## ⚡ Primitive Logic Gates (`gates.c`)

Processing binary inputs $A, B \in \{0, 1\}$:

| Gate | Boolean Expression | C Implementation |
| :--- | :--- | :--- |
| **AND** | $Y = A \cdot B$ | `a & b` |
| **OR** | $Y = A + B$ | `a \|\| b` |
| **NOT** | $Y = \overline{A}$ | `!a` |
| **NAND** | $Y = \overline{A \cdot B}$ | `!AND(a, b)` |
| **NOR** | $Y = \overline{A + B}$ | `!OR(a, b)` |
| **XOR** | $Y = A \oplus B = \overline{A}B + A\overline{B}$ | `OR(AND(!a, b), AND(a, !b))` |
| **XNOR** | $Y = \overline{A \oplus B} = AB + \overline{A}\overline{B}$ | `OR(AND(a, b), AND(!a, !b))` |

---

## 🧮 Arithmetic Circuits (`adder.c`, `substractor.c`)

### 1. Half-Adder ($\text{HA}$)

$$S = A \oplus B$$

$$C_{\text{out}} = A \cdot B$$

```c
AdderOutput HALF_ADDER(int a, int b) {
  AdderOutput result;
  result.sum = XOR(a, b);
  result.carry = AND(a, b);
  return result;
}
```

---

### 2. Full-Adder ($\text{FA}$)

$$S = A \oplus B \oplus C_{\text{in}}$$

$$C_{\text{out}} = (A \cdot B) + (C_{\text{in}} \cdot (A \oplus B))$$

```c
AdderOutput FULL_ADDER(int a, int b, int cin) {
  AdderOutput result;
  result.sum = XOR(XOR(a, b), cin);
  result.carry = OR(AND(a, b), AND(cin, XOR(a, b)));
  return result;
}
```

---

### 3. Half-Subtractor ($\text{HS}$)

$$D = A \oplus B$$

$$B_{\text{out}} = \overline{A} \cdot B$$

---

### 4. Full-Subtractor ($\text{FS}$)

$$D = A \oplus B \oplus B_{\text{in}}$$

$$B_{\text{out}} = (\overline{A} \cdot B) + (\overline{A \oplus B} \cdot B_{\text{in}})$$
