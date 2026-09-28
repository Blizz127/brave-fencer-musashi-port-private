/* MAIN10 resident retail span [800D0D7C,800D0E30), offset 0x21F84 at base 800AEDF8. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800D0D7C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


s32 func_800D0D7C(s32 arg0, s32 arg1) {
    extern u8 D_80078EB0;
    extern u8 D_80078EB1;
    register s32 zr __asm__("$0");
    u32 now;
    u32 r;
    s32 h;
    u32 dead[2];

    now = D_80078EB0 | (D_80078EB1 << 8);
    r = now + zr;
    h = arg0 + zr;
    if ((r & 0xFF) >= ((u32)arg1 & 0xFF)) {
        r = ((r - arg1) & 0xFF) | (now & 0xFF00);
    } else {
        r = ((0x3C - (arg1 - r)) & 0xFF) | (now & 0xFF00);
        h = arg0 + 1;
    }

    if (((r & 0xFFFF) >> 8) >= ((u32)h & 0xFF)) {
        r = ((((r & 0xFFFF) >> 8) - h) << 8) | (r & 0xFF);
    } else {
        r = ((0x18 - (h - ((r & 0xFFFF) >> 8))) << 8) | (r & 0xFF);
    }
    return (s16)r;
}
