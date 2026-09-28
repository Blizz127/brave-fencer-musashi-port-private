/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A36A8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_8004787C(s32 a0);

void func_801A36A8(s32 a0) {
    s16 v;

    v = *(u16 *)((s32)a0 + 0x108) + 0x30;
    *(u16 *)((s32)a0 + 0x108) = v;
    *(s16 *)((s32)a0 + 0x52) = func_8004787C(v) >> 8;
}
