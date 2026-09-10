/* Complete SC02 retail span [80147948,8014799C).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
#include "psx_types.h"


void func_80147948(s32 a0, s32 a1, s32 a2) {
    s32 v0 = *(s32 *)(a0 + 0x24) + a1;

    *(s32 *)(a0 + 0x24) = v0;
    if (a1 < 0) {
        if (!(-a2 < v0)) {
            *(s32 *)(a0 + 0x24) = -a2;
            return;
        }
    }
    if (a1 > 0) {
        if (!(*(s32 *)(a0 + 0x24) < a2)) {
            *(s32 *)(a0 + 0x24) = a2;
        }
    }
}
