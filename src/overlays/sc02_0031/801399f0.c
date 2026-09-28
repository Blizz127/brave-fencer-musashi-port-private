/* SC02.CD FILE_031 / ov_SC02_031 retail span [801399F0,80139A34).
 * Offset 0x11898 at overlay base 80128158. SHA256(span)=20d7f3eee4937e63065a404f6a6729db355f111a4b017605c9825b8029bbde80.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801399f0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801399F0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);

s32 func_801399F0(s32 a0) {
    s32 v1;
    if (*(s32*)(a0 + 0x0) == 0) return -1;
    v1 = *(s16*)(a0 + 0x4);
    if (v1 == 0) return -1;
    if (v1 == 0xE) return -1;
    if (v1 == 0xD) return *(s8*)(a0 + 0x1F);
    return 0;
}
