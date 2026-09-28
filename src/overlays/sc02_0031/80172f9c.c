/* SC02.CD FILE_031 / ov_SC02_031 retail span [80172F9C,80172FEC).
 * Offset 0x4AE44 at overlay base 80128158. SHA256(span)=8e4f75f29a2369595a9fb11a58f653ff206269834c6b2c56c9e6c8e7078c8fb2.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80172f9c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80172F9C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_8017303C(void *);
extern void func_80154A74(s32 a0, s32 a1);
extern s32 func_80174650(s32);
extern u8 D_800D46E4[];
extern s32 D_80126B58;
extern s16 D_80126B30;

void func_80172F9C(void) {
    func_8017303C(D_800D46E4);
    func_80154A74((s32)&D_80126B58, 0x11);
    D_80126B30 = 0;
    func_80174650((s32)&D_80126B58);
}
