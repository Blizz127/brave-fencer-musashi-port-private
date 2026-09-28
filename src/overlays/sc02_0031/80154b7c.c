/* SC02.CD FILE_031 / ov_SC02_031 retail span [80154B7C,80154B98).
 * Offset 0x2CA24 at overlay base 80128158. SHA256(span)=7c0cdca4e596298d81aa03877248591f8a5b20e172328db022eae61702ce3c05.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80154b7c.c (m2c-derived, oracle MATCH); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80154B7C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_80154B7C(u8 *a0, s32 a1) {
    *(s32 *)(a0 + 0xD0) = a1;
    *(s16 *)(a0 + 0xD6) = 1;
    *(s16 *)(a0 + 0xD4) = 1;
    a0[0xD8] = 0;
    a0[0xD9] = 0;
}
