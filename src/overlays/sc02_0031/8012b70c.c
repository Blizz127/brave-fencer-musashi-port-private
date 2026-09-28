/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012B70C,8012B744).
 * Offset 0x35B4 at overlay base 80128158. SHA256(span)=9ad1b2220b74bd2f7301ee6f5de037b98f071a54d9b083b3c196157d499b27bb.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012b70c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012B70C - byte-exact against retail at -O2 (tools/register_match.py). */
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

s32 func_8012B70C(s16 *a0, s16 *a1) {
    s16 ax = a0[2];
    s16 bx = a1[2];
    s16 by = a1[0];
    s16 ay = a0[0];
    return (func_8004CFEC(ax - bx, by - ay) - 0x400) & 0xFFF;
}
