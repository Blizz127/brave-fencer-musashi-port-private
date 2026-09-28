/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801585AC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u16 func_80148800(s32 *a0);

s32 func_801585AC(s32 *a0) {
    u16 r = func_80148800(a0);
    u16 v = *(u16 *)((u8 *)a0 + 0x244) | r;
    s32 m;
    *(u16 *)((u8 *)a0 + 0x244) = v;
    m = v & 0x10;
    return m != 0;
}
