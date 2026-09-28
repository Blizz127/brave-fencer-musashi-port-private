/* SC02.CD FILE_031 / ov_SC02_031 retail span [80173A28,80173A60).
 * Offset 0x4B8D0 at overlay base 80128158. SHA256(span)=3574479f5a8ec3c9147b3331cb8065cc70c6191fcfe7229118b851974b28f928.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80173a28.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80173A28 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern s32 D_8012750C;
extern void func_80173A60(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4);

void func_80173A28(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5) {
    func_80173A60(a0, a1, a2, a3, a4);
    D_8012750C = a5;
}
