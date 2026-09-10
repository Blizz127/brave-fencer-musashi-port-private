/* Complete SC02 retail span [80144054,80144090).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
#include "psx_types.h"

extern void (*D_80186604[])(void);

void func_80144054(void *obj) {
    D_80186604[*(u16 *)((s32)obj + 0x2)]();
}
