/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801477E8 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_801477E8(s32 *a0, s32 a1) {
    a0[0xD] = a1;
    if (a1 < -0x1F0000) {
        a0[0xD] = -0x1F0000;
    } else if (a1 > 0x1F0000) {
        a0[0xD] = 0x1F0000;
    }
}
