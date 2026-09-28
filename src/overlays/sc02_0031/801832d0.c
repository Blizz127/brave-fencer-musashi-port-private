/* Complete SC02 retail span [801832D0,801832F4).
 * Dep of 80182078 (func_801832D0).
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801832D0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 D_801B794C;
extern s32 D_801B7930;
extern s32 D_801B7988;

void func_801832D0(s32 arg0, s32 arg1) {
    D_801B794C = arg0 + 0x380;
    D_801B7930 = 0;
    D_801B7988 = arg1;
}
