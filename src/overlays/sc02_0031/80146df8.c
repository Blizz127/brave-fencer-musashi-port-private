/* Complete SC02 retail span [80146DF8,80146E90).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
#include "psx_types.h"


void func_80146DF8(s32 *a0, s32 a1, s32 a2, s32 a3, s32 t0) {
    if (a1 < 0) {
        if (a1 < -t0) {
            a1 = -t0;
        }
    } else {
        if (t0 < a1) {
            a1 = t0;
        }
    }
    if (a2 < 0) {
        if (a2 < -t0) {
            a2 = -t0;
        }
    } else {
        if (t0 < a2) {
            a2 = t0;
        }
    }
    if (a3 < 0) {
        if (a3 < -t0) {
            a3 = -t0;
        }
    } else {
        if (t0 < a3) {
            a3 = t0;
        }
    }
    *(s32 *)((s32)a0 + 0x24) = a1;
    *(s32 *)((s32)a0 + 0x28) = a2;
    *(s32 *)((s32)a0 + 0x2C) = a3;
}
