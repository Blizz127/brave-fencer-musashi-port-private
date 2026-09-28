/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80148C20 - byte-exact against retail at -O2 (tools/register_match.py). */


s32 func_80148C20(s32 a0, s16 a1) {
    s32 *p = *(s32 **)((s32)a0 + 0x20);
    *(s16*)((s32)p + 0x12) = a1;
    return 1;
}
