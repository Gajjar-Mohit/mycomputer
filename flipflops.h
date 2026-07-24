#ifndef FLIPFLOPS_H
#define FLIPFLOPS_H

typedef struct {
  int Qn;    // Q output
  int Qn_1;  // Q_bar output
} SRLatchOutput;

SRLatchOutput SRLATCH(int s, int r);

#endif
