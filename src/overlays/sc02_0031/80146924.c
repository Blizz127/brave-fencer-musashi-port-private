/* Complete SC02 retail span [80146924,80146994).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
#include "psx_types.h"


extern s32 D_8011D030;
extern s32 func_80146994(s32 a0, s32 a1, s32 a2, s32 a3);

s32 func_80146924(s32 a0, s32 a1, s32 a2, s32 a3, s32 arg5) {
    s32 count = 0;
    u8 *v1 = (u8 *)&D_8011D030;
    u8 *end = v1 + 0xA50;

    while (v1 < end) {
        if (*(u16 *)v1 == (a0 & 0xFFFF)) {
            count++;
        }
        v1 += 0x58;
    }
    if ((u32)count < (u32)arg5) {
        return func_80146994(a0 & 0xFFFF, a1, a2, a3);
    }
    return 0;
}
