/* Complete SC02 retail span [8014A2E4,8014A380).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
#include "psx_types.h"

extern u8 D_801202A0[];
extern s32 func_8014C278(s32 a0, s32 a1, s32 a2);

s32 func_8014A2E4(s32 a0) {
    u32 i;
    u8 *p;

    i = 0;
    p = D_801202A0;
    do {
        if (*(u16 *)(p + 0x0) != 0 && (*(u16 *)(p + 0x5C) & 0x8000) &&
            *(s16 *)(p + 0xAA) != 0 && func_8014C278(a0, (s32)p, 0x30) != 0) {
            return (s32)p;
        }
        i++;
        p += 0x10C;
    } while (i < 0x60);
    return 0;
}
