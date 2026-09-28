/* SC02.CD FILE_031 / ov_SC02_031 retail span [80168EC4,80168F40).
 * Offset 0x40D6C at overlay base 80128158. SHA256(span)=5f4e1dafe1416bcb284d024d95aadc7f5bed30fbb141949a7ebf27872a516184.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80168ec4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80168EC4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80168F40();
extern void func_800D22E4(s32 a0);
extern void func_80146C3C();

void func_80168EC4(s32 a0) {
    if (*(s32 *)(a0 + 0x1C) < 5) {
        func_80168F40();
        *(u16 *)(a0 + 0x10) = *(u16 *)(a0 + 0x6);
        *(u16 *)(a0 + 0x14) = *(u16 *)(a0 + 0xA);
        *(u16 *)(a0 + 0x18) = *(u16 *)(a0 + 0xE);
        func_800D22E4(a0);
        *(s32 *)(a0 + 0x1C) += 1;
    } else {
        ((void (*)(s32))func_80146C3C)(a0);
    }
}
