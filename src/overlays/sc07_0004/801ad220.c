/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801AD220 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_801AD220(s32 a0, s32 a1) {
    s32 v0;
    s16 v1;

    if (a1 != 0) {
        v0 = *(s32 *)(a0 + 0x64);
        *(u16 *)(a1 + 8) = *(u16 *)(v0 + 6);
        v0 = *(s32 *)(a0 + 0x64);
        *(u16 *)(a1 + 0xA) = *(u16 *)(v0 + 0xA) - 0x40;
        v0 = *(s32 *)(a0 + 0x64);
        *(u16 *)(a1 + 0xC) = *(u16 *)(v0 + 0xE) + 0x20;
        v1 = *(s16 *)(*(s32 *)(a0 + 0x20) + 0x18);
        v0 = v1 * 3;
        *(u16 *)(a1 + 0x18) = v0;
        *(u16 *)(a1 + 0x1A) = v0;
    }
}
