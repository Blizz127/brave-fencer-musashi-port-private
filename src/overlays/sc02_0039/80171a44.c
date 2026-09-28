/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80171A44 - byte-exact against retail at -O2 (tools/register_match.py). */


s32 func_80171A44(u8 *a0)
{
    s32 v = a0[0x215] + 1;
    a0[0x216] = 0;
    a0[0x215] = v;
    return v;
}
