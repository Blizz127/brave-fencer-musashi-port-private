/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A7C34 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_801A7C34(s32 a0) {
    s32 v0;

    v0 = *(s32 *)(a0 + 0x20);
    *(u16 *)(v0 + 0x1A) = 0;
    *(u16 *)(v0 + 0x18) = 0;
    *(s32 *)(a0 + 0x1C) = 1;
    *(u16 *)(a0 + 0x2) = 2;
}
