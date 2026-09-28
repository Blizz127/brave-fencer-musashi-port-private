/* Exact retail overlay 0010 export [800D2CA8,800D2D10), offset 0x23EB0. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800D2CA8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


s32 func_800D2CA8(s32 a0, s32 a1) {
    s32 result = 0;
    s32 cur = a0;
    s32 shift = 0;

    while (cur >= 10) {
        a0 = a0 / 10;
        result |= (cur - (a0 * 2 + a0 * 8)) << shift;
        cur = a0;
        shift += 4;
    }
    result |= cur << shift;
    return result << a1;
}
