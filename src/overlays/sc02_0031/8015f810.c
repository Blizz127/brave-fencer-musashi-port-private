/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015F810,8015F848).
 * Offset 0x376B8 at overlay base 80128158. SHA256(span)=ce3b54d0f00ac416bbc8ef9a4908222c239edec8856b5a4443aa482d4fa5ced7.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015f810.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015F810 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80161104(void);
extern void func_8015F848(s32 *a0);

void func_8015F810(s32 *a0) {
    if (func_80161104() != 0) {
        func_8015F848(a0);
    }
}
