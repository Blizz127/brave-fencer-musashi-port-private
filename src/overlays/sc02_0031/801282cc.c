/* SC02.CD FILE_031 / ov_SC02_031 retail span [801282CC,801282EC).
 * Offset 0x174 at overlay base 80128158. SHA256(span)=f019b84f40a245c6b9179c21e0fe302b0791677ba0e17a86efb6585ba4693f76.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801282cc.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801282CC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80011B7C(int);

void func_801282CC(void) {
    func_80011B7C(0x11);
}
