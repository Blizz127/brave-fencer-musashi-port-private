/* Exact retail word export for [8001534C,800153A4); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8001534C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_800AF630[];
extern void func_800153A4(void *a0, s32 a1, s16 a2, s16 a3, u8 arg4, u8 arg5);

void func_8001534C(s32 idx, s32 a1, s16 x, s16 y, u8 arg4, u8 arg5) {
    u8 *p;
    s32 off;

    p = D_800AF630;
    off = (s16)idx * 16 + 0x9DA8;
    func_800153A4(p + off, a1, x, y, arg4, arg5);
}
