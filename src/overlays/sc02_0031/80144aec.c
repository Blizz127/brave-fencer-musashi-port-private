/* Complete SC02 retail span [80144AEC,80144B14).
 * Matched C: Druthulu shared ov/func_80144AEC.h (local leaf word export).
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80144AEC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern int func_80144B14(int param_1);

void func_80144AEC(s32 *a0) {
    s32 old;
    old = *(s32 *)((s32)a0 + 0xDC);
    *(s32 *)((s32)a0 + 0xDC) = (s32)&func_80144B14;
    *(s16 *)((s32)a0 + 0x0) = 0x83;
    *(s16 *)((s32)a0 + 0x2) = 1;
    *(s32 *)((s32)a0 + 0xCC) = old;
}
