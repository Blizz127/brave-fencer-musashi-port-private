/* Complete SC02 retail span [80147DC0,80147E44).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
#include "psx_types.h"


extern void func_80013F3C(s32 a0);
extern void func_800126C4(s32 a0, s32 a1);
extern void func_80012558(s32 a0, s32 a1);
extern void func_800123F0(s32 a0, s32 a1);
extern void func_800484EC(s32 a0, s32 a1, s32 a2);

void func_80147DC0(s32 a0, s32 a1) {
    s32 buf[8];
    s32 q = *(s32 *)(a0 + 0x20);

    func_80013F3C((s32)buf);
    func_800126C4((s32)buf, *(s16 *)(q + 0x10));
    func_80012558((s32)buf, *(s16 *)(q + 0x12));
    func_800123F0((s32)buf, *(s16 *)(q + 0x14));
    func_800484EC((s32)buf, a0 + 0x24, a1);
}
