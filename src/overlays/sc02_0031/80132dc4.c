/* SC02.CD FILE_031 / ov_SC02_031 retail span [80132DC4,80132E6C).
 * Offset 0xAC6C at overlay base 80128158. SHA256(span)=578670785d8c1b643f51c3da411965805774dd43f2a29b5d8ecc603f3e10a851.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80132dc4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80132DC4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s32 func_80047E98(void *a0, void *a1);

void func_80132DC4(s32 a0, s32 a1, s32 a2) {
    s16 in[3];
    s16 out[4];
    in[0] = (u16)*(u16 *)(a1 + 0x0) - *(u16 *)(a0 + 0x6);
    in[1] = (u16)*(u16 *)(a1 + 0x2) - *(u16 *)(a0 + 0xA);
    in[2] = (u16)*(u16 *)(a1 + 0x4) - *(u16 *)(a0 + 0xE);
    func_80047E98(&in[0], &out[0]);
    *(s32 *)(a0 + 0x10) = out[0] * a2;
    *(s32 *)(a0 + 0x14) = out[1] * a2;
    *(s32 *)(a0 + 0x18) = out[2] * a2;
}
