/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A8670 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80132EF4(s32 a0, s32 a1);

s32 func_801A8670(s32 arg0) {
    s32 var_v1;

    var_v1 = func_80132EF4(arg0, 0x30);
    if (var_v1 != 0) {
        *(u16 *)(var_v1 + 0x2E) = 6;
        *(s32 *)(var_v1 + 0x34) = arg0;
    }
    return var_v1;
}
