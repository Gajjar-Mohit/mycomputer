#ifndef DEMULTIPLEXER
#define DEMULTIPLEXER

typedef struct {
  int o1;
  int o2;
  int o3;
  int o4;
} Demux1x4Output;

Demux1x4Output DEMUX_1X4(int i, int o1, int o2, int o3, int o4, int s0, int s1);

typedef struct {
  int o1, o2;
} Demux1x2Output;

Demux1x2Output DEMUX_1X2(int i, int s0);

#endif