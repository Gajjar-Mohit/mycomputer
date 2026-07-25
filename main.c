#include "adder.h"
#include "demultiplexer.h"
#include "flipflops.h"
#include "gates.h"
#include "latchs.h"
#include "multiplexer.h"
#include "substractor.h"
#include <stdio.h>

void test_gates(void) {
  printf("==================================================\n");
  printf("                 LOGIC GATES TEST                 \n");
  printf("==================================================\n\n");

  printf("--- AND Gate ---\n");
  printf(" A | B | Output\n");
  printf("---+---+--------\n");
  for (int a = 0; a <= 1; a++) {
    for (int b = 0; b <= 1; b++) {
      printf(" %d | %d |   %d\n", a, b, AND(a, b));
    }
  }
  printf("\n");

  printf("--- OR Gate ---\n");
  printf(" A | B | Output\n");
  printf("---+---+--------\n");
  for (int a = 0; a <= 1; a++) {
    for (int b = 0; b <= 1; b++) {
      printf(" %d | %d |   %d\n", a, b, OR(a, b));
    }
  }
  printf("\n");

  printf("--- NOT Gate ---\n");
  printf(" A | Output\n");
  printf("---+--------\n");
  for (int a = 0; a <= 1; a++) {
    printf(" %d |   %d\n", a, NOT(a));
  }
  printf("\n");

  printf("--- NOR Gate ---\n");
  printf(" A | B | Output\n");
  printf("---+---+--------\n");
  for (int a = 0; a <= 1; a++) {
    for (int b = 0; b <= 1; b++) {
      printf(" %d | %d |   %d\n", a, b, NOR(a, b));
    }
  }
  printf("\n");

  printf("--- NAND Gate ---\n");
  printf(" A | B | Output\n");
  printf("---+---+--------\n");
  for (int a = 0; a <= 1; a++) {
    for (int b = 0; b <= 1; b++) {
      printf(" %d | %d |   %d\n", a, b, NAND(a, b));
    }
  }
  printf("\n");

  printf("--- XOR Gate ---\n");
  printf(" A | B | Output\n");
  printf("---+---+--------\n");
  for (int a = 0; a <= 1; a++) {
    for (int b = 0; b <= 1; b++) {
      printf(" %d | %d |   %d\n", a, b, XOR(a, b));
    }
  }
  printf("\n");

  printf("--- XNOR Gate ---\n");
  printf(" A | B | Output\n");
  printf("---+---+--------\n");
  for (int a = 0; a <= 1; a++) {
    for (int b = 0; b <= 1; b++) {
      printf(" %d | %d |   %d\n", a, b, XNOR(a, b));
    }
  }
  printf("\n");
}

void test_adders(void) {
  printf("==================================================\n");
  printf("                ADDER CIRCUITS TEST               \n");
  printf("==================================================\n\n");

  printf("--- HALF-ADDER Circuit ---\n");
  printf(" A | B | Carry | Sum\n");
  printf("---+---+-------+-----\n");
  for (int a = 0; a <= 1; a++) {
    for (int b = 0; b <= 1; b++) {
      AdderOutput out = HALF_ADDER(a, b);
      printf(" %d | %d |   %d   |  %d\n", a, b, out.carry, out.sum);
    }
  }
  printf("\n");

  printf("--- FULL-ADDER Circuit ---\n");
  printf(" A | B | C | Carry | Sum\n");
  printf("---+---+---+-------+-----\n");
  for (int a = 0; a <= 1; a++) {
    for (int b = 0; b <= 1; b++) {
      for (int c = 0; c <= 1; c++) {
        AdderOutput out = FULL_ADDER(a, b, c);
        printf(" %d | %d | %d |   %d   |  %d\n", a, b, c, out.carry, out.sum);
      }
    }
  }
  printf("\n");
}

void test_subtractors(void) {
  printf("==================================================\n");
  printf("             SUBTRACTOR CIRCUITS TEST             \n");
  printf("==================================================\n\n");

  printf("--- HALF-SUBTRACTOR Circuit ---\n");
  printf(" A | B | Borrow | Subtraction\n");
  printf("---+---+--------+-------------\n");
  for (int a = 0; a <= 1; a++) {
    for (int b = 0; b <= 1; b++) {
      HalfSubstractorOutput out = HALF_SUBSTRACTOR(a, b);
      printf(" %d | %d |   %d    |      %d\n", a, b, out.borrow,
             out.substraction);
    }
  }
  printf("\n");

  printf("--- FULL-SUBTRACTOR Circuit ---\n");
  printf(" A | B | C | Borrow | Subtraction\n");
  printf("---+---+---+--------+-------------\n");
  for (int a = 0; a <= 1; a++) {
    for (int b = 0; b <= 1; b++) {
      for (int c = 0; c <= 1; c++) {
        FullSubstractorOutput out = FULL_SUBSTRACTOR(a, b, c);
        printf(" %d | %d | %d |   %d    |      %d\n", a, b, c, out.borrow,
               out.substraction);
      }
    }
  }
  printf("\n");
}

void test_multiplexers(void) {
  printf("==================================================\n");
  printf("            MULTIPLEXER CIRCUITS TEST             \n");
  printf("==================================================\n\n");

  printf("--- 2 X 1 MUX Circuit ---\n");
  printf(" I1 | I2 | S0 | Output\n");
  printf("----+----+----+--------\n");
  int i1_2 = 1, i2_2 = 0;
  for (int s0 = 0; s0 <= 1; s0++) {
    printf("  %d |  %d |  %d |   %d\n", i1_2, i2_2, s0,
           MUX_2X1(i1_2, i2_2, s0));
  }
  i1_2 = 0;
  i2_2 = 1;
  for (int s0 = 0; s0 <= 1; s0++) {
    printf("  %d |  %d |  %d |   %d\n", i1_2, i2_2, s0,
           MUX_2X1(i1_2, i2_2, s0));
  }
  printf("\n");

  printf("--- 4 X 1 MUX Circuit ---\n");
  printf(" I1 | I2 | I3 | I4 | S0 | S1 | Output\n");
  printf("----+----+----+----+----+----+--------\n");
  int i1 = 1, i2 = 0, i3 = 1, i4 = 0;
  for (int s1 = 0; s1 <= 1; s1++) {
    for (int s0 = 0; s0 <= 1; s0++) {
      printf("  %d |  %d |  %d |  %d |  %d |  %d |   %d\n", i1, i2, i3, i4, s0,
             s1, MUX_4X1(i1, i2, i3, i4, s0, s1));
    }
  }
  printf("\n");
}

void test_demultiplexers(void) {
  printf("==================================================\n");
  printf("           DEMULTIPLEXER CIRCUITS TEST            \n");
  printf("==================================================\n\n");

  printf("--- 1 X 2 DEMUX Circuit ---\n");
  printf(" I | S0 | O1 | O2\n");
  printf("---+----+----+----\n");
  int input = 1;
  for (int s0 = 0; s0 <= 1; s0++) {
    Demux1x2Output out = DEMUX_1X2(input, s0);
    printf(" %d |  %d |  %d |  %d\n", input, s0, out.o1, out.o2);
  }
  printf("\n");

  printf("--- 1 X 4 DEMUX Circuit ---\n");
  printf(" I | S0 | S1 | O1 | O2 | O3 | O4\n");
  printf("---+----+----+----+----+----+----\n");
  for (int s1 = 0; s1 <= 1; s1++) {
    for (int s0 = 0; s0 <= 1; s0++) {
      Demux1x4Output out = DEMUX_1X4(input, 0, 0, 0, 0, s0, s1);
      printf(" %d |  %d |  %d |  %d |  %d |  %d |  %d\n", input, s0, s1, out.o1,
             out.o2, out.o3, out.o4);
    }
  }
  printf("\n");
}

void test_flipflops(void) {
  printf("==================================================\n");
  printf("             FLIP-FLOPS / LATCHES TEST            \n");
  printf("==================================================\n\n");

  printf("--- SR LATCH (NAND Active-Low) ---\n");
  printf(" S | R | Qn | Qn_bar | State Description\n");
  printf("---+---+----+--------+-------------------\n");

  LatchOutput out = SRLATCH(0, 1);
  printf(" 0 | 1 |  %d |   %d    | Set (Q=1)\n", out.Qn, out.Qn_1);

  out = SRLATCH(1, 1);
  printf(" 1 | 1 |  %d |   %d    | Hold (Retains Q=1)\n", out.Qn, out.Qn_1);

  out = SRLATCH(1, 0);
  printf(" 1 | 0 |  %d |   %d    | Reset (Q=0)\n", out.Qn, out.Qn_1);

  out = SRLATCH(1, 1);
  printf(" 1 | 1 |  %d |   %d    | Hold (Retains Q=0)\n", out.Qn, out.Qn_1);

  out = SRLATCH(0, 0);
  printf(" 0 | 0 |  %d |   %d    | Invalid (Forbidden)\n", out.Qn, out.Qn_1);

  printf("\n");

  printf("--- SR FLIP-FLOP (Gated Clock) ---\n");
  printf(" CLK | S | R | Qn | Qn_bar | State Description\n");
  printf("-----+---+---+----+--------+-------------------\n");

  FlipFlopOutput ff_out = SRFLIPFLOP(1, 0, 0);
  printf("  0  | 1 | 0 |  %d |   %d    | Clock Off (Holds state)\n", ff_out.Qn,
         ff_out.Qn_1);

  ff_out = SRFLIPFLOP(1, 0, 1);
  printf("  1  | 1 | 0 |  %d |   %d    | Set (Q=1)\n", ff_out.Qn, ff_out.Qn_1);

  ff_out = SRFLIPFLOP(0, 0, 1);
  printf("  1  | 0 | 0 |  %d |   %d    | Hold (Retains Q=1)\n", ff_out.Qn,
         ff_out.Qn_1);

  ff_out = SRFLIPFLOP(0, 1, 1);
  printf("  1  | 0 | 1 |  %d |   %d    | Reset (Q=0)\n", ff_out.Qn,
         ff_out.Qn_1);

  ff_out = SRFLIPFLOP(0, 0, 1);
  printf("  1  | 0 | 0 |  %d |   %d    | Hold (Retains Q=0)\n", ff_out.Qn,
         ff_out.Qn_1);

  ff_out = SRFLIPFLOP(1, 1, 1);
  printf("  1  | 1 | 1 |  %d |   %d    | Invalid (Forbidden)\n", ff_out.Qn,
         ff_out.Qn_1);

  printf("\n");

  printf("--- JK FLIP-FLOP ---\n");
  printf(" CLK | J | K | Qn | Qn_bar | State Description\n");
  printf("-----+---+---+----+--------+-------------------\n");

  FlipFlopOutput jk_out = JKFLIPFLOP(1, 0, 0);
  printf("  0  | 1 | 0 |  %d |   %d    | Clock Off\n", jk_out.Qn, jk_out.Qn_1);

  jk_out = JKFLIPFLOP(0, 0, 1);
  printf("  1  | 0 | 0 |  %d |   %d    | Hold\n", jk_out.Qn, jk_out.Qn_1);

  jk_out = JKFLIPFLOP(1, 0, 1);
  printf("  1  | 1 | 0 |  %d |   %d    | Set (Q=1)\n", jk_out.Qn, jk_out.Qn_1);

  jk_out = JKFLIPFLOP(0, 1, 1);
  printf("  1  | 0 | 1 |  %d |   %d    | Reset (Q=0)\n", jk_out.Qn,
         jk_out.Qn_1);

  jk_out = JKFLIPFLOP(1, 1, 1);
  printf("  1  | 1 | 1 |  %d |   %d    | Toggle\n", jk_out.Qn, jk_out.Qn_1);

  printf("\n");
}

int main() {
  test_gates();
  test_adders();
  test_subtractors();
  test_multiplexers();
  test_demultiplexers();
  test_flipflops();

  return 0;
}
