/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012A79C,8012A7D4).
 * Offset 0x2644 at overlay base 80128158. SHA256(span)=5beb3f8c1cde6fef1179313c3248a3f7630c132e8446c96225f32af9d69c63a5.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012a79c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012A79C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_8004CFEC(s32 a0, s32 a1);

s16 func_8012A79C(s16 *a0, s16 *a1) {
    s16 x0 = a0[0];
    s16 x1 = a1[0];
    s16 y0 = a0[2];
    s16 y1 = a1[2];
    return func_8004CFEC(x0 - x1, y0 - y1);
}
