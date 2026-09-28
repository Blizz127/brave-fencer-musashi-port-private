/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015F260,8015F2BC).
 * Offset 0x37108 at overlay base 80128158. SHA256(span)=2aba4b6eb2b4c366ffd1f3a23e0353c922bd8debc23d9ea89938333ba62ea365.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015f260.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015F260 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801553A8(s32 *a0);
extern void func_80154A74(s32 a0, s32 a1);
extern void func_80149048(s32 *a0);

void func_8015F260(s32 *a0) {
    s32 v;
    func_801553A8(a0);
    func_80154A74((s32)a0, 0x11);
    v = a0[0x11];
    v &= -0x3;
    v &= -0x2;
    a0[0x11] = v;
    func_80149048(a0);
    *(s16 *)((u8 *)a0 + 0xF6) = 0x1000;
}
