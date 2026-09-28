/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801511A8 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_801511A8(u8 *a0) {
    u16 v = *(u16 *)(a0 + 0x3C);
    *(s16 *)(a0 + 0x3E) = 0;
    *(s16 *)(a0 + 0x40) = 0;
    *(s16 *)(a0 + 0x42) = 0;
    *(u16 *)(a0 + 0x3C) = v & 0xFFFE;
}
