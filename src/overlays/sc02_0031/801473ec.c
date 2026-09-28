/* Complete SC02 retail span [801473EC,80147460).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801473EC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_801473EC(s32 *a0) {
    s32 *a2;
    a2 = a0;
    a2[1] += a2[4];
    a2[2] += a2[5];
    a2[3] += a2[6];
    if (a2[4] != 0 || a2[5] != 0 || a2[6] != 0) {
        a2[0x11] |= 0x80000000;
    }
}
