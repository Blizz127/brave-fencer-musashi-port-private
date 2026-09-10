/* Complete SC02 retail span [801449C8,80144A04).
 * Matched C: Druthulu ov_SC02_031 D_80186614 dispatch (local leaf word export).
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
#include "psx_types.h"

extern void (*D_80186614[])(void);

void func_801449C8(void *obj) {
    D_80186614[*(u16 *)((s32)obj + 0x2)]();
}
