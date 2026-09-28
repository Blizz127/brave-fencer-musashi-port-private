/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A8564 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80132EF4(s32 a0, s32 a1);

s32 func_801A8564(s32 a0) {
    s32 var;

    var = func_80132EF4(a0, 0x30);
    if (var != 0) {
        *(u16 *)(var + 0x2E) = 1;
        *(s32 *)(var + 0x34) = a0;
    }
    return var;
}
