/* Complete SC02 retail span [80147B5C,80147C30).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
#include "psx_types.h"


extern s32 D_80127090;
extern s32 D_80127094;
extern s32 D_80127098;

void func_80147B5C(s32 a0, s32 a1) {
    if (*(s32 *)(a0 + 0x44) & 0x400000) {
        D_80127090 = *(s32 *)(a0 + 0x24);
    } else {
        D_80127090 = *(s32 *)a1;
    }
    if (*(s32 *)(a0 + 0x44) & 0x800000) {
        D_80127094 = *(s32 *)(a0 + 0x28);
    } else {
        D_80127094 = *(s32 *)(a1 + 4);
    }
    if (*(s32 *)(a0 + 0x44) & 0x1000000) {
        D_80127098 = *(s32 *)(a0 + 0x2C);
    } else {
        D_80127098 = *(s32 *)(a1 + 8);
    }
    *(s32 *)(a0 + 0x10) = D_80127090;
    *(s32 *)(a0 + 0x14) = D_80127094;
    *(s32 *)(a0 + 0x18) = D_80127098;
    D_80127090 = 0;
    D_80127094 = 0;
    D_80127098 = 0;
}
