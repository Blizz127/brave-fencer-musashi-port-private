/* Complete SC02 retail span [8017CB7C,8017CBB8).
 * STOP D_80198780 dispatch.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
#include "psx_types.h"
extern void (*D_80198780[])(void);
void func_8017CB7C(void *a0) { D_80198780[*(u16 *)((s32)a0 + 0x2)](); }
