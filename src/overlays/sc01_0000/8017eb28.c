/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017EB28 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80016224(s32 arg0, s32 arg1);
extern short D_800AF7CE;

void func_8017EB28(void) {
        D_800AF7CE = 0;
        func_80016224(0, 0);
    }
