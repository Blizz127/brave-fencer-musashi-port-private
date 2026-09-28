/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CCDB0 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_800CCDB0(s32 *a0) {
    *(s32 *)((s32)a0 + 0x23C) = 0;
    *(s32 *)((s32)a0 + 0x238) = 0;
    *(s32 *)((s32)a0 + 0x234) = 0;
    *(s16 *)((s32)a0 + 2) = 1;
}
