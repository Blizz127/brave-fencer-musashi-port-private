/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80148C4C - byte-exact against retail at -O2 (tools/register_match.py). */


s32 func_80148C4C(s32 a0, s32 a1) {
    *(s16 *)(*(s32 *)(a0 + 0x20) + 0x12) = (a1 + 0x200) & 0xFFF;
    return 1;
}
