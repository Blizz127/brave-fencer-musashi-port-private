/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015F848,8015F89C).
 * Offset 0x376F0 at overlay base 80128158. SHA256(span)=8d0680274f980a4caf770183fa4c30beb0b905b7250cfe73d492508e0323e01d.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015f848.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015F848 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 D_8011F730;
extern void func_801553A8(s32 *a0);
extern void func_80154150(s32 a0, s32 a1);
extern void func_80146CA0(void *a0);

void func_8015F848(s32 *a0) {
    func_801553A8(a0);
    func_80154150((s32)a0, 0x1F);
    D_8011F730 |= 0x5;
    func_80146CA0(a0);
}
