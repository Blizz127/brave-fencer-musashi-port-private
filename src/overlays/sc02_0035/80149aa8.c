/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80149AA8 - byte-exact against retail at -O2 (tools/register_match.py). */


s32 func_80149AA8(s32 *a0) {
    s32 v0;
    if (a0[0x44 / 4] & 0x404) {
        v0 = 0;
    } else {
        v0 = *(u16 *)((s32)a0 + 0xAC) & 0x80;
        v0 = v0 != 0;
    }
    return v0;
}
