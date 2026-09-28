/* SC02.CD FILE_031 / ov_SC02_031 retail span [80134A28,80134A74).
 * Offset 0xC8D0 at overlay base 80128158. SHA256(span)=23d26b15e4a40ad8a6bd4edd16f82767d7854a7954402a041c2430c534e2a952.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80134a28.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80134A28 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);

s32 func_80134A28(s32 a0, s32 a1, s32 a2) {
    return *(s16*)(a0 + 0x0) * *(s16*)(a1 + 0x0)
         + *(s16*)(a0 + 0x2) * *(s16*)(a1 + 0x2)
         + *(s16*)(a0 + 0x4) * *(s16*)(a1 + 0x4)
         + a2;
}
