/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8014A674 - byte-exact against retail at -O2 (tools/register_match.py). */


s32 func_8014A674(s32 *a0) {
    return *(u8*)((s32)a0 + 0x1BC) < 1;
}
