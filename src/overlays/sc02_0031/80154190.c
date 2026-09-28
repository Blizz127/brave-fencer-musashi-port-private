/* SC02.CD FILE_031 / ov_SC02_031 retail span [80154190,801541D8).
 * Offset 0x2C038 at overlay base 80128158. SHA256(span)=0b1f469ab71439efc0e7a00288746ab2a15a12dc5c06dc127593d5a42c63e04f.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80154190.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80154190 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80154418(void *a0);

void func_80154190(u8 *a0, s32 a1) {
    s32 v1 = *(s32 *)((a1 << 2) + *(s32 *)(a0 + 0xB0));
    *(s16 *)(a0 + 0xBA) = 1;
    *(s16 *)(a0 + 0xB8) = 1;
    *(s8 *)(a0 + 0xBC) = 0;
    *(s8 *)(a0 + 0xBD) = 0;
    *(s8 *)(a0 + 0xDC) = 0;
    *(s32 *)(a0 + 0xB4) = v1;
    func_80154418((void *)a0);
}
