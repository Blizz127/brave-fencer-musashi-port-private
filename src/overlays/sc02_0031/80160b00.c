/* SC02.CD FILE_031 / ov_SC02_031 retail span [80160B00,80160B34).
 * Offset 0x389A8 at overlay base 80128158. SHA256(span)=27f17f28c23b050cd748365b39744aff2cf939ec87abbec27a5faf84d461e5d0.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80160b00.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80160B00 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80147078(s32 *a0, s16 a1);
extern s32 func_80160B34();

void func_80160B00(s32 *arg0) {
    func_80147078(arg0, 0x1D);
    func_80160B34((s32)arg0);
}
