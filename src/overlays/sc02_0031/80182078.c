/* Complete SC02 retail span [80182078,801820E0).
 * STOP dispatch D_80198FB8.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
#include "psx_types.h"

extern void (*D_80198FB8[])(void);
extern void func_801832D0(s16 a0, s16 a1);

void func_80182078(void *a0) {
    D_80198FB8[*(u16 *)((s32)a0 + 0x2)]();
    if (*(u16 *)((s32)a0 + 0x0) != 0) {
        func_801832D0(*(s16 *)((s32)a0 + 0xA) - 0x380, *(s16 *)((s32)a0 + 0xFE));
    }
}
