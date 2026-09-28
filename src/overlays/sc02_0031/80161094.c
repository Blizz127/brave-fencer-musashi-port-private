/* SC02.CD FILE_031 / ov_SC02_031 retail span [80161094,801610FC).
 * Offset 0x38F3C at overlay base 80128158. SHA256(span)=786adf0207c37f80e7c8838aaf271a494caffe0632505971dc2d8a0865e3ee8d.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80161094.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80161094 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_801399F0(s32 a0);
extern void func_80139914(s32 a0);
extern void func_80129248(s16 a0);
extern u16 D_801270C0;
extern u8 D_800B9A17;

void func_80161094(s32 a0) {
    if (func_801399F0(*(s32 *)(a0 + 0x198)) != 0) {
        func_80139914(*(s32 *)(a0 + 0x198));
        *(s32 *)(a0 + 0x198) = 0;
    }
    D_801270C0 = 1;
    func_80129248(1);
    D_800B9A17 = 1;
}
