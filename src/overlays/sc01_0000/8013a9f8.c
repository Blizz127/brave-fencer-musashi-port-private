/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8013A9F8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);

void func_8013A9F8(s32 a0, s32 a1) {
    s32 orig = a1;
    a1 -= 2;
    a1 &= 0xFFFF;
    if ((u32)a1 < 5) {
        s32 b = orig & 0xFFFF;
        b -= 2;
        b <<= 10;
        *(s16*)(a0 + 0xE) = b;
    }
}
