/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015DDF0,8015DE24).
 * Offset 0x35C98 at overlay base 80128158. SHA256(span)=4ceaec41a664edb8dfe6519daf44d926cc6dbcfa5d4dc294057fb1e41864abbb.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015ddf0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015DDF0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80147078(s32 *a0, s16 a1);
extern void func_8015DECC(s32 a0);

void func_8015DDF0(s32 *a0) {
    func_80147078(a0, 0xF);
    func_8015DECC(a0);
}
