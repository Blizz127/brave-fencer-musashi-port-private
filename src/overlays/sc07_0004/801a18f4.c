/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A18F4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012AD44(s32 *a0, s16 a1);
extern s16 D_801F8714;
extern s32 D_801AFBD4;

void func_801A18F4(s32 a0) {
    *(s32 *)(a0 + 0x1C) = (s16)(D_801F8714 / 39) + 0x20;
    *(s16 *)(a0 + 0xAE) = -3;
    *(s32 *)(a0 + 0x58) = (s32)&D_801AFBD4 | 0x40000000 | 0x20000000;
    *(u16 *)(a0 + 0x5C) &= 0xDFFF;
    func_8012AD44((s32 *)a0, 9);
}
