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
