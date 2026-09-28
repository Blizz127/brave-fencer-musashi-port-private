/* SC02.CD FILE_031 / ov_SC02_031 retail span [8013E2C4,8013E370).
 * Offset 0x1616C at overlay base 80128158. SHA256(span)=4f7e213e9439383457152597428668beab2b199bf194f5d25077be33a234cd6c.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8013e2c4.c (recovery=assembly, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8013E2C4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif
/* GTE instruction macros (vendor/bfm-decomp/include/gte_macros.inc) for GNU as. */
__asm__(
    ".macro cop2op fake_op, op, gbg = 0, sf = 1, mx = 0, v = 0, cv = 0, lm = 0\n"
    "    cop2 \\fake_op << 20 | \\gbg << 20 | \\sf << 19 | \\mx << 17 | \\v << 15 | \\cv << 13 | \\lm << 10 | \\op\n"
    ".endm\n"
    ".macro sqr sf\n"
    "    cop2op 0x0A, 0x28, sf = \\sf, lm = 1\n"
    ".endm\n"
    ".macro op sf\n"
    "    cop2op 0x17, 0x0C, sf = \\sf\n"
    ".endm\n"
);

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s16 D_80126CAC;
extern short D_80126CAE;
extern s16 D_80126CB0;

int func_8013E2C4(short *a0) {
    int in[3];
    int out[3];
    in[0] = D_80126CAC - a0[0];
    in[1] = D_80126CAE - a0[1];
    in[2] = D_80126CB0 - a0[2];
    __asm__ __volatile__(
        "lwc2 $9, 0(%0)\n"
        "lwc2 $10, 4(%0)\n"
        "lwc2 $11, 8(%0)\n"
        "nop\n"
        "nop\n"
        "sqr 0\n"
        : : "r"(&in[0]) : "$9", "$10", "$11", "memory");
    {
        register int *pout __asm__("$2") = &out[0];
        __asm__ __volatile__(
            "swc2 $25, 0(%0)\n"
            "swc2 $26, 4(%0)\n"
            "swc2 $27, 8(%0)\n"
            : : "r"(pout) : "memory");
    }
    return (out[0] + out[1] + out[2]) - 0x90001U < 0x18FFF;
}
