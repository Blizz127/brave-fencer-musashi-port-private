/* SC02.CD FILE_031 / ov_SC02_031 retail span [801739D8,80173A20).
 * Offset 0x4B880 at overlay base 80128158. SHA256(span)=acb813bcabf9272a99316fca2e601fc795aa3779103dfe705fe1d1091959e27c.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801739d8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801739D8 - byte-exact against retail at -O2 (tools/register_match.py). */
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
extern s32 func_80174650(s32);

void func_801739D8(u8 *a0) {
    if ((*(s32 *)(a0 + 0x44) & 2) == 0) {
        func_80171A1C(a0);
        func_80174650((s32)a0);
    }
}
