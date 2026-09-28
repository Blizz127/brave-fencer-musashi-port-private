/* MAIN10 resident retail span [800D0CE0,800D0D7C), offset 0x21EE8 at base 800AEDF8. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800D0CE0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80029504(void);
extern s32 (*D_800D375C)(s32);
extern s32 func_8001AAA0(s32);
extern s32 D_8012704C;
extern s32 D_801151F8;
extern s32 D_80126AE8;
extern s32 D_80127500;
extern s32 D_801201F0;
extern s32 D_80127050;
extern s32 D_800A654C;

s32 func_800D0CE0(void) {
    s32 s0;
    s32 r;

    r = func_80029504();
    s0 = 0;
    if (D_800D375C != 0) {
        s0 = D_800D375C(r);
    }
    if (func_8001AAA0(s0)) {
        D_8012704C = 0;
        D_801151F8 = 0;
        D_80126AE8 = 0;
        D_80127500 = 0;
        D_8012704C = 0;
        D_801201F0 = 0;
        D_80127050 = 0;
        D_800A654C = s0;
        return 1;
    }
    return 0;
}
