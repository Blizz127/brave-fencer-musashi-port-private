/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80162AC0 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_80162AC0(s32 *a0, s8 a1) {
    *(s8*)((s32)a0 + 0x0) = a1;
    *(s8*)((s32)a0 + 0x1) = 0;
}
