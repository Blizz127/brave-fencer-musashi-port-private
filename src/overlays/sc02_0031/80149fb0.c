/* Complete SC02 retail span [80149FB0,8014A048).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
#include "psx_types.h"

extern s32 D_80186828[];
extern u8 D_80078E78[];
extern s16 D_800C9A08; /* currentLocationId */

s32 func_80149FB0(s32 a0) {
    s32 *p = &D_80186828[0];
    s32 v = *p;
    u8 *q = &D_80078E78[0];
    s32 loc;

    if (v != 0) {
        loc = D_800C9A08;
        p = p + 1;
        do {
            if (loc == v) {
                return 0;
            }
            v = *p;
            p = p + 1;
        } while (v != 0);
    }

    if ((*(u32 *)(a0 + 0x44) & 0x400) != 0) {
        return 0;
    }
    if (*(s16 *)(a0 + 0x1C8) != 0) {
        return 0;
    }
    if ((*(u16 *)(a0 + 0xAC) & 0x100) == 0) {
        return 0;
    }
    v = q[0x48];
    q[0x48] = (u8)(v ^ 0x80);
    return 1;
}
