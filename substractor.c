// Implementation of Substractor circuit using login gates

#include "gates.h"
#include <stdio.h>

// ========================================

/**
Half substractor cicuit

A | B | Borrow | Substraction
-----------------------------
0 | 0 |   0    |      0
0 | 1 |   1    |      1
1 | 0 |   0    |      1
1 | 1 |   0    |      0

Equation: Borrow = A'.B | Substraction = A'.B + A.B'

*/

typedef struct {
  int borrow;
  int substraction;
} HalfSubstractorOutput;

HalfSubstractorOutput HALF_SUBSTRACTOR(int a, int b) {
  HalfSubstractorOutput result;
  result.substraction = XOR(a, b);
  result.borrow = AND(!a, b);
  return result;
}

// ========================================

/**
Full Substractor cicuit

A | B | C | Borrow | Substraction
----------------------------------
0 | 0 | 0 |    0    |      0
0 | 0 | 1 |    0    |      1
0 | 1 | 0 |    0    |      1
0 | 1 | 1 |    1    |      0
1 | 0 | 0 |    0    |      1
1 | 0 | 1 |    1    |      0
1 | 1 | 0 |    1    |      0
1 | 1 | 1 |    1    |      1


Equation: BORROW = A'.C + B.A' + B.C | SUBSTRACTION = A ⊕ B ⊕ C

*/

typedef struct {
  int borrow;
  int substraction;
} FullSubstractorOutput;

FullSubstractorOutput FULL_SUBSTRACTOR(int a, int b, int c) {
  FullSubstractorOutput result;
  HalfSubstractorOutput half_substractor_1, half_substractor_2;
  half_substractor_1 = HALF_SUBSTRACTOR(a, b);
  half_substractor_2 = HALF_SUBSTRACTOR(half_substractor_1.substraction, c);

  result.substraction = half_substractor_2.substraction;
  result.borrow = OR(half_substractor_1.borrow, half_substractor_2.borrow);
  return result;
}