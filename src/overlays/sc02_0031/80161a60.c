/* SC02.CD FILE_031 / ov_SC02_031 retail span [80161A60,80161A90).
 * Offset 0x39908 at overlay base 80128158. SHA256(span)=cea4ec9c09c16a30454c3eafcfe6e7b316818c82fff600bcd8b78b238f5e4327.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80161a60.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80161A60 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_80078EC0;

s32 func_80161A60(s32 a0) {
    s32 v0;
    if (*(s16*)(a0 + 0x1C8) != 0) {
        v0 = ((D_80078EC0 & 0x7F) ^ 6) == 0;
        return v0;
    }
    return 0;
}
