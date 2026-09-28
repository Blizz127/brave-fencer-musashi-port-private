/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801429C4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u16 D_801270C0;
extern void (*D_8017F404[])();

void func_801429C4(int param_1)
{
    if (*(s16 *)&D_801270C0 != 3) {
        D_8017F404[*(u16 *)(param_1 + 2)]();
    }
}
