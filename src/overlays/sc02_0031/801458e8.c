/* Complete SC02 retail span [801458E8,80145934).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
#include "psx_types.h"

extern s32 D_800AE6AC;
extern s32 D_800AE6B0;
extern s16 D_800B9A0A;
extern u8 D_80078E50;
extern void func_800D185C(u8 *a0);

void func_801458E8(void) {
    D_800AE6B0 = D_800AE6AC | 0x1000000;
    func_800D185C(&D_80078E50);
    D_800B9A0A = 0x3000;
}
