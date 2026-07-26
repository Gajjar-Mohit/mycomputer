// Implementation of encoder using simple circuits

#include "gates.h"
#include <stdio.h>

typedef struct {
  int a0, a1, a2;
} EncoderOutput;

EncoderOutput BIN_TO_BCD_ENCODER(int i7, int i6, int i5, int i4, int i3, int i2,
                                 int i1) {
  EncoderOutput result;
  result.a0 = OR(i1, OR(i3, OR(i5, i7)));
  result.a1 = OR(i2, OR(i3, OR(i6, i7)));
  result.a2 = OR(i4, OR(i5, OR(i6, i7)));
  return result;
}