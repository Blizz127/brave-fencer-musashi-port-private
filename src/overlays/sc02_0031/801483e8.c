/* Complete SC02 retail span [801483E8,801484B0).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
#include "psx_types.h"


extern void func_80015978(s32 a0, s32 *a1);
extern s32 func_80133784(s32 a0, void *a1, s32 a2);

void func_801483E8(u8 *self) {
    u16 src[4];
    s16 dst[4];
    s32 ret;

    func_80015978((s32)(self + 4), (s32 *)src);
    dst[0] = (s16)src[0];
    dst[1] = (s16)src[1] + 8;
    dst[2] = (s16)src[2];
    ret = func_80133784(1, src, (s32)dst);
    if (ret == 0x2000 &&
        *(s16 *)(self + 6) == dst[0] &&
        *(s16 *)(self + 0xA) == dst[1] &&
        *(s16 *)(self + 0xE) == dst[2] &&
        *(u8 *)&dst[3] == 0) {
        func_80015978((s32)(self + 4), (s32 *)(self + 0xA0));
    }
}

