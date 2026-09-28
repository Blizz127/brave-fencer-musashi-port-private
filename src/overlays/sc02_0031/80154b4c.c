/* SC02.CD FILE_031 / ov_SC02_031 retail span [80154B4C,80154B7C).
 * Offset 0x2C9F4 at overlay base 80128158. SHA256(span)=c03f44a326eee1b1fef1543514cdef832b8baa2cc2ec62e4d30092df5f9cec2c.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80154b4c.c (m2c-derived, oracle MATCH); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80154B4C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80154B7C(u8 *a0, s32 a1);

void func_80154B4C(u8 *a0, s32 a1) {
    if (*(s32 *)(a0 + 0xD0) != a1) {
        func_80154B7C(a0, a1);
    }
}
