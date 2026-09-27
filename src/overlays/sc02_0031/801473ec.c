/* Complete SC02 retail span [801473EC,80147460).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
#include "psx_types.h"


void func_801473EC(s32 *a0) {
    a0[1] += a0[4];
    a0[2] += a0[5];
    a0[3] += a0[6];
    if (a0[4] != 0 || a0[5] != 0 || a0[6] != 0) {
        a0[0x11] |= 0x80000000;
    }
}
