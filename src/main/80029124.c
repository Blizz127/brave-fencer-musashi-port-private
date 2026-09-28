#include "psx_types.h"


/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80029124 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

extern u8 D_800AE648[];

void func_80029124(s32 arg0, s32 arg1) {
    s32 idx = (u32)arg0 >> 3;
    s32 mask = 1 << (arg0 & 7);

    if ((arg1 & 0xFF) != 0)
        D_800AE648[idx] |= mask;
    else
        D_800AE648[idx] &= ~mask;
}
