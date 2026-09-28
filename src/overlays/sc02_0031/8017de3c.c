/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017DE3C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801466B4(u16 a0, s32 a1, s32 a2, s32 a3, s32 arg5);
extern void func_8013C9C4(void *a0);
extern void func_80162FC0(s32 *a0);
extern void func_8016325C(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_8012A568(void (*a0)(void));
extern void func_8001C810(s32 a0, s32 a1);
extern void func_80147324(s32 arg0);
extern void func_80146CA0(void *a0);

void func_8017DE3C(s32 a0) {
    extern u8 D_80188910[];
    extern s32 D_801B473C;
    extern s32 D_801888C8;

    s32 iVar1;
    s32 iVar2;
    s16 sVar1;

    iVar1 = *(s32 *)(a0 + 0x4c);
    iVar2 = *(s32 *)(a0 + 0x20);
    func_8016325C(a0, 0, 0x20000, 0);
    func_80162FC0((s32 *)a0);
    if ((*(s16 *)(a0 + 0x60) == 0) && (0 < *(s32 *)(a0 + 0x28))) {
        u16 uVar1;
        *(u16 *)(iVar2 + 0x10) = 0;
        uVar1 = *(u16 *)(a0 + 0x60);
        *(u16 *)(a0 + 0x60) = uVar1 + 1;
    }
    sVar1 = *(s16 *)(iVar1 + 0xA);
    if (sVar1 < *(s16 *)(a0 + 0xA)) {
        u16 uVar1;
        s32 uVar2;
        *(s16 *)(a0 + 0xA) = sVar1;
        func_8013C9C4(D_80188910);
        *(u16 *)(a0 + 0x60) = *(u16 *)(iVar2 + 0x18);
        func_8001C810(iVar2, (s32)&D_801B473C);
        *(s32 **)(iVar2 + 0x80) = &D_801888C8;
        *(u16 *)(iVar2 + 0x2c) = *(u16 *)(iVar2 + 0x2c) | 0xA0;
        *(u32 *)(iVar2 + 4) = *(u32 *)(iVar2 + 4) | 0x50000000;
        uVar1 = *(u16 *)(a0 + 0x60);
        *(u16 *)(iVar2 + 0x1c) = uVar1;
        *(u16 *)(iVar2 + 0x1a) = uVar1;
        *(u16 *)(iVar2 + 0x18) = uVar1;
        if (*(s32 *)(a0 + 0x50) == 0) {
            *(u16 *)(iVar2 + 0x2c) = *(u16 *)(iVar2 + 0x2c) | 0x10;
            func_801466B4(0x1B, a0, 0, 0, 1);
            func_801466B4(0x1B, a0, 1, 0, 1);
            func_801466B4(0x1B, a0, 2, 0, 1);
            func_801466B4(0x1B, a0, 3, 0, 1);
            uVar2 = 0x81D;
        } else {
            uVar2 = 0xC5E;
        }
        func_80147324(uVar2);
        func_80146CA0((void *)a0);
    } else if (*(s16 *)(a0 + 0x60) != 0) {
        s16 sVar2;
        sVar2 = *(u16 *)(iVar2 + 0x1c) + 0x100;
        *(s16 *)(iVar2 + 0x1c) = sVar2;
        *(s16 *)(iVar2 + 0x1a) = sVar2;
        *(s16 *)(iVar2 + 0x18) = sVar2;
    }
}
