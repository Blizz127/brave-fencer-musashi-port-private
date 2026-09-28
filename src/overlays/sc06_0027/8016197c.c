/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016197C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


s32 func_8016197C(s32 a0, s32 a1) {
    s32 v0;
    if (a1 & 1) {
        v0 = 1;
    } else if (a1 & 0x4000) {
        v0 = 2;
    } else {
        v0 = ((u32)a1 >> 11) & 4;
    }
    return v0;
}
