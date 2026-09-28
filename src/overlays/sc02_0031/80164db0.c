/* SC02.CD FILE_031 / ov_SC02_031 retail span [80164DB0,80164DD0).
 * Offset 0x3CC58 at overlay base 80128158. SHA256(span)=9e7a20e08351e79b56ce15a8320863009cab18fd7a4704deb4085985cd72a24f.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80164db0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80164DB0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80162CCC();

void func_80164DB0(void) {
    func_80162CCC();
}
