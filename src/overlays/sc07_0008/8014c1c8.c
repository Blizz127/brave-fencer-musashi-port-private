/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014C1C8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80133784(s32 a0, void *a1, s32 a2);

void func_8014C1C8(s32 a0, s32 a1, void* a2)
{
    s16 buf[4];
    s16 out[4];
    s32 s0 = a1;
    buf[0] = *(u16 *)(a0 + 6);
    buf[1] = *(u16 *)(a0 + 0xA);
    buf[2] = *(u16 *)(a0 + 0xE);
    out[0] = *(u16 *)(s0 + 6) + *(u16 *)(a2 + 0);
    out[1] = *(u16 *)(s0 + 0xA) + *(u16 *)(a2 + 2);
    out[2] = *(u16 *)(s0 + 0xE) + *(u16 *)(a2 + 4);
    if (func_80133784(1, buf, (s32)out) != 0) {
        *(s16 *)(s0 + 6) = out[0];
        *(s16 *)(s0 + 0xA) = out[1];
        *(s16 *)(s0 + 0xE) = out[2];
    }
}
