/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015E95C,8015E9B8).
 * Offset 0x36804 at overlay base 80128158. SHA256(span)=bd0ae2cd95893fa53c208df6b72f0d5b8151d3dc2fdd2527c2d03816c78090fe.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015e95c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015E95C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern void func_8015E9B8(s32 *a0);
extern u8 D_80078EC0;

void func_8015E95C(s32 a0) {
    if ((D_80078EC0 & 0x80) == 0) {
        func_80146A6C(0x14, (void *)a0, 0, 0, 0, 0, 0);
    }
    func_8015E9B8(a0);
}
