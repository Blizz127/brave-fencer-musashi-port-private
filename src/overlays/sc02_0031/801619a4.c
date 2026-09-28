/* SC02 resident retail span [801619A4,801619D0). Offset 0x3984C at base 80128158.
 * SHA256(span)=6555e7c26f2be1e10876539ab4d55d9c63c6dd500735d6ab0d18a2b6328ff24b.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910);
 * the C is the Druthulu shared/ov func_801619A4 shape (h_exact 97f3cab9); its D_80078EC0 already matches this member; oracle MATCH 11/11.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801619A4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_80078EC0;

s32 func_801619A4(s32 *a0) {
    if (*(s16 *)((s32)a0 + 0x1C8) == 0) {
        return 0;
    }
    return D_80078EC0 & 0x7F;
}
