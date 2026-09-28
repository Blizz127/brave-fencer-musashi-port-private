/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80178B70 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


s32 func_80178B70(s32 param_1, s32 param_2)
{
    extern void func_80178BF8();
    extern void func_80178CBC();
    extern int D_80182544;

    int *p = &D_80182544;
    *p = ((int)param_2);
    func_80178BF8();
    func_80178CBC(((int)param_1), p - 3);
}
