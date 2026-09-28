/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CBC7C - byte-exact against retail at -O2 (tools/register_match.py). */
#define rand func_8005C49C
extern s32 rand(void);
void func_800CB8A0(void *a0);

void func_800CBC7C(s32 param_1) {
    extern void func_800CB8A0();
    extern s32 rand(void);
    s32 iVar2;
    s32 iVar3;

    if (*(s16 *)(param_1 + 0x28) > *(s16 *)(param_1 + 0x2A)) {
        iVar2 = *(s32 *)(param_1 + 0x1C);
        if (iVar2 <= 0) {
            goto LAB_800CBCFC;
        }
        *(u16 *)(param_1 + 0x2A) = (rand() & 0x180) + 0x500;
        iVar2 = -0xA0;
    } else {
        iVar2 = *(s32 *)(param_1 + 0x1C);
        if (iVar2 >= 0) {
            goto LAB_800CBCFC;
        }
        *(u16 *)(param_1 + 0x2A) = (rand() & 0x180) + 0x800;
        iVar2 = 0xA0;
    }
    *(s32 *)(param_1 + 0x1C) = iVar2;
LAB_800CBCFC:
    *(u16 *)(param_1 + 0x28) = *(u16 *)(param_1 + 0x28) + *(s32 *)(param_1 + 0x1C);
    *(s32 *)(param_1 + 0x4C) = *(s32 *)(param_1 + 0x4C) + *(s16 *)(param_1 + 0x12);
    *(s32 *)(param_1 + 0x50) -= 3;
    *(s32 *)(param_1 + 0x54) = *(s32 *)(param_1 + 0x54) + *(s16 *)(param_1 + 0x1A);
    func_800CB8A0(param_1);
    iVar3 = *(s32 *)(param_1 + 0x30);
    *(s32 *)(param_1 + 0x30) = iVar3 - 1;
    if (iVar3 == 0) {
        *(u16 *)(param_1 + 2) += 1;
    }
}
