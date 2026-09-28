/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8014B5C4 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_8014B5C4(s32 *a0, s32 a1, s32 a2) {
    *(s8*)((s32)a0 + 0x1C7) = a1 | a2;
}
