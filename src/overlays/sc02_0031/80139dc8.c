/* SC02.CD FILE_031 / ov_SC02_031 retail span [80139DC8,80139DEC).
 * Offset 0x11C70 at overlay base 80128158. SHA256(span)=47fc75c5557040fd12f3d1814eb36a0a23cb522a4ac548d1110642ffc458d83d.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80139dc8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80139DC8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s16 D_8012811A;

void func_80139DC8(void) {
    s32 i = 0x287;
    s16 *p = &D_8012811A;
    do {
        *p = 0;
        i--;
        p = (s16 *)((s32)p - 2);
    } while (i >= 0);
}
