/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8012E4C8 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_8012E4C8(s32 a0) {
    s32 v1;
    s32 t;
    v1 = *(s32 *)(a0 + 0x20);
    *(s16 *)(v1 + 0x1C) = 0x1000;
    *(s16 *)(v1 + 0x18) = 0x1000;
    *(s16 *)(a0 + 0x60) = 0;
    *(u16 *)(a0 + 0x5C) = *(u16 *)(a0 + 0x5C) | 1;
    t = *(u16 *)(*(s32 *)(a0 + 0x20) + 0x12);
    *(s16 *)(a0 + 0x5E) = 1;
    *(s16 *)(a0 + 0x62) = t + 0x800;
}
