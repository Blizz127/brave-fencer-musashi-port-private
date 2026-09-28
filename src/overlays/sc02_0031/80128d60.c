/* SC02.CD FILE_031 / ov_SC02_031 retail span [80128D60,80128DB4).
 * Offset 0xC08 at overlay base 80128158. SHA256(span)=33ff2bb617b6b146695f0fd19c26036bcbb1a9acdd0542e9225f60f5aa71c0b9.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80128d60.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80128D60 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80018450(s32 a0, s32 a1);
extern void func_800183E0(s32 a0);

void func_80128D60(s32 a0, s32 *a1, s32 *a2) {
    a1[0] = (s32)a2;
    *(s16 *)((u8 *)a1 + 4) = 0;
    *(s16 *)((u8 *)a1 + 6) = a2[1] & 0x3F;
    if (a0 != 0) {
        func_80018450(a0, a2[0]);
    } else {
        func_800183E0(a2[0]);
    }
}
