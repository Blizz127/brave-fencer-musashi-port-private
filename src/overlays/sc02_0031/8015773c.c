/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015773C,80157788).
 * Offset 0x2F5E4 at overlay base 80128158. SHA256(span)=3e0303712529cc93a98edcc4629307000d622035c90801fcd48eede1cb870b30.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015773c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015773C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80154A74(s32 a0, s32 a1);
extern void func_801553C0(s32 a0);
extern void func_801553A8(s32 *a0);

s32 func_8015773C(u8 * arg0)
{
    *(s32 *)((u8 *)arg0 + 0x44) = *(s32 *)((u8 *)arg0 + 0x44) & ~2;
    func_80154A74((s32)arg0, 0x11);
    func_801553C0((s32)arg0);
    func_801553A8(arg0);
}
