/* Complete SC02 retail span [801446A4,8014477C).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
#include "psx_types.h"

extern s32 func_8012C194(void);
extern void func_8012CAE4(void *a0);
extern s32 func_8001CC3C(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_80128EA8(s32 a0, s32 a1, s32 a2);
extern u8 D_800D3888[];
extern u8 D_800D387C[];

void func_801446A4(s32 param_1) {
    s32 iVar1;

    iVar1 = func_8012C194();
    if (iVar1 == 0) {
        func_8012CAE4((void *)param_1);
        return;
    }
    *(s32 *)(param_1 + 0xcc) = iVar1;
    func_8001CC3C(iVar1, 0, 0, 0);
    *(s32 *)(iVar1 + 0x20) = (s32)&D_800D387C;
    *(u8 *)(iVar1 + 0x27) = 0x9c;
    *(s16 *)(iVar1 + 0x1a) = 0x3000;
    *(s16 *)(iVar1 + 0x18) = 0x3000;
    *(u32 *)(iVar1 + 4) = *(u32 *)(iVar1 + 4) | 0x50000000;
    func_80128EA8(iVar1, param_1 + 0xd0, (s32)&D_800D3888);
    *(s16 *)(iVar1 + 8) = *(u16 *)(param_1 + 6);
    *(s16 *)(iVar1 + 0xa) = *(u16 *)(param_1 + 0xa);
    *(s16 *)(iVar1 + 0xc) = *(u16 *)(param_1 + 0xe);
    *(s16 *)(param_1 + 2) = *(s16 *)(param_1 + 2) + 1;
}
