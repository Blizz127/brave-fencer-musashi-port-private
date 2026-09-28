/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80134FB8 - byte-exact against retail at -O2 (tools/register_match.py). */


s32 func_80134FB8(s32 a0, s32 a1, s32 a2) {
    return *(s16*)(a0 + 0x0) * *(s16*)(a1 + 0x0)
         + *(s16*)(a0 + 0x2) * *(s16*)(a1 + 0x2)
         + *(s16*)(a0 + 0x4) * *(s16*)(a1 + 0x4)
         + a2;
}
