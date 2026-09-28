/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A7D18 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_801A7D18(s32 arg0) {
    s32 var;

    var = *(s32 *)(arg0 + 0x20);
    *(u16 *)(var + 0x1A) = 0x400;
    *(u16 *)(var + 0x18) = 0x400;
    *(u16 *)(arg0 + 0x2) = 6;
}
