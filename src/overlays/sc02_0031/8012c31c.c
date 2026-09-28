/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012C31C,8012C354).
 * Offset 0x41C4 at overlay base 80128158. SHA256(span)=27fd6b363299ddfcb53527f6455306a523512e572bde01b4e9ae480f10f5042c.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012c31c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012C31C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern u8 D_80120194[];

s32 func_8012C31C(void) {
    s32 a0;
    s32 v1;
    a0 = (s32)D_80120194;
    v1 = a0 + 0x6480;
    if (v1 != a0) {
        do {
            if (*(u16 *)v1 == 0) {
                return v1;
            }
            v1 -= 0x10C;
        } while (v1 != a0);
    }
    return 0;
}
