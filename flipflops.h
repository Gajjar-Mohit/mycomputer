#ifndef FLIPFLOPS
#define FLIPFLOPS

#include "latchs.h"
typedef struct {
  int Qn, Qn_bar;
} FlipFlopOutput;

typedef struct {
  LatchState latch_state;
} FlipFlopState;

typedef struct {
  FlipFlopState master, slave;
} MasterSlaceFlipFlopState;

#define DEFAULT_FF_STATE {.latch_state = DEFAULT_LATCHS_STATE}
#define DEFAULT_MS_FF_STATE                                                    \
  {.master = DEFAULT_FF_STATE, .slave = DEFAULT_FF_STATE}

FlipFlopOutput SRFLIPFLOP(FlipFlopState *ff, int s, int r, int clk);
FlipFlopOutput JKFLIPFLOP(FlipFlopState *ff, int j, int k, int clk);
FlipFlopOutput MASTERSLAVEFLIOPFLOP(MasterSlaceFlipFlopState *ff, int s, int r,
                                    int clk);

FlipFlopOutput DFLIPFLOP(FlipFlopState *ff, int d, int clk);

#endif
