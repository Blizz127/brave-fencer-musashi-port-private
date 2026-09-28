/* SC02.CD FILE_031 / ov_SC02_031 retail span [80133060,801330E0).
 * Offset 0xAF08 at overlay base 80128158. SHA256(span)=45f95579d65472d3c3998dddcba375b41bcac46cff5ffacb786afc394bd5e2e6.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80133060.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80133060 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_801330E0(void * param_1, s16 * param_2, s32 param_3);

void func_80133060(u8 *a0, s32 *a1, s32 a2) {
    s16 tmp[3];
    tmp[0] = *(u16 *)(a0 + 2);
    tmp[1] = *(u16 *)(a0 + 6);
    tmp[2] = *(u16 *)(a0 + 0xA);
    func_801330E0(tmp, tmp, (s16)a2);
    a1[0] = tmp[0] << 16;
    a1[1] = tmp[1] << 16;
    a1[2] = tmp[2] << 16;
}
