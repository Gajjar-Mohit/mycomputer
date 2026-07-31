// Implementing binary counter using JK Flipflop

#include "counter.h"
#include "flipflops.h"
#include <stdio.h>

CounterOutput count(CounterState *counter, int clk, int high) {
  CounterOutput result;
  printf("Clock: %d\n", clk);
  // result.q0 = DFLIPFLOP(&counter->ff0, high, high, clk).Qn;
  // // printf("Result Q0: %d\n", result.q0);
  // result.q1 = DFLIPFLOP(&counter->ff1, high, high, result.q0).Qn;
  // // printf("Result Q1: %d\n", result.q1);
  // result.q2 = DFLIPFLOP(&counter->ff2, high, high, result.q1).Qn;
  // // printf("Result Q2: %d\n", result.q2);
  // result.q3 = DFLIPFLOP(&counter->ff3, high, high, result.q2).Qn;
  // // printf("Result Q3: %d\n", result.q3);
  result.q0 = 0;
  result.q3 = DFLIPFLOP(&counter->ff3, result.q0, clk).Qn;
  result.q2 = DFLIPFLOP(&counter->ff2, result.q3, clk).Qn;
  result.q1 = DFLIPFLOP(&counter->ff1, result.q2, clk).Qn;
  result.q0 = DFLIPFLOP(&counter->ff0, result.q1, clk).Qn;

  return result;
}