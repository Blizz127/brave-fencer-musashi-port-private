/* MAIN10 resident retail span [800D0E30,800D0EC4), offset 0x22038 at base 800AEDF8. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800D0E30 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


s16 func_800D0E30(u8 *p) {
    extern u8 D_80078EB0;
    extern u8 D_80078EB1;
    register s32 zr __asm__("$0");
    u8 dummy[16];
    u32 hi;
    u32 lo;
    register u32 b __asm__("$5");
    register u32 t2 __asm__("$2");
    register u32 t3 __asm__("$3");
    register u32 h __asm__("$3");

    hi = (u8)(p[1] - D_80078EB1);
    lo = (u8)(p[0] - D_80078EB0);
    p = (u8 *)((hi << 8) | lo);

    b = (u32)p + zr;
    if ((b & 0xFF) >= 0x3C) {
        t3 = (b + 0x3C) & 0xFF;
        t2 = ((u32)p & 0xFF00) - 0x100;
        b = t2 | t3;
    }
    t2 = b & 0xFFFF;
    h = t2 >> 8;
    if (h >= 0x18) {
        t2 = (h + 0x18) << 8;
        t3 = b & 0xFF;
        b = t2 | t3;
    }
    return (s16)b;
}
