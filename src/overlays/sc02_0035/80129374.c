/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80129374 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_80129374(s32 a0, s32 a1) {
    *(s32 *)(a0 + 0x10) = *(s32 *)(a1 + 0x10);
    *(s32 *)(a0 + 0x14) = *(s32 *)(a1 + 0x14);
    *(s32 *)(a0 + 0x18) = *(s32 *)(a1 + 0x18);
}
