/* Complete SC02 retail span [80147264,80147290).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
#include "psx_types.h"


extern s16 D_80126BB8;
extern s16 D_80126BBA;
extern s16 D_80126BBC;

void func_80147264(s32 a0) {
    D_80126BB8 = *(u16 *)(a0 + 0x0);
    D_80126BBA = *(u16 *)(a0 + 0x2);
    D_80126BBC = *(u16 *)(a0 + 0x4);
}
