/* SC02.CD FILE_031 / ov_SC02_031 retail span [80174808,8017481C).
 * Offset 0x4C6B0 at overlay base 80128158. SHA256(span)=52cd556ded98e83c61cf753d2a2480e1e5c41cc57aa94e589a8e8a1ac62a8519.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80174808.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80174808 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));

s32 func_80174808(u8 *a0) {
    s32 v = (s32)a0[0x214] + 1;
    a0[0x214] = (u8)v;
    return v;
}
