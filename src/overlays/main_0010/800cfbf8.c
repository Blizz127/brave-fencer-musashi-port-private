/* Exact retail overlay 0010 export [800CFBF8,800CFDE8), offset 0x20E00. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800CFBF8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s16 D_800B9A08;
extern s32 func_800CFC5C(s32);

s32 func_800CFBF8(void) {
    s32 r = func_800CFC5C(D_800B9A08);

    if (r == 1) {
        return 0x1010;
    }
    if (r == 2) {
        return 0x1052;
    }
    if (r == 3) {
        return 0x1077;
    }
    if (r == 4) {
        return 0x1094;
    }
    return 0x1010;
}
