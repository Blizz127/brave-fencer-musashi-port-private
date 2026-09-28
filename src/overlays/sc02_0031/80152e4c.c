/* SC02.CD FILE_031 / ov_SC02_031 retail span [80152E4C,80152EFC).
 * Offset 0x2ACF4 at overlay base 80128158. SHA256(span)=7a9d77ea877c81d13c007c724980b06707a8afe0a5087d382762dd85768b3e4a.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80152e4c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80152E4C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

struct S {
    u8  pad0[0x7E]; /* 0x0..0x7D */
    u16 f7E;        /* 0x7E */
};
extern void func_80149020(s32 *a0);
extern void func_80153B58(s32 *a0);
extern void func_80147A84(s32 arg0);
extern void func_801473EC(s32 *a0);
extern void func_80148038(s32 a0, s32 a1);
extern void func_80147460(s32 a0);
extern s32 func_801472C8(struct S *a0);
extern void func_801470B4(s32 a0);
extern void func_8015369C(s32 a0);
extern void func_80146CA0(void *a0);

void func_80152E4C(s32 a0) {
    s32 s0 = a0;
    s32 v0;
    func_80149020((s32 *)s0);
    func_80153B58((s32 *)s0);
    func_80147A84(s0);
    func_801473EC((s32 *)s0);
    v0 = *(u8 *)(s0 + 0xDF);
    if (v0 == 0) {
        func_80148038(s0, 0x18000);
    } else {
        *(u8 *)(s0 + 0xDF) = v0 - 1;
    }
    func_80147460(s0);
    {
        u8 dv = *(u8 *)(s0 + 0xDE);
        *(u8 *)(s0 + 0xDE) = dv + 0xFF;
        if (dv != 0) return;
    }
    {
        *(u8 *)(s0 + 0xDE) = 0x10;
        func_801472C8(s0);
        func_801470B4(s0);
        func_8015369C(s0);
        func_80146CA0((void *)s0);
    }
}
