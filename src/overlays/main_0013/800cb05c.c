/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB05C - byte-exact against retail at -O2 (tools/register_match.py). */


void func_800CB05C(s32 a0, s32 a1) {
    s32 v; s16 x; s16 y;
    a1 &= 0xFF;
    switch (a1) {
    case 1:
        v = *(s32 *)(a0 + 0xC0) + 0x800;
        *(s32 *)(a0 + 0xC0) = v;
        if (v >= 0x2001) { *(s32 *)(a0 + 0xC0) = 0x2000; }
        x = *(u16 *)(a0 + 0x1B8) + 0x800;
        y = *(u16 *)(a0 + 0x1BA) + 0x800;
        *(u16 *)(a0 + 0x1B8) = x;
        *(u16 *)(a0 + 0x1BA) = y;
        break;
    case 2:
        v = *(s32 *)(a0 + 0xC0) - 0x800;
        *(s32 *)(a0 + 0xC0) = v;
        if (v < 0) { *(s32 *)(a0 + 0xC0) = 0; }
        x = *(u16 *)(a0 + 0x1B8) - 0x800;
        y = *(u16 *)(a0 + 0x1BA) - 0x800;
        *(u16 *)(a0 + 0x1B8) = x;
        *(u16 *)(a0 + 0x1BA) = y;
        break;
    }
}
