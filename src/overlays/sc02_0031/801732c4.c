/* SC02.CD FILE_031 / ov_SC02_031 retail span [801732C4,801732F4).
 * Offset 0x4B16C at overlay base 80128158. SHA256(span)=71608ab7ab27f4324facb9abe09740105023a312c2112943d3c16854a8f2a8fb.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801732c4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801732C4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_8016F2A8(void);
extern s32 func_80174650(s32);

void func_801732C4(s32 *a0) {
        ((void (*)(s32 *))func_8016F2A8)(a0);
        func_80174650((s32)a0);
    }
