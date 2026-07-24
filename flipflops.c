// Implemented flipflops using logic gates

#include "flipflops.h"
#include "gates.h"
#include <stdio.h>

/**
Flipflop / Latch: SR (NAND Active-Low Latch)
S | R | Qn | Qn_bar | State
-----------------------------
0 | 0 | 1  |   1    | Invalid
0 | 1 | 1  |   0    | Set
1 | 0 | 0  |   1    | Reset
1 | 1 | Q  |   Q'   | Hold
*/

SRLatchOutput SRLATCH(int s, int r) {
  static int q = 0, q_bar = 1;
  SRLatchOutput result;

  int next_q = NAND(s, q_bar);
  int next_q_bar = NAND(r, next_q);
  next_q = NAND(s, next_q_bar);
  next_q_bar = NAND(r, next_q);

  q = next_q;
  q_bar = next_q_bar;

  result.Qn = q;
  result.Qn_1 = q_bar;
  return result;
}