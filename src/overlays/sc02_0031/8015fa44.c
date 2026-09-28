/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015FA44,8015FA78).
 * Offset 0x378EC at overlay base 80128158. SHA256(span)=a3733d17f9241e7873860985f4f9e7223dea018b56c1c68300a8c659a0383ba5.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015fa44.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015FA44 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80147078(s32 *a0, s16 a1);
extern void func_8015FBE0(s32 *a0);

void func_8015FA44(s32 *a0) {
    func_80147078(a0, 0x16);
    func_8015FBE0(a0);
}
