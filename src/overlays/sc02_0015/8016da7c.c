/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8016DA7C - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_801465C0(void);
extern void func_80128EA8(s32 a0, s32 a1, s32 a2);
extern void func_80146C3C();
extern void func_80146C3C(void);
extern s32 func_8001CC3C(s32 a0, s32 a1, s32 a2, s32 a3);
extern u8 D_801814E4;
extern u8 D_801814F0;

void func_8016DA7C(s32 param_1)
{
    s32 iVar1;

    iVar1 = ((s32 (*)(void))func_801465C0)();
    if (iVar1 == 0) {
        ((void (*)(s32))func_80146C3C)(param_1);
    } else {
        *(s32 *)(param_1 + 0x20) = iVar1;
        ((void (*)(s32, s32, s32, s32))func_8001CC3C)(iVar1, (s32)&D_801814E4, 0x250, 0x100);
        *(u8 *)(iVar1 + 0x27) = 0x90;
        *(u16 *)(iVar1 + 0x18) = 0x3000;
        *(u16 *)(iVar1 + 0x1a) = 0x4000;
        *(u32 *)(iVar1 + 4) = *(u32 *)(iVar1 + 4) | 0x50000000;
        func_80128EA8(iVar1, param_1 + 0x24, (s32)&D_801814F0);
        *(s32 *)(param_1 + 0x10) = 0;
        *(s32 *)(param_1 + 0x14) = 0xfff40000;
        *(s16 *)(param_1 + 2) = *(s16 *)(param_1 + 2) + 1;
    }
}
