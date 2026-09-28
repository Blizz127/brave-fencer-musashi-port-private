/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012FF4C,8012FF98).
 * Offset 0x7DF4 at overlay base 80128158. SHA256(span)=4218ca9f458b030683a9b20ad2245dc3b8e8197c2529e5045e6e9cd779806192.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012ff4c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012FF4C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_80131CA8(int a0, int a1);

void func_8012FF4C(s32 a0) {
    *(s8 *)(a0 + 0xC1) = 5;
    if (*(s32 *)(a0 + 0xB4) & 0x20) {
        s32 v1 = *(s32 *)(a0 + 0x20);
        *(s16 *)(a0 + 0x5C) = 0;
        *(s32 *)(a0 + 0x1C) = 0x1E;
        *(s16 *)(a0 + 0x98) = 0;
        *(s16 *)(v1 + 0x10) = 0;
    }
    func_80131CA8(a0, 0xF);
}
