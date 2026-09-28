/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012CBCC,8012CBF4).
 * Offset 0x4A74 at overlay base 80128158. SHA256(span)=a4862d2e751fbe0b3de517011ad683613974254480adcedce684361f531606f0.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012cbcc.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012CBCC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s32 func_8012CC88();
extern u8 D_800D3918[];

void func_8012CBCC(s32 a0) {
    func_8012CC88(a0, 1, (s32)D_800D3918);
}
