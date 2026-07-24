#ifndef FLIPFLOPS
#define FLIPFLOPS

typedef struct {
  int Qn, Qn_1;
} FlipFlopOutput;

FlipFlopOutput SRFLIPFLOP(int s, int r, int clk);
FlipFlopOutput JKFLIPFLOP(int j, int k, int clk);

#endif
