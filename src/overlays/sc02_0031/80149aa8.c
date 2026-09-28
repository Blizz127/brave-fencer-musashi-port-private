/* Complete SC02 retail span [80149AA8,80149AD4).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80149AA8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


s32 func_80149AA8(s32 *a0) {
    s32 v0;
    if (a0[0x44 / 4] & 0x404) {
        v0 = 0;
    } else {
        v0 = *(u16 *)((s32)a0 + 0xAC) & 0x80;
        v0 = v0 != 0;
    }
    return v0;
}
