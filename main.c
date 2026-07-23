#include "adder.h"
#include "gates.h"
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

  int sum1;
  int carry1;
  HALF_ADDER(0, 0, &sum1, &carry1);

  int sum2;
  int carry2;
  HALF_ADDER(0, 1, &sum2, &carry2);

  int sum3;
  int carry3;
  HALF_ADDER(1, 0, &sum3, &carry3);

  int sum4;
  int carry4;
  HALF_ADDER(1, 1, &sum4, &carry4);

  printf("A | B | Carry | Sum\n");
  printf("0   0     %d      %d\n", carry1, sum1);
  printf("0   1     %d      %d\n", carry2, sum2);
  printf("1   0     %d      %d\n", carry3, sum3);
  printf("1   1     %d      %d\n", carry4, sum4);

  printf("========================================\n");

  return 0;
}
