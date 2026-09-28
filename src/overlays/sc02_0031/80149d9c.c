/* Complete SC02 retail span [80149D9C,80149DD8).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80149D9C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80149E94(s32 a0);
extern s32 func_80149DD8(s32 a0);

s32 func_80149D9C(s32 a0) {
    s32 v0;
    if (func_80149E94(a0) != 0) {
        v0 = 1;
    } else {
        v0 = func_80149DD8(a0) != 0;
    }
    return v0;
}
