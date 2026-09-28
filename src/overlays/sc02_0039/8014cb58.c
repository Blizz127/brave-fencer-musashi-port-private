/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8014CB58 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u8 D_80078EC0;

s32 func_8014CB58(void) {
    return D_80078EC0 & 0x7F;
}
