/* Complete SC02 retail span [8014B5C4,8014B5D0).
 * Ahead hole after 4AA28; PAC0 member31.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014B5C4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_8014B5C4(s32 *a0, s32 a1, s32 a2) {
    *(s8*)((s32)a0 + 0x1C7) = a1 | a2;
}
