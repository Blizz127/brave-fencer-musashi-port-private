/* SC02.CD FILE_031 / ov_SC02_031 retail span [801607B8,801607E4).
 * Offset 0x38660 at overlay base 80128158. SHA256(span)=c86551bfb128cf20840cfb8d687c7431cb3e7fd852f4da2e0f276f4b63e52cd3.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801607b8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801607B8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80149048(s32 *a0);

void func_801607B8(s32 *a0) {
    a0[0x11] &= ~1;
    func_80149048(a0);
}
