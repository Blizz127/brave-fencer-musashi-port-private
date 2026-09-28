/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CBB50 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_800CBB50(void *a0) {
    *(u8 *)((s32)a0 + 0x27) = 0x1A;
    *(s16 *)((s32)a0 + 0x2C) = 1;
    *(s16 *)((s32)a0 + 0x8) = 0;
    *(s16 *)((s32)a0 + 0xA) = -0x40;
}
