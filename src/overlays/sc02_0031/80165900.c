/* SC02.CD FILE_031 / ov_SC02_031 retail span [80165900,80165910).
 * Offset 0x3D7A8 at overlay base 80128158. SHA256(span)=9c6cebe1deb420277c96a1605a170ea2ffdbb2245e1631d24348f00fb4c5bb64.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80165900.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80165900 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s8 D_80078EC4;

s32 func_80165900(void) {
    return (unsigned char)D_80078EC4;
}
