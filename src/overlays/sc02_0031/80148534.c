/* Complete SC02 retail span [80148534,8014856C).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
#include "psx_types.h"


extern void func_801485B8(s32 a0, s32 a1, s32 a2);
extern s32 *D_80126B78;

void func_80148534(s32 a0, s32 a1) {
    func_801485B8(*(s32 *)((s32)D_80126B78 + 0x20) - 0x8, a0, a1);
}

