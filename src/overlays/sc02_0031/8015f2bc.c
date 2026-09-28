/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015F2BC,8015F2F0).
 * Offset 0x37164 at overlay base 80128158. SHA256(span)=159cf96c7ae6ef94ce3082ae9308aadb9d5608efe7e4eb4bb3d4c2f11733928a.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015f2bc.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015F2BC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80147078(s32 *a0, s16 a1);
extern void func_8015F380();

void func_8015F2BC(s32 *a0) {
    func_80147078(a0, 0x14);
    func_8015F380(a0);
}
