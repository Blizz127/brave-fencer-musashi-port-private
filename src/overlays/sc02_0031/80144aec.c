/* Complete SC02 retail span [80144AEC,80144B14).
 * Matched C: Druthulu shared ov/func_80144AEC.h (local leaf word export).
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
#include "psx_types.h"

extern s32 func_80144B14(s32 param);

void func_80144AEC(s32 *obj) {
    s32 old;

    old = *(s32 *)((s32)obj + 0xDC);
    *(s32 *)((s32)obj + 0xDC) = (s32)&func_80144B14;
    *(s16 *)((s32)obj + 0x0) = 0x83;
    *(s16 *)((s32)obj + 0x2) = 1;
    *(s32 *)((s32)obj + 0xCC) = old;
}
