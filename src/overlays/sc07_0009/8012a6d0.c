/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012A6D0 - byte-exact against retail at -O2 (tools/register_match.py). */
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

s32 func_8012A6D0(void* a0, void* a1)
{
    s32 s0 = a0;
    s32 s1 = a1;
    s32 dy = *(s16 *)(s0 + 0x4) - *(s16 *)(s1 + 0x4);
    s32 dx = *(s16 *)(s0 + 0x0) - *(s16 *)(s1 + 0x0);
    s32 d;
    d = func_80047D3C(dy * dy + dx * dx);
    return (s16)func_8004CFEC(*(s16 *)(s0 + 0x2) - *(s16 *)(s1 + 0x2), (s16)d);
}
