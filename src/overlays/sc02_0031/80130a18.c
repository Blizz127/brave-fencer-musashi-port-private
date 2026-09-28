/* SC02.CD FILE_031 / ov_SC02_031 retail span [80130A18,80130AC4).
 * Offset 0x88C0 at overlay base 80128158. SHA256(span)=ae12e882306afe6e088d534c4bcb7afa90e64af6bc8680b4a2f8f03988e21d5d.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80130a18.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80130A18 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_80131CA8(int, int);
extern s32 func_80133784(s32 a0, void *a1, s32 a2);

void func_80130A18(u8 *a0) {
    s16 b1[4];
    s16 b2[4];
    *(u16 *)(a0 + 0x5C) = *(u16 *)(a0 + 0x5C) & 0xFFFE;
    if (((s32 (*)(int, int))func_80131CA8)((int)a0, 0x34) != 0) {
        return;
    }
    b1[0] = *(u16 *)(a0 + 6);
    b1[1] = *(u16 *)(a0 + 0xA) - 0x10;
    b1[2] = *(u16 *)(a0 + 0xE);
    b2[0] = *(u16 *)(a0 + 6);
    b2[1] = *(u16 *)(a0 + 0xA) + 8;
    b2[2] = *(u16 *)(a0 + 0xE);
    if ((func_80133784(0x11, b1, (s32)b2) & 0x6000) != 0) {
        *(s8 *)(a0 + 0xC1) = 0x11;
        *(s16 *)(a0 + 0xAC) = 0x78;
    }
}
