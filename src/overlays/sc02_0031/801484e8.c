/* Complete SC02 retail span [801484E8,80148534).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801484E8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80154358(void *a0);
extern void func_801485B8(s32 a0, s32 a1, s32 a2);
extern s32 D_80126B58;

void func_801484E8(s32 a0, s32 a1) {
    s32 v0 = func_80154358(&D_80126B58);
    func_801485B8(v0 - 0x10, a0, a1);
}
