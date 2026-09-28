/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801565C0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_801151E0[];

s32 func_801565C0(void) {
    s32 result;
    u32 i;
    result = 0;
    for (i = 0; i < 3; i++) {
        if (D_801151E0[i] & 1) {
            result |= 1;
        }
    }
    return result;
}
