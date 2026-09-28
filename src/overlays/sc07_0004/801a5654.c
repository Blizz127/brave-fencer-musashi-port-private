/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A5654 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_8012C658(s32 arg0, s32 arg1, s32 arg2);

void func_801A5654(s32 param_1, s16 param_2, s32 param_3) {
    s32 v0;

    v0 = func_8012C658(0x339, param_3, param_1);
    if (v0 != 0) {
        *(s16 *)(v0 + 0xFE) = param_2;
    }
}
