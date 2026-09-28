/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80161D20 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80147324(s32 arg0);

void func_80161D20(int param_1, u32 param_2)
{

    extern u16 D_80181700[];
    if (param_2 < 8) {
        func_80147324(D_80181700[param_2]);
    }
    return;
}
