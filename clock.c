// Implementation of clock oscillation
#include <stdio.h>



typedef struct {
  int state;
} Clock;

void clock_init(Clock *clk) { clk->state = 0; }

int clock_tick(Clock *clk) {
  clk->state = !clk->state;
  return clk->state;
}
