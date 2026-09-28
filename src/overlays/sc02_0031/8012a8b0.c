/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012A8B0,8012A8E8).
 * Offset 0x2758 at overlay base 80128158. SHA256(span)=8ebc4b60cb7304d5d165ec959a700c60804a855de611b2cd873a4a2cecd38088.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012a8b0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012A8B0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012AAAC();

void func_8012A8B0(u8 *a0, s32 a1) {
    u16 v0 = *(u16 *)(a0 + 0x72);
    *(s32 *)(a0 + 0x90) = a1;
    *(s32 *)(a0 + 0x94) = 0;
    *(s32 *)(a0 + 0x9C) = 0;
    *(s16 *)(a0 + 0x9A) = 0;
    *(u16 *)(a0 + 0x72) = v0 & 0xF9FF;
    func_8012AAAC();
}
