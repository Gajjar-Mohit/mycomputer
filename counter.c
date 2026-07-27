// Implementing binary counter using JK Flipflop

#include "clock.h"
#include "flipflops.h"
#include <stdio.h>

typedef struct {
  int q0, q1, q2, q3;
} CounterOutput;

CounterOutput count(int bit, int high) {
  CounterOutput result;
  printf("Clock: %d\n", bit);
  result.q0 = JKFLIPFLOP(high, high, bit).Qn;
  printf("Result Q0: %d\n", result.q0);
  result.q1 = JKFLIPFLOP(high, high, result.q0).Qn;
  printf("Result Q1: %d\n", result.q1);
  result.q2 = JKFLIPFLOP(high, high, result.q1).Qn;
  printf("Result Q2: %d\n", result.q2);
  result.q3 = JKFLIPFLOP(high, high, result.q2).Qn;
  printf("Result Q3: %d\n", result.q3);
  return result;
}