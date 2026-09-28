/* SC02.CD FILE_031 / ov_SC02_031 retail span [80131E38,80131E7C).
 * Offset 0x9CE0 at overlay base 80128158. SHA256(span)=80cd80415dd09828ea1768a97304b5c1f79eefbea00cf93ef1b3c69337404efe.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80131e38.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80131E38 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_80131CA8(int a0, int a1);

void func_80131E38(u8 *a0) {
    *(s8 *)(a0 + 0xC1) = 0xF;
    if (*(s32 *)(a0 + 0xB4) & 0x40000) {
        *(s32 *)(a0 + 0x1C) = 6;
        *(s16 *)(a0 + 0x5C) = 0;
    }
    func_80131CA8((int)a0, 0x39);
}
