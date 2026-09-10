/* Complete SC02 retail span [8014891C,80148980).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
#include "psx_types.h"

s32 func_8014891C(s32 a0) {
    u8 v1;
    v1 = *(u8 *)(a0 + 0xA9);
    switch (v1) {
    case 0x41:
        return *(u16 *)(a0 + 0xAA) & 0x1000;
    case 0x53:
    case 0x73:
        return (*(u16 *)(a0 + 0xAE) >> 8) < 0x40;
    }
    return 0;
}
