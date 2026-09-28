/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014B6F0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 D_80078E9C;
extern s32 D_80078ED0;

void func_8014B6F0(s32 a0, s32 a1) {
    D_80078E9C += a1;
    if (*(s16*)((s32)&D_80078E9C + 2) >= 0xA1) {
        D_80078E9C = 0xA00000;
    }
    D_80078ED0 += a1;
    if (*(s16*)((s32)&D_80078ED0 + 2) >= 0xA1) {
        D_80078ED0 = 0xA00000;
    }
}
