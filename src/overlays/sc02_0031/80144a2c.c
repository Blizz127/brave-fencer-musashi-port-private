/* Complete SC02 retail span [80144A2C,80144A68).
 * Matched C: Druthulu ov_SC02_031 D_8018661C dispatch (local leaf word export).
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
#include "psx_types.h"

extern void (*D_8018661C[])(void);

void func_80144A2C(void *obj) {
    D_8018661C[*(u16 *)((s32)obj + 0x2)]();
}
