/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801647A4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8014659C(void);
extern void func_8001C810(s32 a0, s32 a1);
extern void func_80164A74(s32 *a0);
extern void func_80146CA0(void *a0);
extern void func_80164930(s32 a);
extern u16 D_800DF2E0;
extern s32 D_801817D4;
extern s16 D_80181808;
extern s16 D_80181806;
extern s16 D_80181804;

void func_801647A4(int param_1) {
    s32 iVar1;

    iVar1 = ((s32 (*)(void))func_8014659C)();
    *(s32 *)(param_1 + 0x20) = iVar1;
    if (iVar1 != 0) {
        ((void (*)(s32, void *))func_8001C810)(iVar1, &D_800DF2E0);
        *(s32 **)(iVar1 + 0x80) = &D_801817D4;
        *(u32 *)(iVar1 + 4) = *(u32 *)(iVar1 + 4) | 0x50000000;
        *(u16 *)(iVar1 + 0x2c) = *(u16 *)(iVar1 + 0x2c) | 0xb0;
        D_80181808 = 0x80;
        D_80181806 = 0x80;
        D_80181804 = 0x80;
        *(u16 *)(iVar1 + 0x1a) = 0;
        *(u16 *)(param_1 + 0x60) = 0;
        *(u16 *)(param_1 + 0x62) = 0x200;
        ((s32 (*)(s32))func_80164A74)(param_1);
        ((void (*)(s32))func_80146CA0)(param_1);
    } else {
        func_80164930(param_1);
    }
}
