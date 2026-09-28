/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8012BF10 - byte-exact against retail at -O2 (tools/register_match.py). */


s32 func_8012BF10(s32 a0, s32 a1) {
    s32 v0;
    v0 = *(s32*)(a0 + 0x1C);
    if (v0 == 0) {
        v0 = 1;
    } else {
        v0 -= 1;
        *(s32*)(a0 + 0x1C) = v0;
        v0 = (u32)v0 < 1;
    }
    if (v0 != 0) {
        *(s32*)(a0 + 0x1C) = a1;
        return 1;
    }
    return 0;
}
