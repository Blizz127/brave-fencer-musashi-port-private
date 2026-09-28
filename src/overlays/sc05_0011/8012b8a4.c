/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012B8A4 - byte-exact against retail at -O2 (tools/register_match.py). */
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
extern u16 D_80126B66;
extern u16 D_80126B5E;

s32 func_8012B8A4(s16 *a0) {
    s16 cx = a0[7];
    s16 dx = D_80126B66;
    s16 dy = D_80126B5E;
    s16 cy = a0[3];
    return (func_8004CFEC(cx - dx, dy - cy) - 0x400) & 0xFFF;
}
