/* SC02.CD FILE_031 / ov_SC02_031 retail span [80162DE8,80162E48).
 * Offset 0x3AC90 at overlay base 80128158. SHA256(span)=e39f47913320e095f0b505937f54a59d233ae03a01560b0f2ac58f80df47a235.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80162de8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80162DE8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80013F3C(s32 a0);
extern void func_800126C4(s32 a0, s32 a1);
extern void func_80012558(s32 a0, s32 a1);
extern void func_800123F0(s32 a0, s32 a1);

void func_80162DE8(s32 *a0) {
    s16 *s0 = (s16 *)a0[8];
    s32 s1 = (s32)s0 + 0x34;
    func_80013F3C(s1);
    func_800123F0(s1, s0[10]);
    func_800126C4(s1, s0[8]);
    func_80012558(s1, s0[9]);
}
