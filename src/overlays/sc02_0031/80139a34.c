/* SC02.CD FILE_031 / ov_SC02_031 retail span [80139A34,80139A44).
 * Offset 0x118DC at overlay base 80128158. SHA256(span)=7072162d1a6b36d2b2662ab0b6c44b6fefa98b63485d9a45c926bf4bda008b3b.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80139a34.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80139A34 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s32 D_80127520;

void func_80139A34(s32 a0) {
    D_80127520 = a0;
}
