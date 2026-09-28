/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80151880 - byte-exact against retail at -O2 (tools/register_match.py). */


s32 func_80151880(s32 a0) {
    u16 h;
    s32 v1;
    h = *(u16*)(a0 + 0x3E);
    v1 = h & 0xFF;
    if (v1 == 0x1B) return 1;
    if (v1 == 0x1C) return 1;
    if (v1 == 0xF) return 1;
    if (v1 == 0x10) return 1;
    if (v1 == 0xB) return 2;
    if (v1 != 0x1F) return (h >> 8) & 2;
    return 1;
}
