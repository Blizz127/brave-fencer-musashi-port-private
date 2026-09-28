/* Exact retail word export [800191D4,8001923C); verified against pinned EXE and asm. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800191D4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 D_80078E30;
extern s32 func_8001923C(s32 a0);

s32 func_800191D4(s32 a0) {
    extern s32 D_80078E30;
    extern s32 func_8001923C();
    s32 *p = &D_80078E30;

    if (*p < 0) {
        return 1;
    }
    if (func_8001923C(a0) == 0) {
        return *p != a0;
    }
    return 1;
}
