/* SC02.CD FILE_031 / ov_SC02_031 retail span [801600D0,80160104).
 * Offset 0x37F78 at overlay base 80128158. SHA256(span)=a1f0afdd95881e87e184f4531a1c196b5c3cec3cf2978940ec5c70e7d12151d8.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801600d0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801600D0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80147078(s32 *a0, s16 a1);
extern void func_801601AC(s32 *a0);

void func_801600D0(s32 *a0) {
    func_80147078(a0, 0x18);
    func_801601AC(a0);
}
