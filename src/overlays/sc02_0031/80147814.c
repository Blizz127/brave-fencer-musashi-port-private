/* Complete SC02 retail span [80147814,80147860).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
#include "psx_types.h"


void func_80147814(s32 a0, s32 a1) {
    s32 v0 = *(s32 *)(a0 + 0x34) + a1;

    *(s32 *)(a0 + 0x34) = v0;
    if (a1 < 0) {
        if (v0 < (s32)0xFFE10000) {
            *(s32 *)(a0 + 0x34) = (s32)0xFFE10000;
            return;
        }
    }
    if (a1 > 0) {
        if ((s32)0x1F0000 < *(s32 *)(a0 + 0x34)) {
            *(s32 *)(a0 + 0x34) = 0x1F0000;
        }
    }
}
