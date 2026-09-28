/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CC0A0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s16 D_800CC9E8;
extern s16 D_800CC9EA;
extern s16 D_800CC9F0;
extern s16 D_800CC9F2;

s32 func_800CC0A0(void *prim)
{
    s32 val;

    val = *(u8 *)((s32)prim + 0xA);
    if (D_800CC9E8 < val && val < D_800CC9EA) {
        goto ret1;
    }
    if (D_800CC9F0 < val && val < D_800CC9F2) {
        goto ret1;
    }
    return 0;
ret1:
    return 1;
}
