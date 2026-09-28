/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015E184,8015E1B8).
 * Offset 0x3602C at overlay base 80128158. SHA256(span)=170c9576615f09dd39e1c89c5d4a07e6959e55d14a86ed14d3356720ae54150e.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015e184.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015E184 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80147078(s32 *a0, s16 a1);
extern s32 func_8015E1B8();

void func_8015E184(s32 *arg0)
{
    func_80147078(arg0, 0x10);
    func_8015E1B8((s32)arg0);
}
