/* SC02.CD FILE_031 / ov_SC02_031 retail span [80155344,80155394).
 * Offset 0x2D1EC at overlay base 80128158. SHA256(span)=fd431a96f40df7bdffcd48ecb08d018c7c90f48e94cc52a629782aa3fd85f82d.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80155344.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80155344 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 D_800DE2A4[];

void func_80155344(s32 a0) {
    s32 *p = D_800DE2A4;
    s32 v0 = *p;
    if (v0 != 0) {
        do {
            v0 |= 0x1000000;
            *p = v0;
            p += 1;
            v0 = *p;
        } while (v0 != 0);
    }
    *(s32 *)(a0 + 0x44) = *(s32 *)(a0 + 0x44) & 0xCFFFFFFF;
}
