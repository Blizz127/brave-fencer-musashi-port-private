/* Complete SC02 retail span [80149AA8,80149AD4).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
#include "psx_types.h"

s32 func_80149AA8(s32 *a0) {
    if (a0[0x44 / 4] & 0x404) {
        return 0;
    }
    return (*(u16 *)((s32)a0 + 0xAC) & 0x80) != 0;
}
