/* SC02 resident retail span [80154C24,80154ED8). Offset 0x2CACC at base 80128158.
 * SHA256(span)=b239c927e5b6986f50632c020a174fcc8dc4cd814d2f2258617bba700ffe1f9b.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910);
 * retargeted for this member: jump table at 0x801B5BA8 (--rodata-base).
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"

extern void func_80154ED8(s32 a0, s32 a1);

void func_80154C24(s32 param_1, s32 *param_2, s32 *param_3) {
    u16 uVar2;
    s32 iVar3;
    s32 uVar5;
    s32 uVar6;

    if (*(u8 *)(param_1 + 0xd4) == 0) {
        return;
    }
    if (*param_2 == 0) {
        *(u16 *)(param_1 + 0xd4) = (u16)*(u8 *)(param_1 + 0xd4);
        *param_2 = *param_2 + 1;
    }
    uVar2 = *(u16 *)(param_1 + 0xd4) - 1;
    *(u16 *)(param_1 + 0xd4) = uVar2;
    if ((uVar2 & 0xff) != 0) {
        goto LAB_80154e6c;
    }
    switch (*(s32 *)((u32)*(u8 *)(param_1 + 0xd8) * 4 + *(s32 *)(param_1 + 0xd0))) {
    case 0:
        *(u16 *)(param_1 + 0xd4) = 0;
        *param_3 = *param_3 | 0x8000;
        *(u16 *)(param_1 + 0xd6) = 0;
        *(u8 *)(param_1 + 0xd8) = 0;
        *(u8 *)(param_1 + 0xd9) = 0;
        break;
    case 1:
        *(u16 *)(param_1 + 0xd4) = 1;
        *param_3 = *param_3 | 0x8000;
        *(u8 *)(param_1 + 0xd8) = 0;
        *(u8 *)(param_1 + 0xd9) = 0;
        func_80154C24(param_1, param_2, param_3);
        break;
    case 2:
        *(u16 *)(param_1 + 0xd4) = 0;
        *(s8 *)(param_1 + 0xd8) = *(s8 *)(param_1 + 0xd8) + 1;
        goto LAB_80154e9c;
    case 3:
        uVar5 = *(s32 *)((u32)*(u8 *)(param_1 + 0xd8) * 4 + *(s32 *)(param_1 + 0xd0) + 4);
        *(u16 *)(param_1 + 0xd4) = 1;
        *(s8 *)(param_1 + 0xd8) = *(s8 *)(param_1 + 0xd8) + 2;
        *(s16 *)(param_1 + 0xd6) = (s16)uVar5;
        func_80154C24(param_1, param_2, param_3);
        break;
    case 5:
        iVar3 = (u32)*(u8 *)(param_1 + 0xd8) * 4 + *(s32 *)(param_1 + 0xd0);
        uVar5 = *(s32 *)(iVar3 + 4);
        uVar6 = *(s32 *)(iVar3 + 8);
        *(u16 *)(param_1 + 0xd4) = 1;
        *(s8 *)(param_1 + 0xd8) = (s8)uVar6;
        *(s32 *)(param_1 + 0xd0) = uVar5;
        func_80154C24(param_1, param_2, param_3);
        break;
    case 6:
        uVar6 = *(s32 *)((u32)*(u8 *)(param_1 + 0xd8) * 4 + *(s32 *)(param_1 + 0xd0) + 4);
        *(u16 *)(param_1 + 0xd4) = 1;
        *(s8 *)(param_1 + 0xd8) = (s8)uVar6;
        func_80154C24(param_1, param_2, param_3);
        break;
    case 7:
        *(u16 *)(param_1 + 0xd4) = *(u16 *)(param_1 + 0xd6);
        *param_3 = *param_3 | 0x4000;
        *(s8 *)(param_1 + 0xd8) = *(s8 *)(param_1 + 0xd8) + 1;
        *(s8 *)(param_1 + 0xd9) = *(s8 *)(param_1 + 0xd9) + 1;
        func_80154C24(param_1, param_2, param_3);
        break;
    case 8:
        *(u16 *)(param_1 + 0xd4) = *(u16 *)(param_1 + 0xd6);
        *param_3 = *param_3 | 0x2000;
        *(s8 *)(param_1 + 0xd8) = *(s8 *)(param_1 + 0xd8) + 1;
        *(s8 *)(param_1 + 0xd9) = *(s8 *)(param_1 + 0xd9) + 1;
        func_80154C24(param_1, param_2, param_3);
        break;
    default:
        func_80154ED8(param_1, *(s32 *)((u32)*(u8 *)(param_1 + 0xd8) * 4 + *(s32 *)(param_1 + 0xd0)));
        *(u16 *)(param_1 + 0xd4) = *(u16 *)(param_1 + 0xd6);
        *(s8 *)(param_1 + 0xd8) = *(s8 *)(param_1 + 0xd8) + 1;
        break;
    }
    goto LAB_80154eac;

LAB_80154e6c:
    if (uVar2 != 1) {
        goto LAB_80154eac;
    }
    if (*(s32 *)((u32)*(u8 *)(param_1 + 0xd8) * 4 + *(s32 *)(param_1 + 0xd0)) != 0) {
        goto LAB_80154eac;
    }
LAB_80154e9c:
    *param_3 = *param_3 | 0x8000;
LAB_80154eac:
    *(u16 *)(param_1 + 0xd4) = *(u16 *)(param_1 + 0xd4) | *param_3;
    return;
}
