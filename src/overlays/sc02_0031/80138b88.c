/* SC02.CD FILE_031 / ov_SC02_031 retail span [80138B88,80138BE0).
 * Offset 0x10A30 at overlay base 80128158. SHA256(span)=cf0c9a765e33c31b3a824ddfd3dfa974f7ae1b43603937d5b06679f31b19bb99.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80138b88.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80138B88 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);

void func_80138B88(s32 a0) {
    s32 a1;
    if (*(s32*)(a0 + 0x8) & 0x2000) {
        *(s16*)(a0 + 0x4) = 0xD;
    } else {
        *(s16*)(a0 + 0x4) = 0xC;
        *(s32*)(a0 + 0x8) &= ~0x1000;
        a1 = *(s32*)(a0 + 0x40);
        if (a1 != 0) {
            if (*(u16*)(a0 + 0x18) != 0) {
                *(s16*)a1 = 3;
            }
        }
    }
}
