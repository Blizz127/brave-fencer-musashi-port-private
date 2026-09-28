/* Complete SC02 retail span [80146EC0,80146F58).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80146EC0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80015954(s32 a0, s32 a1);
extern void func_80149374(s32 a0, s32 a1);
extern void func_80146F58(s32 a0, s32 a1);

void func_80146EC0(s32 a0, s32 a1, s32 a2, s32 a3) {
    s32 s2 = a0;
    s32 s0 = a1;
    s32 s1 = a3;
    u16 buf[3];
    func_80015954(a2, a1);
    func_80149374(s2, s0);
    func_80146F58(s1, (s32)&buf[0]);
    *(u16 *)(s0 + 2) = *(u16 *)(s0 + 2) + buf[0];
    *(u16 *)(s0 + 6) = *(u16 *)(s0 + 6) + buf[1];
    *(u16 *)(s0 + 0xA) = *(u16 *)(s0 + 0xA) + buf[2];
}
