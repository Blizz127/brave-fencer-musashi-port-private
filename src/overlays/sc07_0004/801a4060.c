/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A4060 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_8004787C(s32 a0);

void func_801A4060(s32 a0) {
    *(s16 *)(*(s32 *)(a0 + 0x20) + 0x18) = (func_8004787C(*(s16 *)(a0 + 0xFE)) >> 3) + 0x1000;
    *(s16 *)(*(s32 *)(a0 + 0x20) + 0x1A) = (func_8004787C(*(s16 *)(a0 + 0xFE) + 0x800) >> 3) + 0x1000;
    *(u16 *)(a0 + 0xFE) += 0x80;
}
