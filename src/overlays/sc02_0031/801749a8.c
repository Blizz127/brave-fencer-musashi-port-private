/* SC02.CD FILE_031 / ov_SC02_031 retail span [801749A8,801749C8).
 * Offset 0x4C850 at overlay base 80128158. SHA256(span)=1013f37e86f0d2ed8316d17a4fa663c03c9e3af9945c888f438ae4982379160d.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801749a8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801749A8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern s32 func_801749C8();

s32 func_801749A8(s32 a0) {
    return func_801749C8(a0);
}
