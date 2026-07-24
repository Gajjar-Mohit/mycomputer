#include "adder.h"
#include "gates.h"
#include "substractor.h"
#include <stdio.h>

int main() {
  printf("========================================\n");

  printf("Testing AND gate\n");
  int output1 = AND(0, 0);
  int output2 = AND(0, 1);
  int output3 = AND(1, 0);
  int output4 = AND(1, 1);
  printf("0 0 -> %d\n", output1);
  printf("0 1 -> %d\n", output2);
  printf("1 0 -> %d\n", output3);
  printf("1 1 -> %d\n", output4);

  printf("========================================\n");
  printf("Testing OR gate\n");
  output1 = OR(0, 0);
  output2 = OR(0, 1);
  output3 = OR(1, 0);
  output4 = OR(1, 1);
  printf("0 0 -> %d\n", output1);
  printf("0 1 -> %d\n", output2);
  printf("1 0 -> %d\n", output3);
  printf("1 1 -> %d\n", output4);

  printf("========================================\n");

  printf("Testing NOT gate\n");
  output1 = NOT(0);
  output2 = NOT(1);
  printf("0 -> %d\n", output1);
  printf("1 -> %d\n", output2);

  printf("========================================\n");
  printf("Testing NOR gate\n");
  output1 = NOR(0, 0);
  output2 = NOR(0, 1);
  output3 = NOR(1, 0);
  output4 = NOR(1, 1);
  printf("0 0 -> %d\n", output1);
  printf("0 1 -> %d\n", output2);
  printf("1 0 -> %d\n", output3);
  printf("1 1 -> %d\n", output4);

  printf("========================================\n");
  printf("Testing NAND gate\n");
  output1 = NAND(0, 0);
  output2 = NAND(0, 1);
  output3 = NAND(1, 0);
  output4 = NAND(1, 1);
  printf("0 0 -> %d\n", output1);
  printf("0 1 -> %d\n", output2);
  printf("1 0 -> %d\n", output3);
  printf("1 1 -> %d\n", output4);

  printf("========================================\n");
  printf("Testing XOR gate\n");
  output1 = XOR(0, 0);
  output2 = XOR(0, 1);
  output3 = XOR(1, 0);
  output4 = XOR(1, 1);
  printf("0 0 -> %d\n", output1);
  printf("0 1 -> %d\n", output2);
  printf("1 0 -> %d\n", output3);
  printf("1 1 -> %d\n", output4);

  printf("========================================\n");
  printf("Testing XNOR gate\n");
  output1 = XNOR(0, 0);
  output2 = XNOR(0, 1);
  output3 = XNOR(1, 0);
  output4 = XNOR(1, 1);
  printf("0 0 -> %d\n", output1);
  printf("0 1 -> %d\n", output2);
  printf("1 0 -> %d\n", output3);
  printf("1 1 -> %d\n", output4);

  printf("========================================\n");
  printf("Testing HALF-ADDER Circuit\n");

  printf("A | B | Carry | Sum\n");
  HalfAdderOutput half_adder_output;
  half_adder_output = HALF_ADDER(0, 0);
  printf("0   0     %d      %d\n", half_adder_output.sum,
         half_adder_output.carry);

  half_adder_output = HALF_ADDER(0, 1);
  printf("0   1     %d      %d\n", half_adder_output.sum,
         half_adder_output.carry);

  half_adder_output = HALF_ADDER(1, 0);
  printf("1   0     %d      %d\n", half_adder_output.sum,
         half_adder_output.carry);

  half_adder_output = HALF_ADDER(1, 1);
  printf("1   1     %d      %d\n", half_adder_output.sum,
         half_adder_output.carry);

  printf("========================================\n");
  printf("Testing FULL-ADDER Circuit\n");

  printf("A | B | C | Carry | Sum\n");
  FullAdderOutput full_adder_output;
  full_adder_output = FULL_ADDER(0, 0, 0);
  printf("0   0   0     %d      %d\n", full_adder_output.carry,
         full_adder_output.sum);

  full_adder_output = FULL_ADDER(0, 0, 1);
  printf("0   0   1     %d      %d\n", full_adder_output.carry,
         full_adder_output.sum);

  full_adder_output = FULL_ADDER(0, 1, 0);
  printf("0   1   0     %d      %d\n", full_adder_output.carry,
         full_adder_output.sum);

  full_adder_output = FULL_ADDER(0, 1, 1);
  printf("0   1   1     %d      %d\n", full_adder_output.carry,
         full_adder_output.sum);

  full_adder_output = FULL_ADDER(1, 0, 0);
  printf("1   0   0     %d      %d\n", full_adder_output.carry,
         full_adder_output.sum);

  full_adder_output = FULL_ADDER(1, 0, 1);
  printf("1   0   1     %d      %d\n", full_adder_output.carry,
         full_adder_output.carry);

  full_adder_output = FULL_ADDER(1, 1, 0);
  printf("1   1   0     %d      %d\n", full_adder_output.carry,
         full_adder_output.sum);

  full_adder_output = FULL_ADDER(1, 1, 1);
  printf("1   1   1     %d      %d\n", full_adder_output.carry,
         full_adder_output.sum);

  printf("========================================\n");
  printf("Testing HALF-SUBSTRACTOR Circuit\n");

  printf("A | B | Borrow | Substraction\n");
  HalfSubstractorOutput half_substractor_output;
  half_substractor_output = HALF_SUBSTRACTOR(0, 0);
  printf("0   0     %d          %d\n", half_substractor_output.borrow,
         half_substractor_output.substraction);

  half_substractor_output = HALF_SUBSTRACTOR(0, 1);
  printf("0   1     %d          %d\n", half_substractor_output.borrow,
         half_substractor_output.substraction);

  half_substractor_output = HALF_SUBSTRACTOR(1, 0);
  printf("1   0     %d          %d\n", half_substractor_output.borrow,
         half_substractor_output.substraction);

  half_substractor_output = HALF_SUBSTRACTOR(1, 1);
  printf("1   1     %d          %d\n", half_substractor_output.borrow,
         half_substractor_output.substraction);

  printf("========================================\n");
  printf("Testing FULL-SUBSTRACTOR Circuit\n");

  printf("A | B | C | Borrow | Substraction\n");
  FullSubstractorOutput full_substractor_output;
  full_substractor_output = FULL_SUBSTRACTOR(0, 0, 0);
  printf("0   0   0     %d          %d\n", full_substractor_output.borrow,
         full_substractor_output.substraction);

  full_substractor_output = FULL_SUBSTRACTOR(0, 0, 1);
  printf("0   0   1     %d          %d\n", full_substractor_output.borrow,
         full_substractor_output.substraction);

  full_substractor_output = FULL_SUBSTRACTOR(0, 1, 0);
  printf("0   1   0     %d          %d\n", full_substractor_output.borrow,
         full_substractor_output.substraction);

  full_substractor_output = FULL_SUBSTRACTOR(0, 1, 1);
  printf("0   1   1     %d          %d\n", full_substractor_output.borrow,
         full_substractor_output.substraction);

  full_substractor_output = FULL_SUBSTRACTOR(1, 0, 0);
  printf("1   0   0     %d          %d\n", full_substractor_output.borrow,
         full_substractor_output.substraction);

  full_substractor_output = FULL_SUBSTRACTOR(1, 0, 1);
  printf("1   0   1     %d          %d\n", full_substractor_output.borrow,
         full_substractor_output.substraction);

  full_substractor_output = FULL_SUBSTRACTOR(1, 1, 0);
  printf("1   1   0     %d          %d\n", full_substractor_output.borrow,
         full_substractor_output.substraction);

  full_substractor_output = FULL_SUBSTRACTOR(1, 1, 1);
  printf("1   1   1     %d          %d\n", full_substractor_output.borrow,
         full_substractor_output.substraction);

  printf("========================================\n");

  return 0;
}
