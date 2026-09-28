/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015E150,8015E184).
 * Offset 0x35FF8 at overlay base 80128158. SHA256(span)=b261ce93f449b8f4f14ad1c1206110d26c0f1bccb99485a0c5e430d7c51bf9f0.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015e150.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015E150 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80147078(s32 *a0, s16 a1);
extern void func_8015E22C(s32 a0);

void func_8015E150(s32 *a0) {
    func_80147078(a0, 0x10);
    func_8015E22C(a0);
}
