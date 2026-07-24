// Implementation of multiplexer using logic gates
#include "gates.h"
#include <stdio.h>

// ========================================
/**
Circuit: Multiplexer
Input: 0 | Output: 4

s0 | s1 | o1 | o2 | o3 | o4 |
-----------------------------
 0 | 0  | 1  | 0  | 0  |  0 |
 0 | 1  | 0  | 1  | 0  |  0 |
 1 | 0  | 0  | 0  | 1  |  0 |
 1 | 1  | 0  | 0  | 0  |  1 |
*/

int MUX_4X1(int i1, int i2, int i3, int i4, int s0, int s1) {
  int a, b, c, d;
  a = AND(AND(!s0, !s1), i1);
  b = AND(AND(s0, !s1), i2);
  c = AND(AND(!s0, s1), i3);
  d = AND(AND(s0, s1), i4);
  return OR(OR(OR(a, b), c), d);
}

// ========================================
/**
Circuit: Multiplexer
Input: 1 | Output: 2

 s | o1 | o2 |
---------------
 1 |  1 | 0  |
 0 |  0 | 1  |
*/

int MUX_2X1(int i1, int i2, int s0) {
  int a, b;
  a = AND(!s0, i1);
  b = AND(s0, i2);
  return OR(a, b);
}