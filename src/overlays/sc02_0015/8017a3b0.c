/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017A3B0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s16 D_80190288;

s32 func_8017A3B0(void) {
    switch (D_80190288) {
    case 0:
        return 1;
    case 1:
        return 0;
    default:
        return 1;
    }
}
