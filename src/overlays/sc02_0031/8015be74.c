/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015BE74,8015BE94).
 * Offset 0x33D1C at overlay base 80128158. SHA256(span)=8853b79c8136dab6b31b4c16f6ddc8ae81feb3a1899abdbb097c7ed20a72dfbb.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015be74.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015BE74 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_8015BE94();

s32 func_8015BE74(void) {
    return func_8015BE94();
}
