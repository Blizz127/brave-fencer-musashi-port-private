/* Complete SC02 retail span [80144880,80144988).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
#include "psx_types.h"

extern s32 func_8012C194(void);
extern void func_8012CAE4(void *a0);
extern void func_8001CB6C(u8 *a0, s32 a1, s32 a2, s32 a3);
extern u8 D_80186588;
extern u8 D_801865F8;

void func_80144880(s32 self) {
    s32 obj;
    s32 b;
    s32 e;

    obj = func_8012C194();
    if (obj == 0) {
        func_8012CAE4((void *)self);
        return;
    }
    *(u16 *)(self + 0xFC) = *(u16 *)(*(s32 *)(self + 0x64) + 0x36);
    *(s32 *)(self + 0xCC) = obj;
    if (*(s16 *)(self + 0x70) == 1) {
        func_8001CB6C((u8 *)obj, (s32)&D_80186588, 0x250, 0x1A0);
        b = 0x14;
    } else {
        func_8001CB6C((u8 *)obj, (s32)&D_801865F8, 0x300, 0x1D0);
        b = 0x6A;
    }
    *(u8 *)(obj + 0x27) = (u8)b;
    *(s32 *)(obj + 4) = 0x60000000;
    *(u16 *)(obj + 0x10) = 0x400;
    *(u16 *)(obj + 8) = *(u16 *)(*(s32 *)(self + 0x64) + 6);
    *(u16 *)(obj + 0xA) = *(u16 *)(*(s32 *)(self + 0x64) + 0xA);
    e = *(u16 *)(*(s32 *)(self + 0x64) + 0xE);
    *(u16 *)(obj + 0x1A) = 0x4000;
    *(u16 *)(obj + 0x18) = 0x4000;
    *(u16 *)(obj + 0xC) = (u16)e;
    *(s16 *)(self + 2) = *(s16 *)(self + 2) + 1;
}
