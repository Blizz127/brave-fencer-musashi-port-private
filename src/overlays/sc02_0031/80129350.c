/* SC02.CD FILE_031 / ov_SC02_031 retail span [80129350,80129374).
 * Offset 0x11F8 at overlay base 80128158. SHA256(span)=d3f24eea8713d674c4678beefacccb6b17867bc1597b6c898051313c06ef740e.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80129350.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80129350 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_80129350(s32 a0, s32 a1) {
    *(s32 *)(a0 + 0x4) = *(s32 *)(a1 + 0x4);
    *(s32 *)(a0 + 0x8) = *(s32 *)(a1 + 0x8);
    *(s32 *)(a0 + 0xC) = *(s32 *)(a1 + 0xC);
}
