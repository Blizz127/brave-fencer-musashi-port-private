/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801AB748 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_801AB748(s32 a0) {
    s32 v0;
    s32 v1;

    v0 = *(s32 *)(a0 + 0x1C);
    if (v0 != 0) {
        v0 = v0 - 1;
        *(s32 *)(a0 + 0x1C) = v0;
    } else {
        v1 = *(s32 *)(a0 + 0x20);
        *(s16 *)(v1 + 0x1A) = 0x400;
        *(s16 *)(v1 + 0x18) = 0x400;
        v1 = *(s32 *)(a0 + 0x20);
        *(u16 *)(v1 + 0x2C) = 0xC020;
        *(s16 *)(a0 + 2) = 1;
    }
}
