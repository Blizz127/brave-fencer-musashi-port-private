/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CDD9C - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80146DE8(s32 *a0, s32 a1, s32 a2, s32 a3);
extern void func_80146E90(s32 *a0, s32 a1);
extern void func_80146CA0(void *a0);
extern s16 D_800CE8D4;
extern void func_8014ACC0(s32 a0, s32 a1);
extern s32 func_80146578(void);
extern void func_8001CC3C(s32 a0, void *a1, s32 a2, s32 a3);
extern u8 D_800CE068[];
extern void func_800CDF64(void);
extern void func_80149374(s32 a0, s32 a1);

void func_800CDD9C(s32 param_1) {
    extern u8 D_800CE068[];
    extern s16 D_800CE8D4;
    register s32 iVar1 __asm__("$18");
    register s32 iVar2 __asm__("$16");
    u16 d;
    u16 x;

    iVar1 = *(s32 *)(param_1 + 0x4C);
    iVar2 = func_80146578();
    *(s32 *)(param_1 + 0x20) = iVar2;
    if (iVar2 != 0) {
        func_8001CC3C(iVar2, D_800CE068, 0x200, 0x100);
        *(u8 *)(iVar2 + 0x27) = 8;
        *(u32 *)(iVar2 + 4) = *(u32 *)(iVar2 + 4) | 0x50000000;
        func_80149374(iVar1, param_1 + 4);
        d = D_800CE8D4;
        x = *(u16 *)(*(s32 *)(iVar1 + 0x20) + 0x10);
        *(u16 *)(iVar2 + 0x12) = d;
        *(u16 *)(iVar2 + 0x10) = x;
        *(u16 *)(iVar2 + 0x14) = *(u16 *)(*(s32 *)(iVar1 + 0x20) + 0x14);
        *(u16 *)(param_1 + 0x60) = *(u16 *)(iVar1 + 0x100);
        *(u16 *)(param_1 + 0x62) = *(u16 *)(iVar1 + 0x102);
        *(u16 *)(param_1 + 0x64) = *(u16 *)(iVar1 + 0x104);
        *(u16 *)(iVar2 + 0x1A) = 0x1000;
        *(u16 *)(iVar2 + 0x18) = 0x1000;
        func_80146DE8((s32 *)param_1, 0, 0, 0xFFE00000);
        func_80146E90((s32 *)param_1, 8);
        func_80146CA0((void *)param_1);
        func_8014ACC0(iVar1, 1);
    } else {
        ((void (*)(s32))func_800CDF64)(param_1);
    }
}
