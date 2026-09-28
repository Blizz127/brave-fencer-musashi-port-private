/* SC02.CD FILE_031 / ov_SC02_031 retail span [80154134,80154150).
 * Offset 0x2BFDC at overlay base 80128158. SHA256(span)=df844632cbc605c52a1b9346b11c83679a4f229370b222b6203c7bcfbc485028.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80154134.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80154134 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_80154134(u8 *a0) {
    *(s32 *)(a0 + 0xB4) = 0;
    *(s16 *)(a0 + 0xBA) = 0;
    *(s16 *)(a0 + 0xB8) = 0;
    a0[0xBD] = 0;
    a0[0xBC] = 0;
    a0[0xDC] = 0;
}
