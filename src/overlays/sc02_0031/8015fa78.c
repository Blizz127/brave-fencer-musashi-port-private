/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015FA78,8015FAAC).
 * Offset 0x37920 at overlay base 80128158. SHA256(span)=906551006d432fecaf85cf6071560c49d4f50c47dc89486b29e3a24b56d6ef95.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015fa78.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015FA78 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80147078(s32 *a0, s16 a1);
extern void func_8015FAAC();

void func_8015FA78(s32 *a0) {
    func_80147078(a0, 0x16);
    func_8015FAAC(a0);
}
