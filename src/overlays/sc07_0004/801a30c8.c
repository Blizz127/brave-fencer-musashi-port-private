/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A30C8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801A46B8(s32 a0);
extern void func_8012AD44(s32 *a0, s16 a1);

void func_801A30C8(s32 a0)
{
    s32 s0;
    u16 v0;

    s0 = a0;
    v0 = *(u16 *)(s0 + 0x5C);
    *(u8 *)(s0 + 0xC1) = 0;
    *(u16 *)(s0 + 0x5E) = 0;
    *(u16 *)(s0 + 0x10A) = 0;
    *(u16 *)(s0 + 0x5C) = v0 & 0xDFFF;
    func_801A46B8(s0);
    func_8012AD44((s32 *)s0, 8);
}
