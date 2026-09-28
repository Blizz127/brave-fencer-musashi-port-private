/* SC02.CD FILE_031 / ov_SC02_031 retail span [801741A8,801741EC).
 * Offset 0x4C050 at overlay base 80128158. SHA256(span)=e31a60863e44a59c7e0b937dab0a52a46f14a106466f558c853d9bf148d50840.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801741a8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801741A8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8014BDC8(void);
extern void func_8014BB0C(void);
extern void func_8014B2A8(void);
extern s32 D_80078ED8;
extern s32 D_80078EA4;

void func_801741A8(s32 _arg0)
{
    func_8014BDC8();
    func_8014BB0C();
    func_8014B2A8();
    D_80078ED8 = 0xA00000;
    D_80078EA4 = 0xA00000;
}
