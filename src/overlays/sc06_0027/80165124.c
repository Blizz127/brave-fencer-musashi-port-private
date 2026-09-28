/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80165124 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_80165124(void *a0) {
    *(s8 *)((s32)a0 + 0x50) = *(u16 *)((s32)a0 + 0x62);
    *(s8 *)((s32)a0 + 0x51) = *(u16 *)((s32)a0 + 0x62);
    *(s8 *)((s32)a0 + 0x52) = *(u16 *)((s32)a0 + 0x62);
}
