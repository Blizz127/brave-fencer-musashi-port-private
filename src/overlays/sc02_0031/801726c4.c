/* SC02.CD FILE_031 / ov_SC02_031 retail span [801726C4,801726D0).
 * Offset 0x4A56C at overlay base 80128158. SHA256(span)=3ecaaa7bd79b98d47420bb7e44420f1c62d0d994830f012157abf030f2fa9c8b.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801726c4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801726C4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));

s32 func_801726C4(s32 *a0) {
    return *(s32*)((s32)a0 + 0x1F4) & 0x200;
}
