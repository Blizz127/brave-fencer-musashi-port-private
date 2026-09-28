/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014A6C4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80029178(s32 a0);

s32 func_8014A6C4(s32 a0) {
    s32 r;
    if ((func_80029178(0x1F) & 0xFF) == 0) {
        r = 0;
    } else if (*(s32 *)(a0 + 0x44) & 0x4) {
        r = 0;
    } else {
        r = *(u8 *)(a0 + 0x1BE) == 0;
    }
    return r;
}
