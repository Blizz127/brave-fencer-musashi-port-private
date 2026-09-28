/* Complete SC02 retail span [80148C20,80148C34).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80148C20 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


s32 func_80148C20(s32 a0, s16 a1) {
    s32 *p = *(s32 **)((s32)a0 + 0x20);
    *(s16*)((s32)p + 0x12) = a1;
    return 1;
}
