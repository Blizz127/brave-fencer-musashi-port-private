/* SC02.CD FILE_031 / ov_SC02_031 retail span [80172F4C,80172F9C).
 * Offset 0x4ADF4 at overlay base 80128158. SHA256(span)=82f4f7a885bea92fa9e42b56ca1e7a360a38a4f4b89a9c2ff45e4b7cfa3ebad7.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80172f4c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80172F4C - byte-exact against retail at -O2 (tools/register_match.py). */
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
extern u8 D_800D47F4[];
extern s32 D_80126B58;
extern s16 D_80126B30;

void func_80172F4C(void) {
    func_8017303C(D_800D47F4);
    func_80154A74((s32)&D_80126B58, 0x13);
    D_80126B30 = 0;
    func_80174650((s32)&D_80126B58);
}
