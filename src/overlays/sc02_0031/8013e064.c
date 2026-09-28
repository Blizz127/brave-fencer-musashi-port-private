/* SC02.CD FILE_031 / ov_SC02_031 retail span [8013E064,8013E0FC).
 * Offset 0x15F0C at overlay base 80128158. SHA256(span)=577399d696edb38c827713dc510722e11ff8a3c0b955815984b82c38867eaa28.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8013e064.c (recovery=assembly, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8013E064 - byte-exact against retail at -O2 (tools/register_match.py). */
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
extern int func_800480EC(int a0);

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
    return func_800480EC(sq[0] + sq[1] + sq[2]);
}
