/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012B178,8012B1B4).
 * Offset 0x3020 at overlay base 80128158. SHA256(span)=b4be00ab25ae72b3410ba31c0c045dca272bdff706146ae02b92ec9192ed22f8.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012b178.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012B178 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_800484EC(s32 a0, s32 a1, s32 a2);

void func_8012B178(s32 a0, s32 a1) {
    s32 sp10[3];
    sp10[2] = a1;
    sp10[1] = 0;
    sp10[0] = 0;
    func_800484EC(*(s32 *)(a0 + 0x20) + 0x34, (s32)sp10, a0 + 0x10);
}
