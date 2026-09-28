/* Complete SC02 retail span [80148534,8014856C).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80148534 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801485B8(s32 a0, s32 a1, s32 a2);
extern s32 *D_80126B78;

void func_80148534(s32 a0, s32 a1) {
    func_801485B8(*(s32 *)((s32)D_80126B78 + 0x20) - 0x8, a0, a1);
}
