/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80149884 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s16 D_800B9A08;
extern s32 func_8016F1AC(void);

s32 func_80149884(void) {
    s32 ret;
    if (D_800B9A08 == 0x308F) {
        ret = 0;
    } else {
        ret = func_8016F1AC() == 0;
    }
    return ret;
}
