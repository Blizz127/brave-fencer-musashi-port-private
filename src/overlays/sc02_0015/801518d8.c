/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801518D8 - byte-exact against retail at -O2 (tools/register_match.py). */


s32 func_801518D8(s32 a0) {
    u8 v1 = *(u8*)(a0 + 0x3E);
    if (v1 == 0x1B) return 1;
    if (v1 == 0x1C) return 1;
    if (v1 == 0xF) return 1;
    if (v1 == 0x10) return 1;
    if (v1 == 0x3) return 1;
    if (v1 != 0x13) return v1 == 0x17;
    return 1;
}
