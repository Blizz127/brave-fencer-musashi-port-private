/* Complete SC02 retail span [8014C568,8014C59C).
 * Ahead hole after 4BE9C→4C6D0; PAC0 member31.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014C568 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_8004CFEC(s32 x, s32 y);

s32 func_8014C568(s16 *a0, s16 *a1) {
    return func_8004CFEC(a0[3] - a1[0], a0[7] - a1[2]) & 0xFFF;
}
