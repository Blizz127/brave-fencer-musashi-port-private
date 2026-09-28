/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80130AC4 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_80130AC4(s32 a0) {
    s16 v0;
    v0 = *(u16*)(a0 + 0xAC) - 1;
    *(u16*)(a0 + 0xAC) = v0;
    if (v0 == 0) {
        *(u8*)(a0 + 0xC1) = 0;
        *(s16*)(a0 + 0x5E) = 0;
    }
}
