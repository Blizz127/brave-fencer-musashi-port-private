/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015EDD4,8015EE08).
 * Offset 0x36C7C at overlay base 80128158. SHA256(span)=36b16b1da741840eced14735d78d13e000fe73d9e8358d8eb8fac77bd8b28dfd.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015edd4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015EDD4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80147078(s32 *a0, s16 a1);
extern s32 func_8015EE08();

void func_8015EDD4(s32 *arg0) {
    func_80147078(arg0, 0x12);
    func_8015EE08((s32)arg0);
}
