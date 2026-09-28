/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB21C - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_8014659C(void);

void func_800CB21C(s32 a0) {
    typedef void (*Fn)(s32);
    s32 iVar1;
    s32 iVar2;

    extern void func_8001C2C4(s32 a0);
    extern void func_80149374(s32 a0, s32 a1);
    extern void func_80146DE8(s32 *a0, s32 a1, s32 a2, s32 a3);
    extern void func_80146E90(s32 *a0, s32 a1);
    extern void func_80146CA0(void *a0);
    extern void func_80162CCC(void);

    iVar1 = *(s32 *)(a0 + 0x4C);
    iVar2 = ((s32 (*)(void))func_8014659C)();
    *(s32 *)(a0 + 0x20) = iVar2;
    if (iVar2 != 0) {
        func_8001C2C4(iVar2);
        *(u32 *)(iVar2 + 4) |= 0x80000000;
        func_80149374(iVar1, a0 + 4);
        *(u16 *)(iVar2 + 0x10) = *(u16 *)(iVar1 + 0x100);
        *(u16 *)(iVar2 + 0x14) = *(u16 *)(iVar1 + 0x104);
        *(u16 *)(iVar2 + 0x12) = *(u16 *)(*(s32 *)(iVar1 + 0x20) + 0x12);
        func_80146DE8((s32 *)a0, 0, 0, (s32)0xFFC00000);
        func_80146E90((s32 *)a0, 0x10);
        func_80146CA0((void *)a0);
    } else {
        ((Fn)func_80162CCC)(a0);
    }
}
