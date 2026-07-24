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

FlipFlopOutput SRFLIPFLOP(int s, int r, int clk) {
  FlipFlopOutput result;
  LatchOutput latch;
  int temp1, temp2;
  temp1 = NAND(s, clk);
  temp2 = NAND(r, clk);
  latch = SRLATCH(temp1, temp2);
  result.Qn = latch.Qn;
  result.Qn_1 = latch.Qn_1;
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

FlipFlopOutput JKFLIPFLOP(int j, int k, int clk) {
  FlipFlopOutput result;

  int q_prev = SRLATCH(1, 1).Qn;
  int q_bar_prev = SRLATCH(1, 1).Qn_1;

  int s_prime = NAND(AND(j, clk), q_bar_prev);
  int r_prime = NAND(AND(k, clk), q_prev);

  LatchOutput latch = SRLATCH(s_prime, r_prime);

  result.Qn = latch.Qn;
  result.Qn_1 = latch.Qn_1;
  return result;
}