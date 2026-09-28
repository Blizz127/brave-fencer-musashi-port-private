/* SC02.CD FILE_031 / ov_SC02_031 retail span [801655E4,80165624).
 * Offset 0x3D48C at overlay base 80128158. SHA256(span)=dc224d423f7f01e72d425bfff61bd198cd0195486cf2708a448793e13db6a885.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801655e4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801655E4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_80078EC1;
extern u8 func_80165658(s32 a0, s32 a1);
extern void func_8014BD60(s32 a0, s32 a1);

void func_801655E4(s32 a0) {
    func_8014BD60(a0, func_80165658(a0, D_80078EC1 & 0x7F) & 0x7F);
}
