/* SC02.CD FILE_031 / ov_SC02_031 retail span [80153C9C,80153CBC).
 * Offset 0x2BB44 at overlay base 80128158. SHA256(span)=780fd0de748e1d4c430a03b6fd3dc75b6f02d20a79a228ff25c027555a415d5c.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80153c9c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80153C9C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 D_80115210;

void func_80153C9C(void) {
    D_80115210 = D_80115210 + 1;
}
