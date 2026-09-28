/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80174ED4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u16 D_80126980;

s32 func_80174ED4(void) {
    return (s16)(D_80126980 & 0x8000);
}
