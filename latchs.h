#ifndef LATCHS
#define LATCHS

typedef struct {
  int q;
  int q_bar;
} LatchState;

#define DEFAULT_LATCHS_STATE {.q = 0, .q_bar = 1}

LatchState SRLATCH(LatchState *state, int s, int r);

#endif
