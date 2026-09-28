/* SC02.CD FILE_031 / ov_SC02_031 retail span [80151664,801516F0).
 * Offset 0x2950C at overlay base 80128158. SHA256(span)=a9ef468d8df37091cbe63d7920f6db95a6496bc75e3844e0e1e7b68b5c69de99.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80151664.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80151664 - byte-exact against retail at -O2 (tools/register_match.py). */
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
extern void func_801470AC(s32 *a0);
extern void func_801472B4(void *a0);
extern void func_801477E8(s32 *a0, s32 a1);
extern void func_80153C18();

void func_80151664(void) {
    register s32 a0v __asm__("$4");
    s32 s0;
    s32 v1;

    s0 = a0v;
    func_80154A74(s0, 0x11);
    func_801553C0(s0);
    func_801470AC((s32 *)s0);
    func_801472B4((void *)s0);
    v1 = *(s32 *)(s0 + 0x20);
    *(s16 *)(s0 + 0x3E) = 0;
    *(s16 *)(s0 + 0x40) = 0;
    *(s16 *)(s0 + 0x42) = 0;
    *(s8 *)(s0 + 0xDD) = 0;
    *(s16 *)(s0 + 0x3C) = *(u16 *)(s0 + 0x3C) & 0xFFFE;
    *(s16 *)(v1 + 0x10) = 0;
    *(s16 *)(s0 + 0x60) = 0x1000;
    *(s16 *)(s0 + 0x62) = 0x1000;
    *(s16 *)(s0 + 0x64) = 0x1000;
    func_801477E8((s32 *)s0, 0);
    func_80153C18(s0);
}
