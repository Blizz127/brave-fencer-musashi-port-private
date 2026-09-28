/* Exact retail word export for [8001A9F8,8001AA78); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8001A9F8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_800A6610[];
extern u16 D_800B9A02;

void func_8001A9F8(s32 a0)
{
    extern u16 D_800B9A02;
    extern u8 D_800A6610[];
    extern u32 D_80063108;
    extern u32 D_80063120;

    u32 *p = (u32 *)(D_800A6610 + (D_800B9A02 << 14));
    u32 *q1;
    u32 *q2;

    q1 = &D_80063108;
    *q1 = (p[1] & 0xFFFFFF) | 0x5000000;
    p[1] = (p[1] & 0xFF000000) | ((u32)q1 & 0xFFFFFF);

    q2 = &D_80063120;
    *q2 = (p[1] & 0xFFFFFF) | 0x5000000;
    p[1] = (p[1] & 0xFF000000) | ((u32)q2 & 0xFFFFFF);
}
