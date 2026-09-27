/* Complete SC02 retail span [801848A8,801848E4).
 * D_801AB158 dispatch (STOP).
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
#include "psx_types.h"

extern void (*D_801AB158[])(void);

void func_801848A8(void *a0) {
    D_801AB158[*(u16 *)((s32)a0 + 0x2)]();
}
