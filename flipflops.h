#ifndef FLIPFLOPS
#define FLIPFLOPS

#include "latchs.h"
typedef struct {
  int Qn, Qn_1;
} FlipFlopOutput;

typedef struct {
  LatchState latch_state;
} FlipFlopState;

#define DEFAULT_FF_STATE {.latch_state = DEFAULT_LATCHS_STATE}

FlipFlopOutput SRFLIPFLOP(FlipFlopState *ff, int s, int r, int clk);
FlipFlopOutput JKFLIPFLOP(FlipFlopState *ff, int j, int k, int clk);

#endif
