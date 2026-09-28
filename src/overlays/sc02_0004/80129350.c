/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80129350 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_80129350(s32 a0, s32 a1) {
    *(s32 *)(a0 + 0x4) = *(s32 *)(a1 + 0x4);
    *(s32 *)(a0 + 0x8) = *(s32 *)(a1 + 0x8);
    *(s32 *)(a0 + 0xC) = *(s32 *)(a1 + 0xC);
}
