/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015E0D4,8015E150).
 * Offset 0x35F7C at overlay base 80128158. SHA256(span)=fb5e03317d60e5b953db44de9cfb468056674f0b9c2e00eed8877cdb174f9614.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015e0d4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015E0D4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80015978(s32 a0, s32 *a1);
extern void func_8014C1A0(s32 arg0, s32 arg1);
extern void func_8014C4AC(s32 a0, s32 a1, s32 a2, s16 *a3, s32 a4);

int func_8015E0D4(int a0)
{
    s16 sp18[4];
    s32 s0;
    s0 = *(s32 *)(a0 + 0x178);
    if (s0 != 0) {
        func_8014C1A0(a0, s0);
        func_80015978(s0 + 4, (s32 *)sp18);
        sp18[3] = 0;
        func_8014C4AC(s0, 0x11, func_80029AAC(), sp18,
                      *(s16 *)(*(s32 *)(a0 + 0x20) + 0x12));
        *(s32 *)(a0 + 0x178) = 0;
    }
}
