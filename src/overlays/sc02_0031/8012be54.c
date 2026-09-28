/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012BE54,8012BE98).
 * Offset 0x3CFC at overlay base 80128158. SHA256(span)=ab0d85af5ecbe6858488550d192613e04d4f3545c3c9dca1b6807ea3cfeff5a1.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012be54.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012BE54 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_8012BE98(s32 a0, u16 *a1);
extern u16 D_80126B5E;
extern u16 D_80126B62;
extern u16 D_80126B66;

void func_8012BE54(s32 a0) {
    u16 sp[3];
    sp[0] = D_80126B5E;
    sp[1] = D_80126B62;
    sp[2] = D_80126B66;
    func_8012BE98(a0, sp);
}
