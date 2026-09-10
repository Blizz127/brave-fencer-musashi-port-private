/* Complete SC02 retail span [80144364,80144458).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
#include "psx_types.h"

extern s32 func_8012C194(void);
extern void func_8012CAE4(void *a0);
extern void func_8001CB6C(u8 *a0, s32 a1, s32 a2, s32 a3);
extern u8 D_80186588;

void func_80144364(s32 obj) {
    s32 child;
    u16 uVar2;
    s16 sVar1;

    child = func_8012C194();
    if (child == 0) {
        func_8012CAE4((void *)obj);
        return;
    }
    uVar2 = *(u16 *)(*(s32 *)(obj + 0x64) + 0x36);
    *(s32 *)(obj + 0xCC) = child;
    *(u16 *)(obj + 0xFC) = uVar2;
    func_8001CB6C((u8 *)child, (s32)&D_80186588, 0x250, 0x1A0);
    *(s32 *)(child + 4) = 0x60000000;
    *(u8 *)(child + 0x27) = 0x14;
    *(u16 *)(child + 0x10) = 0x400;
    *(u16 *)(child + 8) = *(u16 *)(*(s32 *)(obj + 0x64) + 6);
    *(u16 *)(child + 0xA) = *(u16 *)(*(s32 *)(obj + 0x64) + 0xA);
    *(u16 *)(child + 0xC) = *(u16 *)(*(s32 *)(obj + 0x64) + 0xE);
    sVar1 = *(s16 *)(obj + 0x70);
    if (sVar1 != 0) {
        *(s16 *)(child + 0x1A) = sVar1;
        *(s16 *)(child + 0x18) = sVar1;
    } else {
        *(u16 *)(child + 0x1A) = 0x2000;
        *(u16 *)(child + 0x18) = 0x2000;
    }
    *(u16 *)(obj + 2) = 1;
}
