/* Complete SC02 retail span [80148C84,80148C9C).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
#include "psx_types.h"

s32 func_80148C84(s32 a0, s32 a1) {
    *(s16 *)(*(s32 *)(a0 + 0x20) + 0x12) = (a1 + 0x600) & 0xFFF;
    return 1;
}
