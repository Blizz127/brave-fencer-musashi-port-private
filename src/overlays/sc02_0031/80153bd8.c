/* SC02.CD FILE_031 / ov_SC02_031 retail span [80153BD8,80153BF0).
 * Offset 0x2BA80 at overlay base 80128158. SHA256(span)=8e5ebd197463e1743b4b2a0bc15c8a7f89afef66308164f3026cce4d1d911ff3.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80153bd8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80153BD8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 D_801151FC;

s32 func_80153BD8(s32 a0) {
    return (a0 ^ D_801151FC) == 0;
}
