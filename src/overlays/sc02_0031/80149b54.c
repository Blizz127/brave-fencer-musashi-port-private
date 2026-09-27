/* Complete SC02 retail span [80149B54,80149BAC).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
#include "psx_types.h"

extern s32 func_8014BEF8(s32 *a0);

s32 func_80149B54(s32 *a0) {
    if ((*(u32 *)((u8 *)a0 + 0x44) & 0x400) != 0) {
        return 0;
    }
    if (func_8014BEF8(a0) == 0) {
        return 0;
    }
    return (*(u16 *)((u8 *)a0 + 0xAC) & 0x10) != 0;
}
