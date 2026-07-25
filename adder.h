#ifndef ADDER
#define ADDER

typedef struct {
  int sum;
  int carry;
} AdderOutput;

AdderOutput HALF_ADDER(int a, int b);


AdderOutput FULL_ADDER(int a, int b, int c);
#endif