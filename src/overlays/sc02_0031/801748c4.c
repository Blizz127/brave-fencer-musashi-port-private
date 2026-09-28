/* SC02.CD FILE_031 / ov_SC02_031 retail span [801748C4,801748E4).
 * Offset 0x4C76C at overlay base 80128158. SHA256(span)=e399530aba71398684d70d1795702e700d0029c53799d27f53298e382dd8b79b.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801748c4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801748C4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));

void func_801748C4(s32 a0) {
    u8 v = *(u8 *)(a0 + 0x214) + 1;
    *(s32 *)(a0 + 0x44) |= 0x4000000;
    *(u8 *)(a0 + 0x214) = v;
}
