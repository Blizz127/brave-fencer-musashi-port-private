/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8014CB2C - byte-exact against retail at -O2 (tools/register_match.py). */
extern u8 D_80126D1F;

s32 func_8014CB2C(void) {
    s32 v1 = D_80126D1F;
    if (v1 & 0x80) {
        v1 = (v1 & 0x7F) | 0x80000000;
    }
    return v1;
}
