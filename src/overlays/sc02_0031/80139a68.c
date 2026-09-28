/* SC02.CD FILE_031 / ov_SC02_031 retail span [80139A68,80139A8C).
 * Offset 0x11910 at overlay base 80128158. SHA256(span)=3f1268d759d9e5670cfa7dde30be512caa773985e4f10fd25dc54db614167dcc.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80139a68.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80139A68 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s16 D_80127540[4];

void func_80139A68(s32 a0, u16 a1) {
    if (a1 < 4) {
        D_80127540[a1] = (s16)a0;
    }
}
