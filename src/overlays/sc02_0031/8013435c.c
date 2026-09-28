/* SC02.CD FILE_031 / ov_SC02_031 retail span [8013435C,801343C4).
 * Offset 0xC204 at overlay base 80128158. SHA256(span)=e61bfeb03fec06871844b83802c03e7a49a54d380d798b98a022bca2ba18d9f2.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8013435c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8013435C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);

s32 func_8013435C(s16 *a0, s16 *a1, s32 a2, s16 *a3) {
    s32 t1;
    s32 sum;
    if (a3[1] < -0xE00) {
        t1 = -0x1800;
    } else {
        t1 = -0x2F00;
    }
    sum = a0[0] * a1[0] + a0[1] * a1[1];
    sum = sum + a0[2] * a1[2];
    sum = sum + a2;
    return sum < t1;
}
