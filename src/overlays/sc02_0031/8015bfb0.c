/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015BFB0,8015BFF4).
 * Offset 0x33E58 at overlay base 80128158. SHA256(span)=3f49cef4695d63b98f0d62b87d3711d42c721668e69e9c14bd93f55a1377489a.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015bfb0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015BFB0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80147078(s32 *a0, s16 a1);
extern void func_8015C030(s32 *a0, s32 a1);

void func_8015BFB0(s32 *a0, s32 a1)
{
    func_80147078(a0, 0x4);
    func_8015C030(a0, a1);
}
