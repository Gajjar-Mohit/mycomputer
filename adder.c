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

void HALF_ADDER(int a, int b, int *sum, int *carry) {
  *sum = OR(AND(!a, b), AND(a, !b));
  *carry = AND(a, b);
}