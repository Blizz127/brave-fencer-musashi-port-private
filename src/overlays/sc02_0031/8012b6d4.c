/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012B6D4,8012B70C).
 * Offset 0x357C at overlay base 80128158. SHA256(span)=cab07e23bd20ab5a5df8c7b0da8d64f56948ff152bb9cd3eacc20f518723f80a.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012b6d4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012B6D4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s32 func_8004CFEC(s32 a0, s32 a1);

s32 func_8012B6D4(s16 *a0, s16 *a1) {
    s16 ax = a0[5];
    s16 bx = a1[5];
    s16 by = a1[1];
    s16 ay = a0[1];
    return (func_8004CFEC(ax - bx, by - ay) - 0x400) & 0xFFF;
}
