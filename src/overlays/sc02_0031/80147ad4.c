/* Complete SC02 retail span [80147AD4,80147B18).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
#include "psx_types.h"


extern void func_80147CC8(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4);
extern void func_80147B5C(s32 a0, s32 a1);

void func_80147AD4(s32 a0, s32 a1, s32 a2, s32 a3) {
    s32 buf[4];

    func_80147CC8(a0, a1, a2, a3, (s32)buf);
    func_80147B5C(a0, (s32)buf);
}
