
#ifndef COUNTER
#define COUNTER
#include "clock.h"
typedef struct {
  int q0, q1, q2, q3;
} CounterOutput;

CounterOutput count(int bit, int high);

#endif