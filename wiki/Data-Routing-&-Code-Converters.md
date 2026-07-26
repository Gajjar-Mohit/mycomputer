# Data Routing & Code Converters

This page covers Multiplexers, Demultiplexers, Encoders, and Decoders used for CPU bus routing and instruction decoding.

---

## 🔀 Data Routing Circuits (`multiplexer.c`, `demultiplexer.c`)

### 2-to-1 Multiplexer ($\text{MUX}_{2\times1}$)
Selects one of two data inputs based on select line $S_0$:

$$Y = (\overline{S_0} \cdot I_1) + (S_0 \cdot I_2)$$

### 4-to-1 Multiplexer ($\text{MUX}_{4\times1}$)
Selects one of four data inputs based on select lines $S_0, S_1$:

$$Y = (\overline{S_0} \cdot \overline{S_1} \cdot I_1) + (S_0 \cdot \overline{S_1} \cdot I_2) + (\overline{S_0} \cdot S_1 \cdot I_3) + (S_0 \cdot S_1 \cdot I_4)$$

---

## 🔢 Code Converters & Instruction Decoders (`encoder.c`, `decoder.c`)

### 8-to-3 Line Encoder (`BIN_TO_BCD_ENCODER`)
Converts 8 input lines ($Y_7$ to $Y_0$) into a 3-bit binary code ($A_2, A_1, A_0$):

$$A_2 = Y_4 + Y_5 + Y_6 + Y_7$$

$$A_1 = Y_2 + Y_3 + Y_6 + Y_7$$

$$A_0 = Y_1 + Y_3 + Y_5 + Y_7$$

### 3-to-7 Active-HIGH Line Decoder (`BCD_TO_BIN_DECODER`)
Decodes a 3-bit instruction address ($I_2, I_1, I_0$) into 7 active-HIGH output control signals ($O_7$ to $O_1$):

$$O_1 = \overline{I_2} \cdot \overline{I_1} \cdot I_0 \quad (\text{Active for } 001_2 = 1)$$

$$O_2 = \overline{I_2} \cdot I_1 \cdot \overline{I_0} \quad (\text{Active for } 010_2 = 2)$$

$$O_3 = \overline{I_2} \cdot I_1 \cdot I_0 \quad (\text{Active for } 011_2 = 3)$$

$$O_4 = I_2 \cdot \overline{I_1} \cdot \overline{I_0} \quad (\text{Active for } 100_2 = 4)$$

$$O_5 = I_2 \cdot \overline{I_1} \cdot I_0 \quad (\text{Active for } 101_2 = 5)$$

$$O_6 = I_2 \cdot I_1 \cdot \overline{I_0} \quad (\text{Active for } 110_2 = 6)$$

$$O_7 = I_2 \cdot I_1 \cdot I_0 \quad (\text{Active for } 111_2 = 7)$$
