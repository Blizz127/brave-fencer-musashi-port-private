/* SC02.CD FILE_031 / ov_SC02_031 retail span [80161888,8016191C).
 * Offset 0x39730 at overlay base 80128158. SHA256(span)=885dd32f326b710620652994d93a4967da6abd6ddd1f24cb21d98bf5fe41e39e.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80161888.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80161888 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8014C010(s32 a0, s32 a1);
extern void func_80161D20();

s32 func_80161888(s32 a0, u32 a1)
{
    s32 s0 = a0;
    if (a1 & 1) {
        func_8014C010(s0, 1);
        func_80161D20(s0, *(u16*)(s0 + 0x16E));
        return 1;
    }
    if (a1 & 0x4000) {
        func_8014C010(s0, 1);
        func_80161D20(s0, *(u16*)(s0 + 0x16E));
        return 2;
    }
    if (a1 & 0x2000) {
        func_8014C010(s0, 1);
        func_80161D20(s0, *(u16*)(s0 + 0x16E));
        return 4;
    }
    return 0;
}
