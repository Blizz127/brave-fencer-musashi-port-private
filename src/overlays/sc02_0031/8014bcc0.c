/* Complete SC02 retail span [8014BCC0,8014BCEC).
 * Ahead hole after 4AA28; PAC0 member31.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014BCC0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s16 D_80078EB4;

void func_8014BCC0(s32 a0, s32 a1) {
    s32 v1 = (u16)D_80078EB4;
    if (a1 < v1) {
        D_80078EB4 = v1 - a1;
    } else {
        D_80078EB4 = 1;
    }
}
