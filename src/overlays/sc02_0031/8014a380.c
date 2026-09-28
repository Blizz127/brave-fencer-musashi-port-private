/* Complete SC02 retail span [8014A380,8014A3E0).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014A380 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80015978(s32 a0, s32 *a1);
extern void func_8014C4AC(s32 a0, s32 a1, s32 a2, s16 *a3, s32 a4);

void func_8014A380(s32 a0, s32 a1) {
    s16 buf[4];
    func_80015978(a0 + 4, (s32 *)buf);
    buf[3] = 0;
    func_8014C4AC(a1, 0x1F, 0, buf, *(s16 *)(*(s32 *)(a0 + 0x20) + 0x12));
}
