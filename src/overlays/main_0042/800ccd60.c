/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CCD60 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_800CCD60(s32 arg0) {
    *(s16 *)(arg0 + 0xF6) = (*(s32 *)(arg0 + 0x23C) << 10) / 7 + 0x1000;
}
