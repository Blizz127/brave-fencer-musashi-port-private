/* SC02 resident retail span [8015A2D8,8015A3C8). Offset 0x32180 at base 80128158.
 * SHA256(span)=e0c8105229b3f88f18f5d699b5a28d337b3c4e0f196311a691a3292ffa1381d4.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910);
 * the C is the Druthulu shared/ov func_8015A2D8 shape (the two published variants differ only in the data symbol) retargeted to this member's D_80187280; oracle MATCH 60/60.
 * Not MAIN10.
 */
#include "psx_types.h"

extern s32 D_80187280;
void func_80146DB8(s32 a0, void *a1);
void func_80154150(s32 a0, s32 a1);
void func_80154A74(s32 a0, s32 a1);
void func_8014C010(s32 a0, s32 a1);
void func_801553A8(s32 a0);
void func_80172608(s32 a0);
void func_80146CA0(s32 a0);

void func_8015A2D8(s32 param_1)
{
    unsigned char bVar1;

    func_80146DB8(param_1, &D_80187280);
    if ((*(unsigned int *)(param_1 + 0x44) & 0x200) != 0) {
        func_80154150(param_1, 10);
        func_80154A74(param_1, 0x1c);
        *(int *)(param_1 + 0x2c) = 0xfffc0000;
        goto LAB_8015a38c;
    }
    bVar1 = *(unsigned char *)(param_1 + 0xa9);
    switch (bVar1) {
    case 0x41:
        func_80154150(param_1, 7);
        break;
    case 0x53:
    case 0x73:
        func_80154150(param_1, 6);
        break;
    default:
        *(int *)(param_1 + 0x23c) = 0;
        goto LAB_8015a390;
    }
    func_80154A74(param_1, 0x21);
LAB_8015a38c:
    *(int *)(param_1 + 0x23c) = 0;
LAB_8015a390:
    func_8014C010(param_1, 2);
    func_801553A8(param_1);
    func_80172608(param_1);
    func_80146CA0(param_1);
    return;
}
