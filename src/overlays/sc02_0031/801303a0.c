/* SC02.CD FILE_031 / ov_SC02_031 retail span [801303A0,801303EC).
 * Offset 0x8248 at overlay base 80128158. SHA256(span)=89a1dd448d6b7c2210e7f98888738f4d98ae4401ec24bd0d3bab5b4289a5e2d5.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801303a0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801303A0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_8012E364();
extern void func_80131CA8(int a0, int a1);

void func_801303A0(s32 a0) {
    if (*(s32 *)(a0 + 0xB4) & 0x2) {
        ((void (*)(s32))func_8012E364)(a0);
    }
    func_80131CA8(a0, 2);
}
