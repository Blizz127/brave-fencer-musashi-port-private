/* SC02.CD FILE_031 / ov_SC02_031 retail span [80160244,801602A4).
 * Offset 0x380EC at overlay base 80128158. SHA256(span)=7f82185de7ff01dbb06d8ffd46e4f90ee3282e43dff8c84385bd29fc87d856dc.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80160244.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80160244 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80154150(s32 a0, s32 a1);
extern void func_80154A74(s32 a0, s32 a1);
extern void func_80146CA0(void *a0);
extern s32 func_80161208();

void func_80160244(s32 *a0) {
    if (*(u16 *)((u8 *)a0 + 0xB8) == 0x8000) {
        func_80154150((s32)a0, 0x23);
        func_80154A74((s32)a0, 0x1B);
        func_80146CA0(a0);
    } else {
        ((s32 (*)(s32 *))func_80161208)(a0);
    }
}
