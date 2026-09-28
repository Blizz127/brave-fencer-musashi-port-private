/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80147A30 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_80147A30(s32 a0, s32 a1, s32 a2) {
    s32 v0 = *(s32*)(a0 + 0x2C) + a1;
    *(s32*)(a0 + 0x2C) = v0;
    if (a1 < 0) {
        if (-a2 >= v0) {
            *(s32*)(a0 + 0x2C) = -a2;
            return;
        }
    }
    if (a1 > 0) {
        if (*(s32*)(a0 + 0x2C) >= a2) {
            *(s32*)(a0 + 0x2C) = a2;
        }
    }
}
