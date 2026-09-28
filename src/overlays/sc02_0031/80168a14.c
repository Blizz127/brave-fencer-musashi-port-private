/* SC02.CD FILE_031 / ov_SC02_031 retail span [80168A14,80168A88).
 * Offset 0x408BC at overlay base 80128158. SHA256(span)=da306b77d68de3f37a48925feda0079f3094d2a3ab9dc7a2f056fe6d9ae414ce.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80168a14.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80168A14 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80168BDC(s32 a0, s32 a1, s32 a2, s32 a3);
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);

void func_80168A14(s32 *a0) {
    func_80168BDC((s32)a0, 8, 1, 2);
    func_80146A6C(3, (s32)a0,
                  *(s16 *)((u8 *)a0 + 0x6),
                  *(s16 *)((u8 *)a0 + 0xA),
                  *(s16 *)((u8 *)a0 + 0xE),
                  -5, 0xC0009C00);
    *(u16 *)((u8 *)a0 + 0x2) += 1;
}
