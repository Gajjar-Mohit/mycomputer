#ifndef LATCHS
#define LATCHS

typedef struct {
  int Qn;
  int Qn_1;
} LatchOutput;

LatchOutput SRLATCH(int s, int r);

#endif
