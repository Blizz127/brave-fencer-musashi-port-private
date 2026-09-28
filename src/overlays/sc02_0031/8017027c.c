/* SC02.CD FILE_031 / ov_SC02_031 retail span [8017027C,801702B8).
 * Offset 0x48124 at overlay base 80128158. SHA256(span)=e1382562b7781d9d0eb6543d7d28e36a99b6df27f0cc9c015485df60e367b62e.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8017027c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017027C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801719A4(int a0, int a1);
extern s32 func_80171990(u8 *a0);
extern void func_801702B8(s32 a0);
extern void func_8012A568(void (*a0)(void));

void func_8017027C(u8 *a0) {
    func_801719A4((int)a0, 2);
    func_80171990(a0);
    func_801702B8((s32)a0);
}
