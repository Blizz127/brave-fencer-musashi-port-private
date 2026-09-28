/* Exact retail word export for [800381E4,80038210); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800381E4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

extern u8 D_800B9CF0[];

s32 func_800381E4(s32 a0, s32 a1) {
    s32 v0;

    a1 = (a1 << 16) >> 13;
    v0 = (a0 << 7) - a0;
    v0 = v0 << 2;
    a1 = a1 + v0;
    return D_800B9CF0[a1];
}
