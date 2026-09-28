/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80149210 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_80149210(s32 a0, s32 a1) {
    *(s32 *)((s32)a0 + 0x1E4) = a1 | (a1 << 16);
    *(s16 *)((s32)a0 + 0x1E4) = a1;
    *(s16 *)((s32)a0 + 0x1E6) = a1;
}
