/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80154134 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_80154134(u8 *a0) {
    *(s32 *)(a0 + 0xB4) = 0;
    *(s16 *)(a0 + 0xBA) = 0;
    *(s16 *)(a0 + 0xB8) = 0;
    a0[0xBD] = 0;
    a0[0xBC] = 0;
    a0[0xDC] = 0;
}
