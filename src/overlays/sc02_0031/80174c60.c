/* SC02.CD FILE_031 / ov_SC02_031 retail span [80174C60,80174C80).
 * Offset 0x4CB08 at overlay base 80128158. SHA256(span)=dd39b8719308e906ae62013bbd0c5f69802cc117956aa6ff5938ff8c0d18ab72.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80174c60.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80174C60 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern s32 func_80174CB0();

s32 func_80174C60(s32 a0) {
    return func_80174CB0(a0, 0);
}
