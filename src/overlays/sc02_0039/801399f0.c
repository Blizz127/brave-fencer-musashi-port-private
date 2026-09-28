/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801399F0 - byte-exact against retail at -O2 (tools/register_match.py). */


s32 func_801399F0(s32 a0) {
    s32 v1;
    if (*(s32*)(a0 + 0x0) == 0) return -1;
    v1 = *(s16*)(a0 + 0x4);
    if (v1 == 0) return -1;
    if (v1 == 0xE) return -1;
    if (v1 == 0xD) return *(s8*)(a0 + 0x1F);
    return 0;
}
