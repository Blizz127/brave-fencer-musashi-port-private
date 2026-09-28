/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017A3B0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s16 D_801B7500;

s32 func_8017A3B0(void) {
    switch (D_801B7500) {
    case 0:
        return 1;
    case 1:
        return 0;
    default:
        return 1;
    }
}
