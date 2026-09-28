/* SC02.CD FILE_031 / ov_SC02_031 retail span [80178BB8,80178BF8).
 * Offset 0x50A60 at overlay base 80128158. SHA256(span)=c9525716a2e2addf46ee3db3fafb60bf27ca1336f336348b1f79113bc926df0c.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80178bb8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80178BB8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_80178CBC(s32 a0, s32 a1);
extern s32 func_80178BF8();

void func_80178BB8(s32 a0, s32 a1) {
    func_80178BF8(a0, a1);
    func_80178CBC(a0, a1);
}
