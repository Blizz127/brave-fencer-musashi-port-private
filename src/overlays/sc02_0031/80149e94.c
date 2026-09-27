/* Complete SC02 retail span [80149E94,80149F2C).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
#include "psx_types.h"

extern u8 D_801202A0[];
extern s32 func_8016F1AC(void);
extern s32 func_80149F2C(s32 a0, s32 a1);

s32 func_80149E94(s32 a0) {
    u8 *p;

    if ((func_8016F1AC() == 0) && (*(u8 *)(a0 + 0x1C5) != 0)) {
        *(u8 *)(a0 + 0x1C5) = 0;
        for (p = D_801202A0; p < D_801202A0 + 0x6480; p += 0x10C) {
            if (func_80149F2C(a0, (s32)p) != 0) {
                return 1;
            }
        }
    }
    return 0;
}
