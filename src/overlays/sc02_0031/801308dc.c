/* SC02.CD FILE_031 / ov_SC02_031 retail span [801308DC,80130974).
 * Offset 0x8784 at overlay base 80128158. SHA256(span)=b0062d71236415fe3b2bf19f3e7bcc0e684863fde9fb4a75f14b7287c5766db5.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801308dc.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801308DC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_80131CA8(int a0, int a1);

void func_801308DC(s32 a0) {
    *(u8 *)(a0 + 0xC1) = 0xE;
    if ((*(s32 *)(a0 + 0xB4) & 0x8000) != 0) {
        *(s32 *)(a0 + 0x1C) = 0x10;
        *(s16 *)(a0 + 0xAA) = 0;
        *(s16 *)(a0 + 0x5C) = 0;
        *(s16 *)(a0 + 0x98) = 0;
        *(s16 *)(*(s32 *)(a0 + 0x20) + 0x18) = 0x400;
        *(s16 *)(*(s32 *)(a0 + 0x20) + 0x1C) = 0x400;
        *(s16 *)(*(s32 *)(a0 + 0x20) + 0x1A) = 0x200;
        *(u16 *)(*(s32 *)(a0 + 0x20) + 0x2C) |= 0x10;
        func_8002D4C8(0x68A, 0);
    }
    func_80131CA8(a0, 0x2A);
}
