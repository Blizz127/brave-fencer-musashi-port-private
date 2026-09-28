/* SC02.CD FILE_031 / ov_SC02_031 retail span [80175624,80175668).
 * Offset 0x4D4CC at overlay base 80128158. SHA256(span)=80adec3c14f7ae7fd59206472920535927d3f9a680b9c5f0a0c9c19cebc7e32a.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80175624.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80175624 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern s16 D_800B9A02;
extern void func_801757A0(s32);

void func_80175624(void *a0) {
    func_801757A0(D_800B9A02);
    *((u8 *)a0 + 1) = *((u8 *)a0 + 1) + 1;
}
