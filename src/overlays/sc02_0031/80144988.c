/* Complete SC02 retail span [80144988,801449C8).
 * Matched C: Druthulu shared ov/func_80144988.h (local leaf word export).
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
#include "psx_types.h"

void func_80144988(s32 obj) {
    s32 t;

    *(u16 *)(obj + 0xA) = *(u16 *)(obj + 0xA) - 0x40;
    *(s32 *)(obj + 0x10) = *(s32 *)(*(s32 *)(obj + 0x64) + 0x10);
    *(s32 *)(obj + 0x14) = *(s32 *)(*(s32 *)(obj + 0x64) + 0x14);
    t = *(s32 *)(*(s32 *)(obj + 0x64) + 0x18);
    *(u16 *)(obj + 0x2) = *(u16 *)(obj + 0x2) + 1;
    *(s32 *)(obj + 0x18) = t;
}
