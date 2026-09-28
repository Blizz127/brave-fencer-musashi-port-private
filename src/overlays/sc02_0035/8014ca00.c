/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8014CA00 - byte-exact against retail at -O2 (tools/register_match.py). */


s32 func_8014CA00(s32 a0) {
    s32 *p = *(s32 **)((s32)a0 + 0x78);
    return *(s16*)((s32)p + 0x2C);
}
