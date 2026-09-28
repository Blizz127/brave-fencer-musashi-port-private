/* SC02.CD FILE_031 / ov_SC02_031 retail span [801399A8,801399F0).
 * Offset 0x11850 at overlay base 80128158. SHA256(span)=8283ae1d54b2ca7f226dda9d974721f5bac38d666365860d1e88a2fcf89206a0.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801399a8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801399A8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 D_801269F0;
extern s32 D_80126A3C;

s32 func_801399A8(void) {
    s32 iVar2; s32 puVar3; s32 iVar1;
    for (iVar2 = 1, puVar3 = (s32)&D_80126A3C, iVar1 = 0x4C; iVar2 < 3; puVar3 += 0x4C, iVar2++, iVar1 += 0x4C) {
        if (*(s32 *)((s32)&D_801269F0 + iVar1) == 0) return puVar3;
    }
    return 0;
}
