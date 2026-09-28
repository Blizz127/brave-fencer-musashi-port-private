/* SC02.CD FILE_031 / ov_SC02_031 retail span [801725A4,801725B8).
 * Offset 0x4A44C at overlay base 80128158. SHA256(span)=690afdbdd27be15850531c03aa2a4bcd52a0cb3411996e8137c78fa20f4904d0.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801725a4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801725A4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));

s32 func_801725A4(u8 *a0) {
    s32 v0 = *(u32 *)((s32)a0 + 0x1F4) | 0x2;
    *(u32 *)((s32)a0 + 0x1F4) = v0;
    return v0;
}
