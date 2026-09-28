/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014ADA8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 D_80078E8C;

void func_8014ADA8(s32 a0, s32 a1) {
    s32 v0;
    v0 = D_80078E8C + a1;
    D_80078E8C = v0;
    if (0x1869F < (u32)v0) {
        D_80078E8C = 0x1869F;
    }
}
