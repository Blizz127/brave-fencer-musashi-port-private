/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016F094,8016F0AC).
 * Offset 0x46F3C at overlay base 80128158. SHA256(span)=9028eee09a4afe806e5c89e6679fc1f0fadc1abe804563ed1661c02e7c67aaa5.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016f094.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016F094 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));

void func_8016F094(s32 *a0) {
    *(s32 *)((s32)a0 + 0x1F8) &= 0xFBFFFFFF;
}
