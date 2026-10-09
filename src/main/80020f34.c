/* Main-exec function func_80020F34 from the SLUS executable (clean room, owner).
 * Scales the columns of the 3x3 s16 matrix m by the s16 factors s (one GTE
 * GPF per column, sf=1): m[i][k] = sat16((s[k] * m[i][k]) >> 12). The words
 * are hand-scheduled GTE code with no frame, so the body is one asm
 * statement on the argument registers. */
#include "psx_types.h"

/* GTE command mnemonics (gpf, ...) come from include/gte_macros.inc. */
__asm__(".include \"gte_macros.inc\"\n");

void func_80020F34(s16 *m, s16 *s)
{
    __asm__ __volatile__(
        "lh $8, 0(%1)\n"
        "lh $9, 0(%0)\n"
        "lh $10, 6(%0)\n"
        "lh $11, 12(%0)\n"
        "mtc2 $8, $8\n"
        "mtc2 $9, $9\n"
        "mtc2 $10, $10\n"
        "mtc2 $11, $11\n"
        "nop\n"
        "nop\n"
        "gpf 1\n"
        "lh $8, 2(%1)\n"
        "lh $9, 2(%0)\n"
        "lh $10, 8(%0)\n"
        "lh $11, 14(%0)\n"
        "mfc2 $12, $9\n"
        "mfc2 $13, $10\n"
        "mfc2 $14, $11\n"
        "sh $12, 0(%0)\n"
        "sh $13, 6(%0)\n"
        "sh $14, 12(%0)\n"
        "mtc2 $8, $8\n"
        "mtc2 $9, $9\n"
        "mtc2 $10, $10\n"
        "mtc2 $11, $11\n"
        "nop\n"
        "nop\n"
        "gpf 1\n"
        "lh $8, 4(%1)\n"
        "lh $9, 4(%0)\n"
        "lh $10, 10(%0)\n"
        "lh $11, 16(%0)\n"
        "mfc2 $12, $9\n"
        "mfc2 $13, $10\n"
        "mfc2 $14, $11\n"
        "sh $12, 2(%0)\n"
        "sh $13, 8(%0)\n"
        "sh $14, 14(%0)\n"
        "mtc2 $8, $8\n"
        "mtc2 $9, $9\n"
        "mtc2 $10, $10\n"
        "mtc2 $11, $11\n"
        "nop\n"
        "nop\n"
        "gpf 1\n"
        "mfc2 $12, $9\n"
        "mfc2 $13, $10\n"
        "mfc2 $14, $11\n"
        "sh $12, 4(%0)\n"
        "sh $13, 10(%0)\n"
        "sh $14, 16(%0)\n"
        : : "r"(m), "r"(s) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "memory");
}
