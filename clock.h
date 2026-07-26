#ifndef CLOCK
#define CLOCK

typedef int bit;

typedef struct {
  bit state;
} Clock;

void clock_init(Clock *clk);
void clock_tick(Clock *clk);

#endif