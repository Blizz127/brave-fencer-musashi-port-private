/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801508B4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_8014A2E4(s32 a0);
extern void func_8014A380(s32 a0, s32 a1);

s32 func_801508B4(s32 a0)
{
    s32 r;
    r = func_8014A2E4(a0);
    if (r != 0) {
        func_8014A380(a0, r);
        return 1;
    }
    return 0;
}
