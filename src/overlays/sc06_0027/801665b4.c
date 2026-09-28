/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801665B4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80128ED8(s32 param_1, s32 *param_2);
extern void func_80146C3C();
extern void func_800D22E4(s32 a0);

void func_801665B4(s32 *a0)
{
    if (func_80128ED8((void *)a0[8], (void *)(a0 + 9))) {
        func_80146C3C((s32)a0);
    } else {
        func_800D22E4((s32)a0);
        a0[5] -= a0[5] >> 3;
    }
}
