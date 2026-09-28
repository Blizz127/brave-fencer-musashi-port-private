/* SC02.CD FILE_031 / ov_SC02_031 retail span [80175014,8017509C).
 * Offset 0x4CEBC at overlay base 80128158. SHA256(span)=7945687738986a1d4ff367f59c1cf379a7ee4ab4fc305fde037dd72b5482e98f.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80175014.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80175014 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));

s32 func_80175014(u8 *a0, u8 *a1, s32 a2) {
    a2 = (s16)a2;
    a1 = a1 + a2 * 14;
    if (*(s16 *)(a1 + 0xC) == 0x7FFF) {
        return 1;
    }
    *(s32 *)(a0 + 0x3C) = *(s16 *)(a1 + 0);
    *(s32 *)(a0 + 0x40) = *(s16 *)(a1 + 2);
    *(s32 *)(a0 + 0x44) = *(s16 *)(a1 + 4);
    *(s32 *)(a0 + 0x48) = *(s16 *)(a1 + 6);
    *(s32 *)(a0 + 0x4C) = *(s16 *)(a1 + 8);
    *(s32 *)(a0 + 0x50) = *(s16 *)(a1 + 0xA);
    *(s32 *)(a0 + 0x54) = *(s16 *)(a1 + 0xC) << 5;
    return 0;
}
