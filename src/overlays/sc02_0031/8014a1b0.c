/* Complete SC02 retail span [8014A1B0,8014A218).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014A1B0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80015978(s32 a0, s32 *a1);
extern u16 func_80156370(u16 a0);
extern void func_8014C4AC(s32 a0, s32 a1, s32 a2, s16 *a3, s32 a4);

void func_8014A1B0(s32 a0, s32 a1) {
    s16 sp18[4];
    u16 tmp;
    func_80015978(a0 + 4, (s32 *)sp18);
    sp18[3] = 0;
    tmp = func_80156370(0xA);
    func_8014C4AC(a1, 0xA, tmp, sp18, *(s16 *)(*(s32 *)(a0 + 0x20) + 0x12));
}
