/* SC02.CD FILE_031 / ov_SC02_031 retail span [80154418,8015444C).
 * Offset 0x2C2C0 at overlay base 80128158. SHA256(span)=7ed972d933de531f7d46c596a4295db5421ccb451ab54ebd5a28144c119feac5.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80154418.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80154418 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8015444C(void *a0, s32 *a1, s32 *a2, s32 *a3);

void func_80154418(void *a0) {
    s32 sp10 = 0;
    s32 sp14 = 0;
    s32 sp18 = 0;
    func_8015444C(a0, &sp10, &sp14, &sp18);
}
