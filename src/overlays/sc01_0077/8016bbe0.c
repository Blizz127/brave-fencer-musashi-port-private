/* Overlay range [8016BBE0,8016BCC0) from MAIN.CD member 0012.
 * SHA256(span)=774d37ed856bd6fa2b3f61c932fdf0fbe01463dca82e656c47d2c0869796f9c2.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8016BBE0 - byte-exact against retail at -O2 (tools/register_match.py). */
typedef s32 M2C_UNK;
extern void func_801465C0(void);
extern void func_80146C3C(u8 *a0);
extern void func_80146C3C();
extern void func_80146C3C(u8*);

s32 func_8016BBE0(s32 param_1) {
    extern void func_8016BF34(void *a0);
    extern void func_8016BF50(s32);
    extern void func_8001CF00(s32);
    extern M2C_UNK D_801D9BC4;
    extern u8 D_801D9BC5;
    extern u8 D_801D9BC6;
    extern M2C_UNK D_801D9BC8;
    extern u8 D_801D9BC9;
    extern u8 D_801D9BCA;

    int iVar1;
    int temp;

    iVar1 = ((s32 (*)(void))func_801465C0)();
    *(int *)(((int)param_1) + 0x20) = iVar1;
    if (iVar1 != 0) {
        ((void (*)(s32))func_8016BF34)(((int)param_1));
        func_8016BF50(((int)param_1));
        func_8001CF00(iVar1);
        *(s16 *)(iVar1 + 0x10) = 0;
        temp = *(int *)(((int)param_1) + 0x2c);
        *(s16 *)(iVar1 + 0x14) = 0;
        *(s16 *)(iVar1 + 0x1a) = 0;
        *(s16 *)(iVar1 + 0x18) = 0;
        *(s16 *)(iVar1 + 0x12) = temp * 0x555;
        *(s16 *)(((int)param_1) + 0x10) = 0;
        *(s16 *)(((int)param_1) + 0x14) = 0;
        (*(u8 *)&D_801D9BC4) = 0x20;
        D_801D9BC5 = 0x20;
        D_801D9BC6 = 0;
        (*(u8 *)&D_801D9BC8) = 0xc0;
        D_801D9BC9 = 0xc0;
        D_801D9BCA = 0;
        *(u16 *)(((int)param_1) + 2) += 1;
    } else {
        ((void (*)(s32))func_80146C3C)(((int)param_1));
    }
}
