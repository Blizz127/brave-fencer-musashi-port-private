/* Complete SC02 retail span [80148038,80148094).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
#include "psx_types.h"


void func_80148038(s32 a0, s32 a1) {
    s32 v1 = *(s32 *)(a0 + 0x34);

    if (v1 < 0) {
        if (a1 < 0) {
            if ((s32)0xFFE10000 < v1) {
            } else {
                a1 = 0;
            }
        }
    } else {
        if (a1 > 0) {
            if (0x1EFFFF < v1) {
                a1 = 0;
            }
        }
    }
    *(s32 *)(a0 + 0x34) += a1;
}

