/* Complete SC02 retail span [80145C54,80145CEC).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
#include "psx_types.h"

extern s32 func_800291B4(s32 arg);
extern void func_800291A0(s32, s32);

void func_80145C54(void) {
    s32 a1;
    s32 v1;
    s32 s0;

    a1 = func_800291B4(0x4A) & 0xFF;
    if (a1 >= 0x20) {
        v1 = a1 + 1;
        a1 = v1;
        if ((v1 & 0xF) == 0) {
            a1 = (u32)v1 >> 4;
        }
        s0 = a1 & 0xFF;
        func_800291A0(0x4A, s0);
        func_800291A0(0x50, s0);
    }
    a1 = func_800291B4(0x4D) & 0xFF;
    if (a1 >= 0x20) {
        v1 = a1 + 1;
        a1 = v1;
        if ((v1 & 0xF) == 0) {
            a1 = (u32)v1 >> 4;
        }
        func_800291A0(0x4D, a1 & 0xFF);
    }
}
