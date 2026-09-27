/* Complete SC02 retail span [80147324,80147364).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
#include "psx_types.h"


extern void func_80147364(s32 a0, s32 a1);
extern s32 D_8012707C;

void func_80147324(s32 arg0) {
    s32 temp_a0 = arg0 & 0xFFFF;

    if (temp_a0 == D_8012707C) {
        D_8012707C = 0;
        return;
    }
    func_80147364(temp_a0, 0);
}
