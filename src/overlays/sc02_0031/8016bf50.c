/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016BF50,8016BFA8).
 * Offset 0x43DF8 at overlay base 80128158. SHA256(span)=751fdee7319faff357bf3b3134d29d9883c72ad27b9e68c9602cf4b3e9312fbb.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016bf50.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016BF50 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80149350(s32 arg0, s32 a1, s32 a2);
extern void func_80015954(s32 a0, s32 a1);
extern void func_8012A568(void (*a0)(void));

s32 func_8016BF50(s32 param)
{
    u16 buf[3];
    s32 arg;
    arg = *(s32 *)(param + 0x34);
    buf[0] = *(u16 *)(param + 0x12);
    buf[1] = *(u16 *)(param + 0x16);
    buf[2] = *(u16 *)(param + 0x1a);
    ((void (*)(s32, void *, void *))func_80149350)(arg, buf, buf);
    ((void (*)(void *, s32))func_80015954)(buf, param + 4);
}
