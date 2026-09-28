/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012F75C,8012F7B4).
 * Offset 0x7604 at overlay base 80128158. SHA256(span)=2952210c4385ec855bc8b97fbffc69756a36449811b2e58b6a6707473d861d95.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012f75c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012F75C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_80131B14();
extern void func_80131CA8(int a0, int a1);

void func_8012F75C(s32 a0) {
    *(u8 *)(a0 + 0xC1) = 3;
    if (*(s32 *)(a0 + 0xB4) & 0x4) {
        func_80131B14();
        *(s32 *)(a0 + 0x1C) = 0x10;
        *(s16 *)(a0 + 0x98) = 0;
    }
    func_80131CA8(a0, 6);
}
