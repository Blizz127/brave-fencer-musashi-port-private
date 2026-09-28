/* SC02.CD FILE_031 / ov_SC02_031 retail span [80142DB8,80142DC4).
 * Offset 0x1AC60 at overlay base 80128158. SHA256(span)=e051f2699e0264c692045685ea738e3fe652b03879a76754e46ac8010d6c19a5.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80142db8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80142DB8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);

s32 func_80142DB8(s32 *a0) {
    return *(u16*)((s32)a0 + 0x5C) & 0x1;
}
