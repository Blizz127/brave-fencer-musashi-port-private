/* SC02.CD FILE_031 / ov_SC02_031 retail span [801607E4,80160818).
 * Offset 0x3868C at overlay base 80128158. SHA256(span)=44cd8ed1e941f8c5f70a7adb1b4d8a13cd020e47f974b774672fbdbd2c415d76.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801607e4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801607E4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80147078(s32 *a0, s16 a1);
extern void func_801608C0(s32 *a0);

void func_801607E4(s32 *a0) {
    func_80147078(a0, 0x1C);
    func_801608C0(a0);
}
