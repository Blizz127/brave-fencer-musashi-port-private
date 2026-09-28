/* SC02.CD FILE_031 / ov_SC02_031 retail span [80173980,801739D8).
 * Offset 0x4B828 at overlay base 80128158. SHA256(span)=77b78cf7a68c889af5d1295439765eaf54f70362d5e2a81505efd0a285e980ea.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80173980.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80173980 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_80171A1C(u8 *a0);
extern s16 D_80126B30;

void func_80173980(u8 *a0) {
    if (D_80126B30 == 0) {
        *(u16 *)(a0 + 0xAC) |= 0x80;
        *(u16 *)(a0 + 0xAA) |= 0x80;
    } else {
        *(u16 *)(a0 + 0xAC) |= 0x10;
    }
    func_80171A1C(a0);
}
