/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801EAF9C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_801EAF9C(s32 arg0, s32 arg1, s32 arg2) {
    extern s32 D_801F2624;
    extern s32 D_801F24AC[];
    extern s32 D_801F24A8[];
    extern s32 D_801F24B0[];
    s32 i;

    i = D_801F2624;
    D_801F24AC[i * 4] = arg0;
    D_801F24A8[i * 4] = arg1;
    D_801F24B0[i * 4] = arg2;
    D_801F2624 = i + 1;
}
