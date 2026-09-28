/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80149034 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_80149034(s32 *a0) {
    *(u16*)((s32)a0 + 0x3C) |= 0x4000;
}
