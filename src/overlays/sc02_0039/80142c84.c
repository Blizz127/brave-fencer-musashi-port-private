/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80142C84 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_80142C84(s32 a0) {
    *(s32 *)(a0 + 0x14) = 0xFFF40000;
    *(s32 *)(a0 + 0x48) = 0x20000;
    *(s16 *)(a0 + 0x102) = 0;
}
