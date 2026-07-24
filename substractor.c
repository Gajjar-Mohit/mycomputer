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