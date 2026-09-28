/* SC02.CD FILE_031 / ov_SC02_031 retail span [80165FA4,80166018).
 * Offset 0x3DE4C at overlay base 80128158. SHA256(span)=81f495dda49f3a40bbf8b781f0b22848cfa1ac171e6e4d912469af14baad94a3.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80165fa4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80165FA4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80013F3C(s32 a0);
extern void func_80020F34(s32 a0, s32 a1);
extern void func_80048FBC(void *a0, void *a1, void *a2);

s32 func_80165FA4(s32 arg0, s32 arg1, s32 arg2)
{
    s32 buf[8];
    func_80013F3C((s32)buf);
    func_80020F34((s32)buf, *(s32 *)((u8 *)arg0 + 0x20) + 0x18);
    func_80048FBC(buf, arg1, arg1);
    func_80048FBC(buf, arg2, arg2);
}
