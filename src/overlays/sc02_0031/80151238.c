/* SC02.CD FILE_031 / ov_SC02_031 retail span [80151238,8015126C).
 * Offset 0x290E0 at overlay base 80128158. SHA256(span)=091fe7d25a21922abfc217cd45554702d0a7c7d5b7c5d8c05a4077f88540ab8b.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80151238.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80151238 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8014ACE8(void *a0, s32 a1, s32 a2);

void func_80151238(void *a0) {
    s16 v0 = *(s16 *)((s32)a0 + 0xF2);
    if (v0 != 0) {
        func_8014ACE8(a0, 5, (s32)v0 & 0x7FFF);
    }
}
