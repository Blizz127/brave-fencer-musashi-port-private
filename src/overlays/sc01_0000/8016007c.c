/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016007C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80154A74(s32 a0, s32 a1);
extern u8 D_800B9A17;
extern u16 D_801270C0;

void func_8016007C(s32 a0) {
    *(s32 *)(a0 + 0x184) = 0;
    *(s16 *)(a0 + 0x18A) = 0;
    *(s16 *)(a0 + 0x188) = 0;
    *(s32 *)(a0 + 0x44) = *(s32 *)(a0 + 0x44) & ~0x10;
    D_800B9A17 = 1;
    func_80154A74(a0, 0x11);
    D_801270C0 = 1;
}
