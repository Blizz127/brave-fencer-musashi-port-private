/* Complete SC02 retail span [8014A51C,8014A59C).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
#include "psx_types.h"

extern s32 func_80029178(s32 a0);

s32 func_8014A51C(s32 a0) {
    if ((func_80029178(0x1E) & 0xFF) == 0) {
        return 0;
    }
    if (*(u32 *)(a0 + 0x44) & 0x400) {
        return 0;
    }
    if (*(u8 *)(a0 + 0xA8) >= 0x19) {
        return 0;
    }
    if (*(u8 *)(a0 + 0x223) != 0) {
        return 0;
    }
    if ((*(u16 *)(a0 + 0xAC) & 0x40) == 0) {
        return 0;
    }
    return 1;
}
