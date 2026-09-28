/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80138DB8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80014E80(s32 a0, s32 a1);

s16 func_80138DB8(s32 a0, u8 a1, s32 a2) {
    return (s16)func_80014E80(a1, a2);
}
