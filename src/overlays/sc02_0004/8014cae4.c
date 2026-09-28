/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8014CAE4 - byte-exact against retail at -O2 (tools/register_match.py). */


u16 func_8014CAE4(s32 *a0, s32 a1) {
    s32 base = a0[0x78 / 4];
    return *(u16 *)(base + a1 * 2 + 0x1C);
}
