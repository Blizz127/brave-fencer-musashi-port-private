/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80154AB4 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_80154AB4(s32 a0, s32 a1) {
    s32 *base = *(s32 **)(a0 + 0xCC);
    s32 v1 = base[a1];
    *(s16 *)(a0 + 0xD6) = 1;
    *(s16 *)(a0 + 0xD4) = 1;
    *(s8 *)(a0 + 0xD8) = 0;
    *(s8 *)(a0 + 0xD9) = 0;
    *(s32 *)(a0 + 0xD0) = v1;
}
