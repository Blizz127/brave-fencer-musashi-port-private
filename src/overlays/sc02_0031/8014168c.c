/* SC02.CD FILE_031 / ov_SC02_031 retail span [8014168C,801416D4).
 * Offset 0x19534 at overlay base 80128158. SHA256(span)=b37b00aa11d293f650da8bc32d73f915182ba2e6f707ac2a826a43c3dfa29ab9.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8014168c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014168C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern u8 D_80115148[];
extern u8 D_80115149[];
extern u8 D_80115158[];

s16 func_8014168C(s16 a0) {
    s32 i = a0 * 2;
    return D_80115148[i] + D_80115149[i] * D_80115158[i];
}
