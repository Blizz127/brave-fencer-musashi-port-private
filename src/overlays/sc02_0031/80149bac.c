/* Complete SC02 retail span [80149BAC,80149BEC).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80149BAC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8015DE24(s32 *a0);
extern void func_80157510(s32 *a0);

void func_80149BAC(s32 *a0) {
    if (*(s32 *)((s32)a0 + 0x178) != 0) {
        func_8015DE24(a0);
    } else {
        *(s8 *)((s32)a0 + 0x1AA) = 1;
        func_80157510(a0);
    }
}
