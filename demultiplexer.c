// Implementation of demultiplexer using logic gates

#include "gates.h"
#include <stdio.h>

// ========================================
/**
Circuit: Demultiplexer
Input: 2 | Output: 4

i | s0 | s1 | o1 | o2 | o3 | o4 |
-----------------------------
1   0 | 0  | 1  | 0  | 0  |  0 |
1   0 | 1  | 0  | 1  | 0  |  0 |
1   1 | 0  | 0  | 0  | 1  |  0 |
1   1 | 1  | 0  | 0  | 0  |  1 |
*/

typedef struct {
  int o1;
  int o2;
  int o3;
  int o4;
} Demux1x4Output;

Demux1x4Output DEMUX_1X4(int i, int o1, int o2, int o3, int o4, int s0,
                         int s1) {
  Demux1x4Output result;
  result.o1 = AND(AND(!s0, !s1), i);
  result.o2 = AND(AND(s0, !s1), i);
  result.o3 = AND(AND(!s0, s1), i);
  result.o4 = AND(AND(s0, s1), i);
  return result;
}

// ========================================
/**
Circuit: Demultiplexer
Input: 1 | Output: 2

 i | s |  o1  |  o2
-----------------
 1 | 1 |   1  |   0
 1 | 0 |   0  |   1
*/

typedef struct {
  int o1, o2;
} Demux1x2Output;

Demux1x2Output MUX_2X1(int i, int s0) {
  Demux1x2Output result;
  result.o1 = AND(!s0, i);
  result.o2 = AND(s0, i);
  return result;
}