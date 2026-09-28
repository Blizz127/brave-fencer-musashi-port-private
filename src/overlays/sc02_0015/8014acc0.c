/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8014ACC0 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_8014ACC0(s32 a0, s32 a1) {
    s16 v0;
    v0 = *(u16 *)((s32)a0 + 0x1C8) - a1;
    *(s16 *)((s32)a0 + 0x1C8) = v0;
    if (v0 < 0) {
        *(s16 *)((s32)a0 + 0x1C8) = 0;
    }
}
