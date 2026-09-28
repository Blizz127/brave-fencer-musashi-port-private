/* MAIN10 resident retail span [800D1DB0,800D1E20), offset 0x22FB8 at base 800AEDF8. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800D1DB0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s16 D_800B9A08;
extern u16 D_80078E50;
extern s32 func_800CFC5C(s32);
extern s32 func_800CFD68(s32);

s32 func_800D1DB0(void) {
    if (D_800B9A08 == 0x3005) {
        return 2;
    }
    if (func_800CFC5C(D_800B9A08) != 0) {
        return 2;
    }
    if (func_800CFD68(D_80078E50) == 0) {
        return 2;
    }
    if (func_800CFC5C(D_80078E50) == 0) {
        return 1;
    }
    return 2;
}
