/* Complete SC02 retail span [8014C59C,8014C5D0).
 * Ahead hole after 4BE9C→4C6D0; PAC0 member31.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014C59C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_8004CFEC(s32 dx, s32 dy);

s32 func_8014C59C(void *a0, void *a1) {
    s32 dx = *(s16 *)((s32)a0 + 0x6) - *(s16 *)((s32)a1 + 0x6);
    s32 dy = *(s16 *)((s32)a0 + 0xE) - *(s16 *)((s32)a1 + 0xE);
    return func_8004CFEC(dx, dy) & 0xFFF;
}
