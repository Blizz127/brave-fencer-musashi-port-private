/* Complete SC02 retail span [80149C08,80149C94).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
#include "psx_types.h"

extern s32 func_8014BEF8(s32 a0);
extern s32 func_80029178(s32 a0);

s32 func_80149C08(s32 a0) {
    if (*(u8 *)(a0 + 0x223) != 0) {
        return 0;
    }
    if (*(s16 *)(a0 + 0x1C8) != 0) {
        return 0;
    }
    if ((*(u32 *)(a0 + 0x44) & 0x404) != 0) {
        return 0;
    }
    if (func_8014BEF8(a0) == 0) {
        return 0;
    }
    if ((func_80029178(0x89) & 0xFF) == 0) {
        return 0;
    }
    return (*(u16 *)(a0 + 0xAC) & 0x10) != 0;
}
