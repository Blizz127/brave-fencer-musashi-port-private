/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015F76C,8015F7A0).
 * Offset 0x37614 at overlay base 80128158. SHA256(span)=857299add91dae02551c9af1bd689a9294a425f10699640411d075aa6a2c5d27.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015f76c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015F76C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80147078(s32 *a0, s16 a1);
extern void func_8015F848(s32 *a0);

void func_8015F76C(s32 *a0) {
    func_80147078(a0, 0x15);
    func_8015F848(a0);
}
