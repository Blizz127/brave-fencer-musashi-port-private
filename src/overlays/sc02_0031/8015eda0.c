/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015EDA0,8015EDD4).
 * Offset 0x36C48 at overlay base 80128158. SHA256(span)=c9fb0b784d548f9e3d0b7400674a076e4ab6e2cdcbd3e126fdf5c03a1dabda56.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015eda0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015EDA0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80147078(s32 *a0, s16 a1);
extern void func_8015EE7C(s32);

void func_8015EDA0(s32 *a0) {
    func_80147078(a0, 0x12);
    func_8015EE7C(a0);
}
