/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015BF48,8015BF7C).
 * Offset 0x33DF0 at overlay base 80128158. SHA256(span)=caeebebac5cbbe51c6dc3d82b582696606d7ff6ef127f7d83e56b885fe0fe86e.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015bf48.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015BF48 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80147078(s32 *a0, s16 a1);
extern void func_8015C0C4(s32 a0);

void func_8015BF48(s32 *a0) {
    func_80147078(a0, 0x4);
    func_8015C0C4(a0);
}
