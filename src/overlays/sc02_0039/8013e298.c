/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8013E298 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s16 D_80126CB0;

s32 func_8013E298(s16 *a0) {
    s32 diff;
    diff = a0[2] - D_80126CB0;
    if (diff < 0) {
        diff = -diff;
    }
    return (u32)(diff - 0x2C1) < 0x3F;
}
