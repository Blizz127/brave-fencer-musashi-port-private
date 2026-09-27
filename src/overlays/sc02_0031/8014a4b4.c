/* Complete SC02 retail span [8014A4B4,8014A4FC).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
#include "psx_types.h"

extern s32 func_80029178(s32 a0);

s32 func_8014A4B4(void *a0) {
    if ((func_80029178(0x1E) & 0xFF) != 0) {
        return (*(u16 *)((s32)a0 + 0xAC) & 0x40) != 0;
    }
    return 0;
}
