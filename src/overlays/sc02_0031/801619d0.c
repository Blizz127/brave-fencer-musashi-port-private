/* SC02.CD FILE_031 / ov_SC02_031 retail span [801619D0,80161A00).
 * Offset 0x39878 at overlay base 80128158. SHA256(span)=c10f9f7068306da70fe8022caa7f7ed835d5627813998edeb79e3f9ba06764f0.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801619d0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801619D0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_80078EC0;

s32 func_801619D0(void *a0) {
    s32 v0;
    if (*(s16 *)((s32)a0 + 0x1C8) == 0) {
        v0 = 0;
    } else {
        v0 = ((D_80078EC0 & 0x7F) ^ 3) == 0;
    }
    return v0;
}
