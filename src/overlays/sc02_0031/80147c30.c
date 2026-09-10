/* Complete SC02 retail span [80147C30,80147CC8).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
#include "psx_types.h"


extern void func_80147CC8(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4);
extern s32 D_80127090;
extern s32 D_80127094;
extern s32 D_80127098;

void func_80147C30(s32 a0, s32 a1, s32 a2, s32 a3) {
    s32 out[3];
    s32 *p0 = &D_80127090;
    s32 *p1 = &D_80127094;
    s32 *p2 = &D_80127098;

    func_80147CC8(a0, a1, a2, a3, (s32)out);
    D_80127090 = out[0];
    D_80127094 = out[1];
    D_80127098 = out[2];
    *(s32 *)(a0 + 0x10) = *p0;
    *(s32 *)(a0 + 0x14) = *p1;
    *(s32 *)(a0 + 0x18) = *p2;
    D_80127090 = 0;
    D_80127094 = 0;
    D_80127098 = 0;
}
