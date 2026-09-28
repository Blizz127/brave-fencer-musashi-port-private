/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80149CD4 - byte-exact against retail at -O2 (tools/register_match.py). */


s32 func_80149CD4(s32 a0) {
    s32 v0;
    if (*(s32*)(a0 + 0x44) & 0x404) {
        v0 = 0;
    } else if (*(s16*)(a0 + 0x1C8) != 0) {
        v0 = 0;
    } else {
        v0 = *(u16*)(a0 + 0xAA) & 8;
        v0 = v0 != 0;
    }
    return v0;
}
