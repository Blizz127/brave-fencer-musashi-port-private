/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* GTE mnemonic macros, copied from vendor/bfm-decomp/include/gte_macros.inc (assembler-only, emit no code). */
__asm__(
".macro cop2op fake_op, op, gbg = 0, sf = 1, mx = 0, v = 0, cv = 0, lm = 0\n"
"    cop2 \\fake_op << 20 | \\gbg << 20 | \\sf << 19 | \\mx << 17 | \\v << 15 | \\cv << 13 | \\lm << 10 | \\op\n"
".endm\n"
".macro sqr sf\n"
"    cop2op 0x0A, 0x28, sf = \\sf, lm = 1\n"
".endm\n"
);
/* func_8013E064 - byte-exact against retail at -O2 (tools/register_match.py). */
#define SquareRoot12 func_800480EC
extern int SquareRoot12(int a0);

int func_8013E064(s16 *a0, s16 *a1) {
    s32 d[3];
    s32 sq[3];
    d[0] = a0[1] - a1[1];
    d[1] = a0[3] - a1[3];
    d[2] = a0[5] - a1[5];
    __asm__ __volatile__("" ::: "memory");
    {
        register s32 *pd __asm__("$2") = &d[0];
        __asm__ __volatile__(
            "lwc2 $9, 0(%0)\n"
            "lwc2 $10, 4(%0)\n"
            "lwc2 $11, 8(%0)\n"
            "nop\n"
            "nop\n"
            "sqr 1\n"
            : : "r"(pd) : "$9", "$10", "$11", "memory");
    }
    {
        register s32 *pq __asm__("$2") = &sq[0];
        __asm__ __volatile__(
            "swc2 $25, 0(%0)\n"
            "swc2 $26, 4(%0)\n"
            "swc2 $27, 8(%0)\n"
            : : "r"(pq) : "memory");
    }
    return SquareRoot12(sq[0] + sq[1] + sq[2]);
}
