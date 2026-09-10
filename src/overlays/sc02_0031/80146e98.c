/* Complete SC02 retail span [80146E98,80146EC0).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
#include "psx_types.h"


s32 func_80146E98(s32 a0) {
    s32 v0 = *(s32 *)(a0 + 0x1C);
    if (v0 != 0) {
        v0 = v0 - 1;
        *(s32 *)(a0 + 0x1C) = v0;
        return (u32)v0 < 1;
    }
    return 1;
}
