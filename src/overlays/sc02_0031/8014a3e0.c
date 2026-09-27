/* Complete SC02 retail span [8014A3E0,8014A454).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
#include "psx_types.h"

extern s16 D_801152B0;
extern s16 D_801152B4;

s32 func_8014A3E0(s32 a0) {
    s32 sp0;
    s32 sp8;

    sp0 = *(s16 *)(a0 + 0x12) * D_801152B0;
    sp8 = *(s16 *)(a0 + 0x1A) * D_801152B4;
    if (sp0 >= 0 && sp8 >= 0) {
        return 1;
    }
    *(s16 *)(a0 + 0x6) = *(s16 *)(a0 + 0x88);
    *(s16 *)(a0 + 0xA) = *(s16 *)(a0 + 0x8A);
    *(s16 *)(a0 + 0xE) = *(s16 *)(a0 + 0x8C);
    return 0;
}
