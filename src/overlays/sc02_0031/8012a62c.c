/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012A62C,8012A68C).
 * Offset 0x24D4 at overlay base 80128158. SHA256(span)=55d3909c5bfcfdcf8406c0e42c72437383731194acd911c85f4b5f133ef7966c.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012a62c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012A62C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

struct BigCopy { s32 words[41]; };

void func_8012A62C(s32 a0) {
    extern s32 D_801151D4;
    extern struct BigCopy D_80126DB8;
    extern u8 D_80127504;
    D_80126DB8 = *(struct BigCopy *)D_801151D4;
    D_80127504 = a0;
}
