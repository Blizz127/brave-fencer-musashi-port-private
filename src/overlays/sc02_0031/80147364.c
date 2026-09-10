/* Complete SC02 retail span [80147364,801473DC).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
#include "psx_types.h"


extern s16 D_800B9A08;
extern s32 D_80126B58;
extern void func_80015978(void *a0, void *a1);
extern void func_8012E5CC(void *a0, s32 a1, s32 a2);
extern void func_8002D4C8(s32 a0, s32 a1);

void func_80147364(s32 arg0, s32 arg1) {
    s32 sp10;

    if (D_800B9A08 == 0x308D) {
        func_80015978((void *)((u8 *)&D_80126B58 + 4), &sp10);
        func_8012E5CC(&sp10, arg0 & 0xFFFF, arg1 & 0xFFFF);
        return;
    }
    func_8002D4C8(arg0 & 0xFFFF, arg1 & 0xFFFF);
}
