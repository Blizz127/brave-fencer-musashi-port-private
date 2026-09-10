/* Complete SC02 retail span [8014477C,80144880).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
#include "psx_types.h"

extern s32 func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8001CA1C(s32 a0, s32 a1);
extern void func_8012A828(s32 a0, void *a1);
extern u8 D_801865B0;
extern u8 D_801865BC;

void func_8014477C(void *param_1) {
    s32 v0;
    s32 v1;
    s32 uVar2;
    s32 addr;
    s32 gv;
    s32 fv;
    s32 self = (s32)param_1;

    v0 = func_8012C1B8();
    *(s32 *)(self + 0x20) = v0;
    if (v0 == 0) {
        func_8012CAE4(param_1);
        return;
    }
    func_8001CA1C(v0, &D_801865B0);
    if (*(u16 *)(*(s32 *)(self + 0x64)) != 0) {
        *(s16 *)(self + 0xFC) = *(u16 *)(*(s32 *)(self + 0x64) + 0x36);
        uVar2 = *(s32 *)(*(s32 *)(self + 0x64) + 0x58);
        if (uVar2 != 0) {
            addr = uVar2 & 0xFFFFFFF;
            gv = *(u16 *)((addr | 0x80000000) + 8);
            fv = *(u16 *)(self + 0xA) - 0x30;
            *(u16 *)(self + 0xA) = gv + fv;
        } else {
            *(u16 *)(self + 0xA) = *(u16 *)(self + 0xA) - 0x60;
        }
    }
    func_8012A828(self, &D_801865BC);
    v1 = (s32)*(s16 *)(self + 0x70) << 0xC;
    *(s16 *)(self + 0x2) = 1;
    *(s16 *)(*(s32 *)(self + 0x20) + 0x12) = v1 / 3;
    *(s32 *)(self + 0x1C) = 0x78;
}
