/* SC02.CD FILE_031 / ov_SC02_031 retail span [801601E4,80160244).
 * Offset 0x3808C at overlay base 80128158. SHA256(span)=1dde0f473f4b3807f65c2e506cf06a63cc0cae35744d30ffcc068bb90e1e76b4.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801601e4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801601E4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80154150(s32 a0, s32 a1);
extern void func_80154A74(s32 a0, s32 a1);
extern void func_80146CA0(void *a0);
extern s32 func_80161208();

void func_801601E4(s32 *a0) {
    if (*(u16 *)((u8 *)a0 + 0xB8) == 0x8000) {
        func_80154150((s32)a0, 0x22);
        func_80154A74((s32)a0, 0x1A);
        func_80146CA0(a0);
    } else {
        ((s32 (*)(s32 *))func_80161208)(a0);
    }
}
