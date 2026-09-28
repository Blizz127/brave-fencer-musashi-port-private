/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016F30C,8016F330).
 * Offset 0x471B4 at overlay base 80128158. SHA256(span)=4173087fca0de7be479e942bc552d4dddf17d0e86671b8ef146941f855be8f45.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016f30c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016F30C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 D_80126D50;

void func_8016F30C(void) {
    D_80126D50 &= 0xF7FFFFFF;
}
