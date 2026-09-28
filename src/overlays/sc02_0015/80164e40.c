/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80164E40 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u8 D_8018F298;
extern u8 D_8018F299;
extern u8 D_8018F29A;

s32 func_80164E40(void) {
    u8 *p = &D_8018F298;
    if (*p != 0) {
        *p -= 0x10;
    }
    if (D_8018F299 != 0) {
        D_8018F299 -= 0x10;
    }
    if (D_8018F29A != 0) {
        D_8018F29A -= 0x10;
    }
    return *(s32 *)p == 0;
}
