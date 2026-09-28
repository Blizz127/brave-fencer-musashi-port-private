/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80165700 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u8 D_80181000[];

u8 func_80165700(s32 a0, s32 a1) {
    return D_80181000[a1 & 0x7F];
}
