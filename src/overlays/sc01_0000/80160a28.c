/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80160A28 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801553C0(s32 a0);
extern void func_80154A74(s32 a0, s32 a1);

void func_80160A28(s32 a0) {
    s32 v0;
    func_801553C0(a0);
    v0 = *(s32 *)(a0 + 0x44);
    v0 &= ~0x40;
    v0 &= ~1;
    *(s32 *)(a0 + 0x44) = v0;
    func_80154A74(a0, 0x11);
}
