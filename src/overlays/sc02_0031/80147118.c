/* Complete SC02 retail span [80147118,80147264).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
#include "psx_types.h"


void func_80147118(s32 a0) {
    s32 vec[3];

    vec[0] = ((s32)(*(s16 *)(a0 + 0x60) * *(s16 *)(a0 + 0x68)) / 4096);
    vec[0] = ((s32)(vec[0] * *(s16 *)(a0 + 0x70)) / 4096);
    vec[1] = ((s32)(*(s16 *)(a0 + 0x62) * *(s16 *)(a0 + 0x6A)) / 4096);
    vec[1] = ((s32)(vec[1] * *(s16 *)(a0 + 0x72)) / 4096);
    vec[2] = ((s32)(*(s16 *)(a0 + 0x64) * *(s16 *)(a0 + 0x6C)) / 4096);
    vec[2] = ((s32)(vec[2] * *(s16 *)(a0 + 0x74)) / 4096);
    if (vec[0] > 0xFFFF) {
        vec[0] = 0xFFFF;
    }
    if (vec[1] > 0xFFFF) {
        vec[1] = 0xFFFF;
    }
    if (vec[2] > 0xFFFF) {
        vec[2] = 0xFFFF;
    }
    *(u16 *)(*(s32 *)(a0 + 0x20) + 0x18) = vec[0];
    *(u16 *)(*(s32 *)(a0 + 0x20) + 0x1A) = vec[1];
    *(u16 *)(*(s32 *)(a0 + 0x20) + 0x1C) = vec[2];
}
