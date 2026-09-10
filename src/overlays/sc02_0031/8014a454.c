/* Complete SC02 retail span [8014A454,8014A4B4).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
#include "psx_types.h"

extern s32 func_80012A60(s32 a0, s32 a1);

s32 func_8014A454(s32 a0) {
    s32 v0;

    if (*(u16 *)(a0 + 0x3C) & 0x4000) {
        v0 = (s16)func_80012A60(*(s16 *)(a0 + 0x42),
                                (*(u16 *)(*(s32 *)(a0 + 0x20) + 0x12) + 0x800) & 0xFFF);
        if (v0 < 0x2AA) {
            return 1;
        }
    }
    return 0;
}
