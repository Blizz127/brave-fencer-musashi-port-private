/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8016004C - byte-exact against retail at -O2 (tools/register_match.py). */
extern u8 D_800B9A17;

void func_8016004C(s32 a0) {
    *(s32 *)((s32)a0 + 0x184) = 0;
    *(s16 *)((s32)a0 + 0x18A) = 0;
    *(s16 *)((s32)a0 + 0x188) = 0;
    *(s32 *)((s32)a0 + 0x44) &= ~0x10;
    D_800B9A17 = 1;
}
