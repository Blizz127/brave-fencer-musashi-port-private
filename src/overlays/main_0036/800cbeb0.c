/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CBEB0 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_800CBEB0(s32 a0) {
    s32 p;
    *(s32 *)(a0 + 0x4) += *(s32 *)(a0 + 0x10);
    *(s32 *)(a0 + 0x8) += *(s32 *)(a0 + 0x14);
    *(s32 *)(a0 + 0xC) += *(s32 *)(a0 + 0x18);
    p = *(s32 *)(a0 + 0x20);
    *(u16 *)(p + 0x10) += *(s32 *)(a0 + 0x4C);
    *(u16 *)(p + 0x12) += *(s32 *)(a0 + 0x50);
    *(u16 *)(p + 0x14) += *(s32 *)(a0 + 0x54);
}
