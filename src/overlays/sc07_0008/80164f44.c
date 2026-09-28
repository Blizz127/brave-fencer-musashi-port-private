/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80164F44 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80146E90(s32 *a0, s32 a1);
extern void func_80146CA0(void *a0);
extern void func_80165124(void *a0);
extern s32 func_80165140(s32 a0);
extern void func_801651B8(void *a0);

void func_80164F44(void *arg0) {
    s32 iVar4;
    s16 sVar2;
    s16 sVar1;
    s16 sVar3;
    *(s16 *)((u8 *)arg0 + 0x62) = *(u16 *)((u8 *)arg0 + 0x62) + 4;
    iVar4 = *(u16 *)((u8 *)arg0 + 0x60) + 0x40;
    *(s16 *)((u8 *)arg0 + 0x60) = iVar4;
    sVar2 = *(u16 *)((u8 *)arg0 + 0x2E) - iVar4;
    *(s16 *)((u8 *)arg0 + 0x2E) = sVar2;
    *(s16 *)((u8 *)arg0 + 0x2C) = sVar2;
    if (sVar2 < 0x1000) {
        *(s16 *)((u8 *)arg0 + 0x2E) = 0x1000;
        *(s16 *)((u8 *)arg0 + 0x2C) = 0x1000;
        *(s16 *)((u8 *)arg0 + 0x60) = 0x80;
        func_80146E90((s32 *)arg0, 0xE);
        func_80146CA0(arg0);
    }
    func_80165124(arg0);
    sVar3 = 2;
    if (*(s16 *)((u8 *)arg0 + 0x2C) < 0x2800) {
        sVar1 = *(u16 *)((u8 *)arg0 + 0x66) + 1;
    } else {
        sVar3 = 3;
        sVar1 = *(u16 *)((u8 *)arg0 + 0x66) + 1;
    }
    *(s16 *)((u8 *)arg0 + 0x66) = sVar1;
    if (sVar1 == sVar3) {
        func_80165140((s32)arg0);
        *(s16 *)((u8 *)arg0 + 0x66) = 0;
    }
    func_801651B8(arg0);
}
