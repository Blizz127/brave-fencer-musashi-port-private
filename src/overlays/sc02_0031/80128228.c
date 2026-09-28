/* SC02.CD FILE_031 / ov_SC02_031 retail span [80128228,80128248).
 * Offset 0xD0 at overlay base 80128158. SHA256(span)=6eb7e9f92c736f03cd7498acad5363d477107f8d6e86cdf6f23e0368dd65987e.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80128228.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80128228 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80128A28(void);

void func_80128228(void) {
    func_80128A28();
}
