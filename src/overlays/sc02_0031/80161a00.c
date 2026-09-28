/* SC02.CD FILE_031 / ov_SC02_031 retail span [80161A00,80161A30).
 * Offset 0x398A8 at overlay base 80128158. SHA256(span)=811ba4102566e37e1d28c442c59834a697df148e2bf3d4e17612dda0f106472d.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80161a00.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80161A00 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_80078EC0;

s32 func_80161A00(s32 a0) {
    if (*(s16*)(a0 + 0x1C8) != 0) {
        return ((D_80078EC0 & 0x7F) ^ 0x4) == 0;
    }
    return 0;
}
