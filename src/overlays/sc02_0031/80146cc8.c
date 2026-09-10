/* Complete SC02 retail span [80146CC8,80146D30).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
#include "psx_types.h"


extern s32 D_80127090;
extern s32 D_80127094;
extern s32 D_80127098;

void func_80146CC8(s32 a0) {
    s32 *p = &D_80127090;
    *(s32 *)(a0 + 0x10) += *p;
    *(s32 *)(a0 + 0x14) += D_80127094;
    *(s32 *)(a0 + 0x18) += D_80127098;
    *p = 0;
    D_80127094 = 0;
    D_80127098 = 0;
}
