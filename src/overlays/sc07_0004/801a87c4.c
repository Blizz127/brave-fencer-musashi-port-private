/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A87C4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_801A87C4(s32 a0, s16 a1, s32 a2) {
    s16 varA;
    s16 varB;

    varA = *(s16 *)(*(s32 *)(a0 + 0x20) + 0x18);
    if (a1 < varA) {
        *(s16 *)(*(s32 *)(a0 + 0x20) + 0x18) = varA - a2;
    }
    varB = *(s16 *)(*(s32 *)(a0 + 0x20) + 0x1A);
    if (a1 < varB) {
        *(s16 *)(*(s32 *)(a0 + 0x20) + 0x1A) = varB - a2;
    }
}
