// Implementation of Adder circuit using login gates

#include "gates.h"
#include <stdio.h>

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
} HalfAdderOutput;

HalfAdderOutput HALF_ADDER(int a, int b) {
  HalfAdderOutput result;
  result.sum = OR(AND(!a, b), AND(a, !b));
  result.carry = AND(a, b);
  return result;
}