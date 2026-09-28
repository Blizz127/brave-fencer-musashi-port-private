/* SC02.CD FILE_031 / ov_SC02_031 retail span [801735B8,801735EC).
 * Offset 0x4B460 at overlay base 80128158. SHA256(span)=3bcb58e8c956be7beaa0f9466eaea1bc3a94626a153e0b4ef931bd41b65b1616.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801735b8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801735B8 - byte-exact against retail at -O2 (tools/register_match.py). */
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

void func_801735B8(u8 *a0) {
    *(u16 *)(a0 + 0xAC) |= 0x40;
    *(u16 *)(a0 + 0xAA) |= 0x40;
    func_80171A1C(a0);
}
