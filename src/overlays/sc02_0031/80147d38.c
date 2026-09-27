/* Complete SC02 retail span [80147D38,80147DC0).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
#include "psx_types.h"


extern void func_80147948(s32 a0, s32 a1, s32 a2);
extern void func_801479BC(s32 a0, s32 a1, s32 a2);
extern void func_80147A30(s32 a0, s32 a1, s32 a2);
extern void func_80147DC0(s32 a0, s32 a1);

void func_80147D38(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    func_80147948(a0, a1, 0x7FFFFFFF);
    func_801479BC(a0, a2, 0x7FFFFFFF);
    func_80147A30(a0, a3, 0x7FFFFFFF);
    func_80147DC0(a0, a4);
}
