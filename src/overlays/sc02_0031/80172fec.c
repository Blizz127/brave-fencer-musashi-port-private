/* SC02.CD FILE_031 / ov_SC02_031 retail span [80172FEC,8017303C).
 * Offset 0x4AE94 at overlay base 80128158. SHA256(span)=0e8b72f99c6c86cb04da0a52a48fe95d17234387c0b9c179735cac555c2ed2c6.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80172fec.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80172FEC - byte-exact against retail at -O2 (tools/register_match.py). */
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
extern u8 D_800D5C6C[];
extern s32 D_80126B58;
extern s16 D_80126B30;

void func_80172FEC(void) {
    func_8017303C(D_800D5C6C);
    func_80154A74((s32)&D_80126B58, 0x11);
    D_80126B30 = 0;
    func_80174650((s32)&D_80126B58);
}
