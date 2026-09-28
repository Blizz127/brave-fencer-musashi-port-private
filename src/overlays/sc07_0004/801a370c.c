/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A370C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u16 D_801AFE34[8];

void func_801A370C(s32 a0) {
    register s32 v0 __asm__("$2");
    register s32 v1 __asm__("$3");

    v0 = *(u16 *)(a0 + 0x10A);
    v1 = *(s32 *)(a0 + 0x20);
    v0 = v0 + 1;
    *(u16 *)(a0 + 0x10A) = v0;
    v0 = D_801AFE34[v0 & 7];
    *(u16 *)(v1 + 0x1C) = v0;
    *(u16 *)(v1 + 0x1A) = v0;
    *(u16 *)(v1 + 0x18) = v0;
}
