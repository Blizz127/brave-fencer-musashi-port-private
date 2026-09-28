/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80161A00 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u8 D_80078EC0;
extern u8  D_80078EC0;

s32 func_80161A00(s32 a0) {
    if (*(s16*)(a0 + 0x1C8) != 0) {
        return ((D_80078EC0 & 0x7F) ^ 0x4) == 0;
    }
    return 0;
}
