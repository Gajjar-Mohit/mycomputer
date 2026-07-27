#ifndef CLOCK
#define CLOCK

typedef struct {
  int state;
} Clock;

void clock_init(Clock *clk);
int clock_tick(Clock *clk);

#endif