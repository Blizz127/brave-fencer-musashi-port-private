/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80152C80 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8014BC44(s32 a0, s32 a1);
extern void func_80154A74(s32 a0, s32 a1);
extern void func_801553C0(s32 a0);
extern void func_801470AC(s32 *a0);
extern void func_801472B4(void *a0);
extern void func_801477E8(s32 *a0, s32 a1);
extern void func_80153C18();

void func_80152C80(s32* a0)
{
    s32 s0 = a0;
    func_8014BC44(s0, *(s16 *)(s0 + 0xF2));
    *(s8 *)(s0 + 0xA8) = 0x20;
    func_80154A74(s0, 0x11);
    func_801553C0(s0);
    func_801470AC((s32 *)s0);
    func_801472B4((void *)s0);
    *(s16 *)(s0 + 0x3E) = 0;
    *(s16 *)(s0 + 0x40) = 0;
    *(s16 *)(s0 + 0x42) = 0;
    *(s8 *)(s0 + 0xDD) = 0;
    *(s16 *)(s0 + 0x3C) = *(u16 *)(s0 + 0x3C) & 0xFFFE;
    *(s16 *)(*(s32 *)(s0 + 0x20) + 0x10) = 0;
    *(s16 *)(s0 + 0x60) = 0x1000;
    *(s16 *)(s0 + 0x62) = 0x1000;
    *(s16 *)(s0 + 0x64) = 0x1000;
    func_801477E8((s32 *)s0, 0);
    func_80153C18(s0);
}
