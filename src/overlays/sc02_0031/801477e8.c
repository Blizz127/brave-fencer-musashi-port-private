/* Complete SC02 retail span [801477E8,80147814).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
#include "psx_types.h"


void func_801477E8(s32 *a0, s32 a1) {
    a0[0xD] = a1;
    if (a1 < -0x1F0000) {
        a0[0xD] = -0x1F0000;
    } else if (a1 > 0x1F0000) {
        a0[0xD] = 0x1F0000;
    }
}
