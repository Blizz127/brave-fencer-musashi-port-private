/* Complete SC02 retail span [8012E8E0,8012E9C0).
 * Matched C: Druthulu shared ov/func_8012E8E0.h (local leaf word export).
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
#include "psx_types.h"

extern void func_80049CAC(s32 dst, s32 src);

void func_8012E8E0(s32 object, s32 vec) {
    s32 link;
    s32 transform;
    s16 combined;
    u16 z;

    link = *(s32 *)(object + 0x20);
    *(s16 *)(object + 0x6) = *(u16 *)(vec + 0x0);
    *(s16 *)(object + 0xA) = *(u16 *)(vec + 0x2);
    z = *(u16 *)(vec + 0x4);
    *(s16 *)(object + 0xC) = 0;
    *(s16 *)(object + 0x8) = 0;
    *(s16 *)(object + 0x4) = 0;
    *(s16 *)(object + 0xE) = z;

    if (link != 0) {
        *(s16 *)(link + 0x12) = *(u16 *)(vec + 0x6);
        transform = *(s32 *)(object + 0x20);
        if (transform != 0) {
            func_80049CAC(transform + 0x10, transform + 0x34);
            link = *(s32 *)(object + 0x20);
            combined = *(u16 *)(object + 0x6) + *(u16 *)(object + 0x50);
            *(s16 *)(link + 0x8) = combined;
            *(s32 *)(link + 0x48) = combined;
            combined = *(u16 *)(object + 0xA) + *(u16 *)(object + 0x52);
            *(s16 *)(link + 0xA) = combined;
            *(s32 *)(link + 0x4C) = combined;
            combined = *(u16 *)(object + 0xE) + *(u16 *)(object + 0x54);
            *(s16 *)(link + 0xC) = combined;
            *(u16 *)(link + 0x2C) = *(u16 *)(link + 0x2C) | 1;
            *(s32 *)(link + 0x50) = combined;
        }
    }
}
