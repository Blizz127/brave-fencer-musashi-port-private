/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB480 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80146C3C(void);
extern void func_801465C0(void);
extern void func_8001CC3C(s32 a0, s32 a1, s32 a2, s32 a3);
extern u8 D_800CB648;
extern s32 D_800CB65C[1];
extern s32 D_800CB660[1];
extern s32 D_800CB664[1];

void func_800CB480(s32 arg0)
{
    s32 iVar1;

    iVar1 = ((s32 (*)(void))func_801465C0)();
    if (iVar1 == 0) {
        ((void (*)(s32))func_80146C3C)(arg0);
    } else {
        *(s32 *)(arg0 + 0x20) = iVar1;
        func_8001CC3C(iVar1, (s32)&D_800CB648, 0x1B8, 0x100);
        *(u8 *)(iVar1 + 0x27) = 0x1A;
        *(u16 *)(iVar1 + 0x1A) = 0x2000;
        *(u16 *)(iVar1 + 0x18) = 0x2000;
        *(s32 *)(arg0 + 0x10) = *(s32 *)((s32)&D_800CB65C + (*(s32 *)(arg0 + 0x2C)) * 0x10);
        *(s32 *)(arg0 + 0x14) = *(s32 *)((s32)&D_800CB660 + (*(s32 *)(arg0 + 0x2C)) * 0x10);
        *(s32 *)(arg0 + 0x18) = *(s32 *)((s32)&D_800CB664 + (*(s32 *)(arg0 + 0x2C)) * 0x10);
        *(s32 *)(arg0 + 0x1C) = 0x10;
        (*(u16 *)(arg0 + 2))++;
    }
}
