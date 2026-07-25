// Implementation of Adder circuit using login gates

#include "gates.h"
#include <stdio.h>

// ========================================

// void HALF_ADDER(int, int, int, int);
/**
Half adder cicuit

A | B | Carry | Sum
---------------------
0 | 0 |   0   |  0
0 | 1 |   0   |  1
1 | 0 |   0   |  1
1 | 1 |   1   |  0

Equation: CARRY = A.B | SUM = A'.B + A.B'

*/

typedef struct {
  int sum;
  int carry;
} AdderOutput;

AdderOutput HALF_ADDER(int a, int b) {
  AdderOutput result;
  result.sum = XOR(a, b);
  result.carry = AND(a, b);
  return result;
}

// ========================================

/**
Full adder cicuit

A | B | C | Carry | Sum
------------------------
0 | 0 | 0 |  0    |  0
0 | 0 | 1 |  0    |  1
0 | 1 | 0 |  0    |  1
0 | 1 | 1 |  1    |  0
1 | 0 | 0 |  0    |  1
1 | 0 | 1 |  1    |  0
1 | 1 | 0 |  1    |  0
1 | 1 | 1 |  1    |  1


Equation: CARRY = (A ⊕ B) C + A.B | SUM = A ⊕ B ⊕ C

*/

typedef struct {
  int sum;
  int carry;
} FullAdderOutput;

FullAdderOutput FULL_ADDER(int a, int b, int c) {
  FullAdderOutput result;
  AdderOutput halfadder1, halfadder2;
  halfadder1 = HALF_ADDER(a, b);
  halfadder2 = HALF_ADDER(halfadder1.sum, c);
  result.sum = halfadder2.sum;
  result.carry = OR(halfadder1.carry, halfadder2.carry);
  return result;
}

// ========================================