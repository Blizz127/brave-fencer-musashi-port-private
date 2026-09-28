/* SC02.CD FILE_031 / ov_SC02_031 retail span [80130898,801308DC).
 * Offset 0x8740 at overlay base 80128158. SHA256(span)=690a5f73bac418a50711959765b7a08a0d5a2d650ea575dec5c5ef800d60b508.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80130898.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80130898 - byte-exact against retail at -O2 (tools/register_match.py). */
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

void func_80130898(u8 *a0) {
    if (*(s32 *)(a0 + 0xB4) & 0x4000) {
        *(s16 *)(a0 + 0xAA) = 0x100;
        *(u16 *)(a0 + 0x5C) = *(u16 *)(a0 + 0x5C) & 0xFFFE;
    }
    func_80131CA8((int)a0, 0x28);
}
