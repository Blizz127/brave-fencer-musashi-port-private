/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012A5F8,8012A62C).
 * Offset 0x24A0 at overlay base 80128158. SHA256(span)=f7b119d1fb481b2151dd3894f45f822fd4ef9209a23000ec9efb3cd1d644d17d.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012a5f8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012A5F8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A62C(s32);

void func_8012A5F8(void (*a0)(void), s32 a1) {
    func_8012A62C(a1 & 0xFF);
    a0();
}
