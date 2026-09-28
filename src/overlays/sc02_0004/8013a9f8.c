/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8013A9F8 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_8013A9F8(s32 a0, s32 a1) {
    s32 orig = a1;
    a1 -= 2;
    a1 &= 0xFFFF;
    if ((u32)a1 < 5) {
        s32 b = orig & 0xFFFF;
        b -= 2;
        b <<= 10;
        *(s16*)(a0 + 0xE) = b;
    }
}
