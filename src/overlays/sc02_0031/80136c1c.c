/* SC02.CD FILE_031 / ov_SC02_031 retail span [80136C1C,80136C3C).
 * Offset 0xEAC4 at overlay base 80128158. SHA256(span)=5ed99233ea68737138555fc4357841b78317620f9c5dd801914d4a4ee11a54c2.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80136c1c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80136C1C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80136C3C(void);

void func_80136C1C(void) {
    func_80136C3C();
}
