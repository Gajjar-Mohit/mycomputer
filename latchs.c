// Implemented flipflops using logic gates

#include "latchs.h"
#include "gates.h"
#include <stdio.h>

/**
Latch: SR (NAND Active-Low Latch)
S | R | Qn | Qn_bar | State
-----------------------------
0 | 0 | 1  |   1    | Invalid
0 | 1 | 1  |   0    | Set
1 | 0 | 0  |   1    | Reset
1 | 1 | Q  |   Q'   | Hold
*/

LatchState SRLATCH(LatchState *state, int s, int r) {
  // static int q = 0, q_bar = 1;
  LatchState result;

  int next_q = NAND(s, state->q_bar);
  int next_q_bar = NAND(r, next_q);
  next_q = NAND(s, next_q_bar);
  next_q_bar = NAND(r, next_q);

  state->q = next_q;
  state->q_bar = next_q_bar;

  result.q = state->q;
  result.q_bar = state->q_bar;
  return result;
}
