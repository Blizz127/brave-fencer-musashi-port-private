/* Exact retail overlay 0010 export [800D2EE8,800D2F0C), offset 0x240F0. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800D2EE8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u16 func_800167F0(s32 arg0);

s32 func_800D2EE8(void) {
    return func_800167F0(4) != 0;
}
