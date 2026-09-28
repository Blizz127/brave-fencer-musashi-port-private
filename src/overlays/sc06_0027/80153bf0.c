/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80153BF0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 D_801151FC;
extern s32 D_80127518;

s32 func_80153BF0(s32 a0) {
    if (a0 == D_801151FC) {
        D_80127518 = 0;
        return 1;
    }
    return 0;
}
