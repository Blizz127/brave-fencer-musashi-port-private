/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CBD68 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80149374(s32 a0, s32 a1);
extern void func_80146CA0(void *a0);

void func_800CBD68(s32 a0) {
    extern s32 D_800CC830;
    extern s32 D_800CC834;
    extern void func_80146578(void);
    extern void func_8001CD9C(s32 a0, s32 a1);
    extern void func_800233CC(void *a0, u16 a1);
    extern void func_800CBF80(void *a0);
    extern void func_80149374(s32 a0, s32 a1);
    extern void func_800D1FC8(void *a0, s32 a1);
    extern void func_80146CA0(void *a0);
    extern void func_80162CCC_w19(void *a0) __asm__("func_80162CCC");

    s32 iVar1;
    s32 iVar2;
    void *ptr;

    iVar1 = *(s32 *)(a0 + 0x4C);
    iVar2 = ((s32 (*)(void))func_80146578)();
    ptr = &D_800CC830;
    *(s32 *)(a0 + 0x20) = iVar2;
    if (iVar2 != 0) {
        func_8001CD9C(iVar2, (s32)ptr);
        func_800233CC(ptr, 0x60);
        *(u16 *)(iVar2 + 0x1A) = 0x3000;
        *(u16 *)(iVar2 + 0x18) = 0x3000;
        D_800CC834 = 0;
        func_800CBF80((void *)a0);
        *(s32 *)(iVar2 + 4) = *(s32 *)(iVar2 + 4) | 0x50000000;
        func_80149374(iVar1, a0 + 4);
        func_800D1FC8((void *)a0, 6);
        func_80146CA0((void *)a0);
    } else {
        func_80162CCC_w19((void *)a0);
    }
}
