/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012F2E8,8012F374).
 * Offset 0x7190 at overlay base 80128158. SHA256(span)=be7a5a7deece95e240bd19d3a3f88e506c6017e9eb29c688fcef694621a0051a.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012f2e8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012F2E8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_8004D504(void *a0, void *a1, void *a2);

void func_8012F2E8(s32 a0, s32 a1, s32 a2) {
    s32 s0 = a2;
    s32 in[3];
    s32 out[3];
    s32 mtx;
    mtx = *(s32 *)(a0 + 0x20);
    in[0] = *(s16 *)(a1 + 0x0) - *(s32 *)(mtx + 0x48);
    in[1] = *(s16 *)(a1 + 0x2) - *(s32 *)(mtx + 0x4C);
    in[2] = *(s16 *)(a1 + 0x4) - *(s32 *)(mtx + 0x50);
    func_8004D504((void *)(mtx + 0x34), in, out);
    *(s16 *)(s0 + 0x0) = out[0];
    *(s16 *)(s0 + 0x2) = out[1];
    *(s16 *)(s0 + 0x4) = out[2];
}
