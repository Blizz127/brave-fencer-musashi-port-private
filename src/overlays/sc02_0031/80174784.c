/* SC02.CD FILE_031 / ov_SC02_031 retail span [80174784,801747AC).
 * Offset 0x4C62C at overlay base 80128158. SHA256(span)=af751ceac36619c941ca9d5c13b06f1f0707b8716c54c4054c38fd510d7f75a3.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80174784.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80174784 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_8016EDEC(s32 a0, s32 a1, s32 a2);
extern s32 func_801747CC(void *a0);

void func_80174784(void) {
    ((void (*)(void *, s32))func_8016EDEC)((void *)func_801747CC, 0x1000000);
}
