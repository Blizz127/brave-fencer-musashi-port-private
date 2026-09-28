/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80165910 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s8 D_80078EC4;

s32 func_80165910(void)
{
    s32 v;
    s32 ret;
    v = (u8)D_80078EC4;
    ret = v;
    if (v == 0) {
        register s32 one __asm__("$2");
        one = 1;
        __asm__ __volatile__("" : "=r"(one) : "0"(one));
        D_80078EC4 = one;
    }
    return ret;
}
