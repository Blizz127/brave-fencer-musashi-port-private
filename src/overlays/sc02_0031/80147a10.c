/* Complete SC02 retail span [80147A10,80147A30).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
#include "psx_types.h"


extern void func_80147A30(s32 a0, s32 a1, s32 a2);

void func_80147A10(s32 a0, s32 a1) {
    func_80147A30(a0, a1, 0x1F0000);
}
