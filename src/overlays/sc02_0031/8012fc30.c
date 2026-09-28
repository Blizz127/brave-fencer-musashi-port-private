/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012FC30,8012FCA4).
 * Offset 0x7AD8 at overlay base 80128158. SHA256(span)=ba5b2d1016e78992d288c8fd45bf62ed46b081f9dd8b899415e469ab31a4a496.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012fc30.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012FC30 - byte-exact against retail at -O2 (tools/register_match.py). */
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
extern void func_8012B23C(s32 a0);
extern s32 func_80131A34(s32, s32);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_80131CA8(int a0, int a1);

void func_8012FC30(s32 a0) {
    *(s8 *)(a0 + 0xC1) = 0xA;
    if (*(s32 *)(a0 + 0xB4) & 0x400) {
        func_80131B14();
        *(s8 *)(a0 + 0xC2) = 0;
        *(u16 *)(a0 + 0x98) = 0;
        func_8012B23C(a0);
        func_80131A34(a0, 8);
        func_8002D4C8(0xA74, 0);
    }
    func_80131CA8(a0, 0x1A);
}
