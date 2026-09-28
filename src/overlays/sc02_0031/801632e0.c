/* SC02.CD FILE_031 / ov_SC02_031 retail span [801632E0,801632F0).
 * Offset 0x3B188 at overlay base 80128158. SHA256(span)=9e9b3ec187e49c56bfefa145cbe1c92a95b1e8a82b121b7aa78edf5233b94a87.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801632e0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801632E0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 D_80115100;

s32 func_801632E0(void) {
    return D_80115100;
}
