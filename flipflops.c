// Implementation of flipflops using logic gates
#include "flipflops.h"
#include "gates.h"
#include "latchs.h"
#include <stdio.h>

/**
Flipflop: SR (NAND Active-Low Latch)
CLK | S | R |   Qn+1  | State
-----------------------------
 0  | x | x | Qn      | Off
 1  | 0 | 0 | hold    | Invalid
 1  | 0 | 1 | 0       | Set
 1  | 1 | 0 | 1       | Reset
 1  | 1 | 1 | Invalid | Hold
*/

FlipFlopOutput SRFLIPFLOP(FlipFlopState *ff, int s, int r, int clk) {
  FlipFlopOutput result;
  LatchState latch;
  int temp1, temp2;
  temp1 = NAND(s, clk);
  temp2 = NAND(r, clk);
  latch = SRLATCH(&ff->latch_state, temp1, temp2);
  result.Qn = latch.q;
  result.Qn_bar = latch.q_bar;
  return result;
}

/**
Flipflop: JK (NAND Active-Low Latch)
CLK | J | K |   Qn+1  | State
-----------------------------
 0  | x | x | Qn      | Off
 1  | 0 | 0 | hold    | Invalid
 1  | 0 | 1 | 0       | Set
 1  | 1 | 0 | 1       | Reset
 1  | 1 | 1 | 0       | toggle/flip
*/

FlipFlopOutput JKFLIPFLOP(FlipFlopState *ff, int j, int k, int clk) {
  FlipFlopOutput result;

  int q_prev = ff->latch_state.q;
  int q_bar_prev = ff->latch_state.q_bar;

  int s_prime = NAND(AND(j, clk), q_bar_prev);
  int r_prime = NAND(AND(k, clk), q_prev);

  LatchState latch = SRLATCH(&ff->latch_state, s_prime, r_prime);

  result.Qn = latch.q;
  result.Qn_bar = latch.q_bar;
  return result;
}

FlipFlopOutput MASTERSLAVEFLIOPFLOP(MasterSlaceFlipFlopState *ff, int s, int r,
                                    int clk) {
  FlipFlopOutput result;
  FlipFlopOutput fstSrFF;

  fstSrFF = JKFLIPFLOP(&ff->master, s, r, clk);
  result = JKFLIPFLOP(&ff->slave, fstSrFF.Qn, fstSrFF.Qn_bar, NOT(clk));
  return result;
}

FlipFlopOutput DFLIPFLOP(FlipFlopState *ff, int d, int clk) {
  FlipFlopOutput result;

  result = SRFLIPFLOP(ff, d, NOT(d), clk);

  return result;
}