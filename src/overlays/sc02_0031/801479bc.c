/* Complete SC02 retail span [801479BC,80147A10).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801479BC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_801479BC(s32 a0, s32 a1, s32 a2) {
    s32 v0 = *(s32*)(a0 + 0x28) + a1;
    *(s32*)(a0 + 0x28) = v0;
    if (a1 < 0) {
        if (!(-a2 < v0)) {
            *(s32*)(a0 + 0x28) = -a2;
            return;
        }
    }
    if (a1 > 0) {
        if (!(*(s32*)(a0 + 0x28) < a2)) {
            *(s32*)(a0 + 0x28) = a2;
        }
    }
}
