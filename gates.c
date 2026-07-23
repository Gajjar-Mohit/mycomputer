// Implementation of logic gates
#include <stdio.h>

int AND(int, int);
int OR(int, int);
int NOT(int);
int NOR(int, int);
int NAND(int, int);
int XOR(int, int);
int XNOR(int, int);

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

  printf("Testing AND gate\n");
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

  return 0;
}

// ========================================

/**
Gate: AND;
Expression: Y = A.B;
Truth Table: 0 0 -> 0 | 0 1 -> 0 | 1 0 -> 0 | 1 1 -> 1
*/

int AND(int a, int b) { return a & b; }

// ========================================

/**
Gate: OR;
Expression: Y = A + B;
Truth Table: 0 0 -> 0 | 0 1 -> 1 | 1 0 -> 1 | 1 1 -> 1
*/

int OR(int a, int b) { return a || b; }

// ========================================

/**
NOT GATE;
Y = A’;
0 -> 1;
1 -> 0;
*/

/**
Gate: XNOR;
Expression: Y = A';
Truth Table: 0 -> 1 | 1 -> 0
*/

int NOT(int a) { return !a; }

// ========================================

/**
NOR GATE;
Y = (A + B)’;
0 0-> 1;
0 1-> 0;
1 0-> 0;
1 1-> 0;
*/

/**
Gate: NOR;
Expression: Y = (A + B)’;
Truth Table: 0 0-> 1 | 0 1-> 0 | 1 0-> 0 | 1 1-> 0
*/

int NOR(int a, int b) { return !OR(a, b); }

// ========================================

/**
Gate: NAND;
Expression:Y = (A.B)’;
Truth Table: 0 0-> 1 | 0 1-> 1 | 1 0-> 1 | 1 1-> 0
*/

int NAND(int a, int b) { return !AND(a, b); }

// ========================================

/**
Gate: XOR;
Expression: Y = A’B + AB’;
Truth Table: 0 0-> 0 | 0 1-> 1| 1 0-> 1 | 1 1-> 0
*/

int XOR(int a, int b) {
  int x = AND(!a, b);
  int y = AND(a, !b);
  return OR(x, y);
}

// ========================================

/**
Gate: XNOR;
Expression: Y = AB + A’B’;
Truth Table: 0 0 -> 1 | 0 1 -> 0 | 1 0 -> 0 | 1 1 -> 1
*/

int XNOR(int a, int b) {
  int x = AND(a, b);
  int y = AND(!a, !b);
  return OR(x, y);
}

// ========================================
