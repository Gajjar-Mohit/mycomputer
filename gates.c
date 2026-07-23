// Implementation of logic gates
#include <stdio.h>

int AND(int, int);
int OR(int, int);
int NOT(int);
int NOR(int, int);
int NAND(int, int);
int XOR(int, int);
int XNOR(int, int);

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
