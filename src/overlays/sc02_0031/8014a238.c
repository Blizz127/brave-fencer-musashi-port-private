/* Complete SC02 retail span [8014A238,8014A2E4).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
#include "psx_types.h"

extern s32 func_8014C278(s32 a0, s32 a1, s32 a2);
extern s32 func_8014C2B0(void *a0, void *a1, s32 a2);
extern u8 D_801202A0[];

s32 func_8014A238(s32 a0) {
    u32 i;
    u8 *p;

    p = D_801202A0;
    for (i = 0; i < 0x60; i++, p += 0x10C) {
        if ((*(u16 *)p != 0) && (*(s16 *)(p + 0xAA) != 0) &&
            (func_8014C278(a0, (s32)p, 0x30) != 0) &&
            (func_8014C2B0((void *)a0, (void *)p, 0x200) != 0)) {
            return (s32)p;
        }
    }
    return 0;
}
