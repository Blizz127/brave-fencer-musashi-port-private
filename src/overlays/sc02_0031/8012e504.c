/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012E504,8012E544).
 * Offset 0x63AC at overlay base 80128158. SHA256(span)=3efa63ebd656a4f0113df552f32341ff0456675e4b4937f54b8b326df5886635.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012e504.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012E504 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern u8 D_801202A0[];

s32 func_8012E504(s32 a0, s32 a1) {
    s32 p;
    s32 end;
    p = (s32)D_801202A0;
    end = (s32)D_801202A0 + 0x6480;
    for (; p != end; p += 0x10C) {
        if (p != a0) {
            if (*(u16*)p == a1) {
                return p;
            }
        }
    }
    return 0;
}
