/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8016BBE0 - byte-exact against retail at -O2 (tools/register_match.py). */
typedef s32 M2C_UNK;
extern void func_801465C0(void);
extern void func_80146C3C();
extern void func_80146C3C(void);

s32 func_8016BBE0(s32 param_1) {
    extern void func_8016BF34(void *a0);
    extern void func_8016BF50(s32);
    extern void func_8001CF00(s32);
    extern M2C_UNK D_801A008C;
    extern u8 D_801A008D;
    extern u8 D_801A008E;
    extern M2C_UNK D_801A0090;
    extern u8 D_801A0091;
    extern u8 D_801A0092;

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
        (*(u8 *)&D_801A008C) = 0x20;
        D_801A008D = 0x20;
        D_801A008E = 0;
        (*(u8 *)&D_801A0090) = 0xc0;
        D_801A0091 = 0xc0;
        D_801A0092 = 0;
        *(u16 *)(((int)param_1) + 2) += 1;
    } else {
        ((void (*)(s32))func_80146C3C)(((int)param_1));
    }
}
