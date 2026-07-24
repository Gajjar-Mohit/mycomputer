#ifndef ADDER
#define ADDER

typedef struct {
  int sum;
  int carry;
} HalfAdderOutput;

HalfAdderOutput HALF_ADDER(int a, int b);

#endif