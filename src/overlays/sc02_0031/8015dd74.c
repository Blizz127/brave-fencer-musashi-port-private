/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015DD74,8015DDF0).
 * Offset 0x35C1C at overlay base 80128158. SHA256(span)=cf24d13ea4d4c1ffc03a04fcad2e652af58e3a49445da08fafa1f1fc236baf97.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015dd74.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015DD74 - byte-exact against retail at -O2 (tools/register_match.py). */
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

int func_8015DD74(int arg0)
{
    s16 sp18[4];
    s32 s0;
    s0 = *(s32 *)(arg0 + 0x178);
    if (s0 != 0) {
        func_8014C1A0(arg0, s0);
        func_80015978(s0 + 4, (s32 *)sp18);
        sp18[3] = 0;
        func_8014C4AC(s0, 9, func_80029AAC(), sp18,
                      *(s16 *)(*(s32 *)(arg0 + 0x20) + 0x12));
        *(s32 *)(arg0 + 0x178) = 0;
    }
}
