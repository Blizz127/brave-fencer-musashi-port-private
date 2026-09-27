/* Complete SC02 retail span [80148AAC,80148AFC).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
#include "psx_types.h"

extern int func_80148AFC(void *a0);

void func_80148AAC(u8 *a0) {
    u8 *v1;
    if ((func_80148AFC(a0) & 0xff) != 0) {
        v1 = *(u8 **)(a0 + 0x20);
        *(u16 *)(v1 + 0x12) = (*(u16 *)(v1 + 0x12) + 0xFA) & 0xFF8;
    }
}
