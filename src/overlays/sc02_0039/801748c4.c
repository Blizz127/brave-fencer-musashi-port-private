/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801748C4 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_801748C4(s32 a0) {
    u8 v = *(u8 *)(a0 + 0x214) + 1;
    *(s32 *)(a0 + 0x44) |= 0x4000000;
    *(u8 *)(a0 + 0x214) = v;
}
