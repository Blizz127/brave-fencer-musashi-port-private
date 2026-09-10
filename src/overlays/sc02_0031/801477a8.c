/* Complete SC02 retail span [801477A8,801477C8).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
#include "psx_types.h"


void func_801477A8(s32 a0, s32 a1) {
    s32 v1 = *(s32 *)(a0 + 0x20);

    *(s16 *)(v1 + 0x12) = (*(u16 *)(v1 + 0x12) + a1) & 0xFFF;
}
