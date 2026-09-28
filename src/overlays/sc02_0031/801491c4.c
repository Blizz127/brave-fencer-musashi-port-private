/* Complete SC02 retail span [801491C4,80149204).
 * PAC0 member31 words.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801491C4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_8004CFEC(s32 a0, s32 a1);
extern s32 D_801151D4;

s32 func_801491C4(s32 a0) {
    s32 p;
    s32 v0;
    p = D_801151D4;
    v0 = func_8004CFEC(*(s32*)(p + 0x3C) - *(s32*)(p + 0x48), *(s32*)(p + 0x44) - *(s32*)(p + 0x50));
    return (s16)v0;
}
