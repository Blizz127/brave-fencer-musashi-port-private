/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80136BC4 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_80136BC4(s32 a0) {
    if (*(s32*)(a0 + 0x8) == 0x20) {
        *(s32*)(a0 + 0x8) = a0 + 0x20;
        *(s32*)(a0 + 0xC) += a0;
        *(s32*)(a0 + 0x10) += a0;
        *(s32*)(a0 + 0x14) += a0;
        *(s32*)(a0 + 0x18) += a0;
        *(s32*)(a0 + 0x1C) += a0;
    }
}
