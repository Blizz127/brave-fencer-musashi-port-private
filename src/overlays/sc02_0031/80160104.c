/* SC02.CD FILE_031 / ov_SC02_031 retail span [80160104,80160138).
 * Offset 0x37FAC at overlay base 80128158. SHA256(span)=988d7dca01b9ed8d482098bb4e1f608f100b180a09333511bdfb400010cb24d0.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80160104.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80160104 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80147078(s32 *a0, s16 a1);
extern void func_80160138();

void func_80160104(s32 *a0) {
    func_80147078(a0, 0x18);
    func_80160138(a0);
}
