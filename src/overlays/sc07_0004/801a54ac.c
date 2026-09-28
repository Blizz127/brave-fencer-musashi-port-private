/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A54AC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_801A54AC(s32 param_1) {
    extern u16 D_80126B96;
    extern s16 D_80126B98;
    extern s32 func_801A54F0();

    if (func_801A54F0(param_1, 0x40)) {
        D_80126B98 = 0x78;
        D_80126B96 |= 0x4000;
    }
}
