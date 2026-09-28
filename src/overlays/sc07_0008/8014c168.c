/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014C168 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_801202A0[];

s32 func_8014C168(s32 * param_1, s32 param_2)
{
    u32 i;
    u16 *p;
    i = 0;
    p = (u16 *)D_801202A0;
    for (; i < 0x60; i++) {
        if (*p == param_2) {
            return p;
        }
        p = (u16 *)((u8 *)p + 0x10C);
    }
    return (u16 *)0;
}
