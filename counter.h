
#ifndef COUNTER
#define COUNTER
#include "clock.h"
#include "flipflops.h"
typedef struct {
  int q0, q1, q2, q3;
} CounterOutput;

typedef struct {
  FlipFlopState ff0;
  FlipFlopState ff1;
  FlipFlopState ff2;
  FlipFlopState ff3;
} CounterState;

#define DEFAULT_COUNTER_STATE                                                  \
  {.ff0 = DEFAULT_FF_STATE,                                                    \
   .ff1 = DEFAULT_FF_STATE,                                                    \
   .ff2 = DEFAULT_FF_STATE,                                                    \
   .ff3 = DEFAULT_FF_STATE}

#define DEFAULT_MS_COUNTER_STATE                                                  \
  {.ff0 = DEFAULT_MS_FF_STATE,                                                    \
   .ff1 = DEFAULT_MS_FF_STATE,                                                    \
   .ff2 = DEFAULT_MS_FF_STATE,                                                    \
   .ff3 = DEFAULT_MS_FF_STATE}

CounterOutput count(CounterState *counter_state, int bit, int high);

#endif