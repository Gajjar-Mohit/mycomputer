#ifndef SUBSTRACTOR
#define SUBSTRACTOR

typedef struct {
  int borrow;
  int substraction;
} HalfSubstractorOutput;

HalfSubstractorOutput HALF_SUBSTRACTOR(int a, int b);

typedef struct {
  int borrow;
  int substraction;
} FullSubstractorOutput;

FullSubstractorOutput FULL_SUBSTRACTOR(int a, int b, int c);
#endif