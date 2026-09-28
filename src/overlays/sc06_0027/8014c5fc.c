/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014C5FC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80047D3C(s32 a0);
extern s32 func_8004CFEC(s32 a0, s32 a1);

s32 func_8014C5FC(s32 a0, s32 a1, void * a2)
{
    s32 dx;
    s32 dz;
    s32 dy;
    s32 r;
    dz = (s16)(*(u16 *)((s32)a1 + 0xE) + *(u16 *)((s32)a2 + 0x4) - *(u16 *)((s32)a0 + 0xE));
    dx = (s16)(*(u16 *)((s32)a1 + 0x6) + *(u16 *)((s32)a2 + 0x0) - *(u16 *)((s32)a0 + 0x6));
    r = func_80047D3C(dz * dz + dx * dx);
    dy = *(s16 *)((s32)a1 + 0xA) + *(s16 *)((s32)a2 + 0x2) - *(s16 *)((s32)a0 + 0xA);
    return func_8004CFEC(dy, (s16)r) & 0xFFF;
}
