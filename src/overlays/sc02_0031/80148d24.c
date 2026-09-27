/* Complete SC02 retail span [80148D24,80148D3C).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
#include "psx_types.h"

s32 func_80148D24(void *a0, s32 a1) {
    s32 p = *(s32 *)((u8 *)a0 + 0x20);
    *(s16 *)(p + 0x12) = (a1 - 0x800) & 0xFFF;
    return 1;
}
