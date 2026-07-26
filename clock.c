// Implementation of clock oscillation
#include <stdio.h>

typedef int bit;

typedef struct {
  bit state;
} Clock;

void clock_init(Clock *clk) { clk->state = 0; }

bit clock_tick(Clock *clk) {
  clk->state = !clk->state;
  return clk->state;
}
