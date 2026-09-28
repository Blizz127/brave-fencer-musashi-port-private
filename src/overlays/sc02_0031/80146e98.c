/* Complete SC02 retail span [80146E98,80146EC0).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80146E98 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


s32 func_80146E98(s32 a0) {
    s32 v0;
    v0 = *(s32*)(a0 + 0x1C);
    if (v0 != 0) {
        v0 = v0 - 1;
        *(s32*)(a0 + 0x1C) = v0;
        return (u32)v0 < 1;
    }
    return 1;
}
