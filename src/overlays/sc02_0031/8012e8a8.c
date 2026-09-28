/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012E8A8,8012E8C4).
 * Offset 0x6750 at overlay base 80128158. SHA256(span)=b2cd5aef5d5a0d8905c07b45fcc1266e83cef05ae07ac8803335016da53bf948.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012e8a8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012E8A8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);

void func_8012E8A8(u8 *a0) {
    s32 *p = *(s32 **)(a0 + 0x20);
    p[1] = p[1] | 0x80000000;
}
