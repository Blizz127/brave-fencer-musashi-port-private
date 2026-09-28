/* Complete SC02 retail span [80147AD4,80147B18).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80147AD4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80147CC8(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4);
extern void func_80147B5C(s32 a0, void *a1);

void func_80147AD4(s32 a0, s32 a1, s32 a2, s32 a3) {
    u8 buf[16];
    func_80147CC8(a0, a1, a2, a3, (s32)buf);
    func_80147B5C(a0, (s32)buf);
}
