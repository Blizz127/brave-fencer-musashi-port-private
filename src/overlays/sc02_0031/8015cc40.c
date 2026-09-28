/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015CC40,8015CC74).
 * Offset 0x34AE8 at overlay base 80128158. SHA256(span)=e692e8c6bd169b98e593cfc537919c9763b72feffd740fbc67b49b717dc353cf.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015cc40.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015CC40 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80147078(s32 *a0, s16 a1);
extern void func_8015CC74();

void func_8015CC40(s32 *a0) {
    func_80147078(a0, 0xB);
    func_8015CC74(a0);
}
