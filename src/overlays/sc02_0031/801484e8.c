/* Complete SC02 retail span [801484E8,80148534).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
#include "psx_types.h"


extern s32 func_80154358(void *a0);
extern void func_801485B8(s32 a0, s32 a1, s32 a2);
extern s32 D_80126B58;

void func_801484E8(s32 a0, s32 a1) {
    s32 v0 = func_80154358(&D_80126B58);

    func_801485B8(v0 - 0x10, a0, a1);
}

