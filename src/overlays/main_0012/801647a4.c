/* Overlay range [801647A4,80164864) from MAIN.CD member 0012.
 * SHA256(span)=31cec8b116222ded3a5ea84960e6f4e3a885f71c3635bc24944a3d6f98b9c134.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801647A4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_8001C810(s32 a0, s32 a1);
extern void func_8014659C(void);
extern void func_80146CA0(void *a0);
extern void func_80164A74(s32 *a0);
extern void func_80164930(s32 a);

void func_801647A4(int param_1) {

    extern u16 D_800DF2E0;
    extern s32 D_80180F4C;
    extern u16 D_80180F80;
    extern s16 D_80180F7E;
    extern s16 D_80180F7C;
    s32 iVar1;

    iVar1 = ((s32 (*)(void))func_8014659C)();
    *(s32 *)(param_1 + 0x20) = iVar1;
    if (iVar1 != 0) {
        ((void (*)(s32, void *))func_8001C810)(iVar1, &D_800DF2E0);
        *(s32 **)(iVar1 + 0x80) = &D_80180F4C;
        *(u32 *)(iVar1 + 4) = *(u32 *)(iVar1 + 4) | 0x50000000;
        *(u16 *)(iVar1 + 0x2c) = *(u16 *)(iVar1 + 0x2c) | 0xb0;
        D_80180F80 = 0x80;
        D_80180F7E = 0x80;
        D_80180F7C = 0x80;
        *(u16 *)(iVar1 + 0x1a) = 0;
        *(u16 *)(param_1 + 0x60) = 0;
        *(u16 *)(param_1 + 0x62) = 0x200;
        ((s32 (*)(s32))func_80164A74)(param_1);
        ((void (*)(s32))func_80146CA0)(param_1);
    } else {
        func_80164930(param_1);
    }
}
