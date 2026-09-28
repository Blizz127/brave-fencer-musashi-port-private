/* SC02.CD FILE_031 / ov_SC02_031 retail span [80153BF0,80153C18).
 * Offset 0x2BA98 at overlay base 80128158. SHA256(span)=afebf85742f24a077516fabb407253377f784f694b4bbfd6f4e9c2d6297d2005.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80153bf0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80153BF0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 D_801151FC;
extern s32 D_80127518;

s32 func_80153BF0(s32 a0) {
    if (a0 == D_801151FC) {
        D_80127518 = 0;
        return 1;
    }
    return 0;
}
