/* Complete SC02 retail span [80148C20,80148C34).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
#include "psx_types.h"

s32 func_80148C20(s32 a0, s16 a1) {
    s32 *p = *(s32 **)(a0 + 0x20);
    *(s16 *)((s32)p + 0x12) = a1;
    return 1;
}
