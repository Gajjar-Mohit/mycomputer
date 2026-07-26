// Implementation of decoder using simple circuits

#include "gates.h"
#include <stdio.h>

typedef struct {
  int o1, o2, o3, o4, o5, o6, o7;
} DecoderOutput;

DecoderOutput BCD_TO_BIN_DECODER(int i2, int i1, int i0) {
  DecoderOutput result;
  result.o1 = AND(!i2, AND(!i1, i0));
  result.o2 = AND(!i2, AND(i1, !i0));
  result.o3 = AND(!i2, AND(i1, i0));
  result.o4 = AND(i2, AND(!i1, !i0));
  result.o5 = AND(i2, AND(!i1, i0));
  result.o6 = AND(i2, AND(i1, !i0));
  result.o7 = AND(i2, AND(i1, i0));

  return result;
}