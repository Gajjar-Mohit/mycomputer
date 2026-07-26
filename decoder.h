#ifndef DECODER
#define DECODER

typedef struct {
  int o1, o2, o3, o4, o5, o6, o7;
} DecoderOutput;

DecoderOutput BCD_TO_BIN_DECODER(int i2, int i1, int i0);

#endif