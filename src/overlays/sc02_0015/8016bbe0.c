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
    extern M2C_UNK D_8018F734;
    extern u8 D_8018F735;
    extern u8 D_8018F736;
    extern M2C_UNK D_8018F738;
    extern u8 D_8018F739;
    extern u8 D_8018F73A;

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
        (*(u8 *)&D_8018F734) = 0x20;
        D_8018F735 = 0x20;
        D_8018F736 = 0;
        (*(u8 *)&D_8018F738) = 0xc0;
        D_8018F739 = 0xc0;
        D_8018F73A = 0;
        *(u16 *)(((int)param_1) + 2) += 1;
    } else {
        ((void (*)(s32))func_80146C3C)(((int)param_1));
    }
}
