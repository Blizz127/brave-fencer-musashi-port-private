/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CCF30 - byte-exact against retail at -O2 (tools/register_match.py). */


s32 func_800CCF30(void *a0) {
    if (*(s16 *)(a0 + 0x60) != 0) {
        *(s16 *)(a0 + 2) = 3;
        return 1;
    }
    return 0;
}
