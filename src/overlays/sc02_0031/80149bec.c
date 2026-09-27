/* Complete SC02 retail span [80149BEC,80149C08).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
#include "psx_types.h"

void func_80149BEC(s32 a0) {
    u8 v = *(u8 *)(a0 + 0x223);
    if (v != 0) {
        *(u8 *)(a0 + 0x223) = v - 1;
    }
}
