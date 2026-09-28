/* SC02.CD FILE_031 / ov_SC02_031 retail span [80172E94,80172ED4).
 * Offset 0x4AD3C at overlay base 80128158. SHA256(span)=60fcbf7ade855824a06e4b98d90939e13964b8c194e7a92d22b834ecb8c47202.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80172e94.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80172E94 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_800D5A34[];
extern s32 D_80126B58;
extern s16 D_80126B30;
extern void func_8017303C(void *);
extern s32 func_80174650(s32);

void func_80172E94(void) {
    func_8017303C((void *)D_800D5A34);
    D_80126B30 = 0;
    func_80174650((s32)&D_80126B58);
}
