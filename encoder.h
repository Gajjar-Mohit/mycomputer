#ifndef ENCODER
#define ENCODER

typedef struct {
  int a0, a1, a2;
} EncoderOutput;

EncoderOutput BIN_TO_BCD_ENCODER(int i7, int i6, int i5, int i4, int i3, int i2,
                                 int i1);

#endif