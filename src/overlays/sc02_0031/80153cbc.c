/* SC02.CD FILE_031 / ov_SC02_031 retail span [80153CBC,80153CCC).
 * Offset 0x2BB64 at overlay base 80128158. SHA256(span)=81fb2702933ba00a6a5f0ec4796cc6bf9247f406c4bd78b920e90708de31f3b4.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80153cbc.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80153CBC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 D_80115210;

s32 func_80153CBC(void) {
    return D_80115210;
}
