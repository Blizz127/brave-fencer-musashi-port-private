/* Complete SC02 retail span [80149CD4,80149D10).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
#include "psx_types.h"

s32 func_80149CD4(s32 a0) {
    if (*(s32 *)(a0 + 0x44) & 0x404) {
        return 0;
    }
    if (*(s16 *)(a0 + 0x1C8) != 0) {
        return 0;
    }
    return (*(u16 *)(a0 + 0xAA) & 8) != 0;
}
