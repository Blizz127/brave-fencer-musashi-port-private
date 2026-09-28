/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8014A680 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_8014A680(s32 a0) {
    u8 v = *(u8 *)(a0 + 0x1BC);
    if (v != 0) {
        *(u8 *)(a0 + 0x1BC) = v - 1;
    }
}
