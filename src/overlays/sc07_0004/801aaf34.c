/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801AAF34 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_801AAF8C();

void func_801AAF34(s32 a0, s32 a1, s16 a2)
{
    s16 sv[3];

    sv[0] = *(u16 *)(a0 + 6) + *(u16 *)(a0 + 0x50);
    sv[1] = *(u16 *)(a0 + 0xA) + *(u16 *)(a0 + 0x52);
    sv[2] = *(u16 *)(a0 + 0xE) + *(u16 *)(a0 + 0x54);
    func_801AAF8C(sv, a1, a2);
}
