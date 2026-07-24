#ifndef ADDER
#define ADDER

typedef struct {
  int sum;
  int carry;
} HalfAdderOutput;

HalfAdderOutput HALF_ADDER(int a, int b);

typedef struct {
  int sum;
  int carry;
} FullAdderOutput;

FullAdderOutput FULL_ADDER(int a, int b, int c);
#endif