/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80171A34 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_80171A34(s32 *a0, s8 a1) {
    *(s8*)((s32)a0 + 0x214) = a1;
    *(s8*)((s32)a0 + 0x215) = 0;
    *(s8*)((s32)a0 + 0x216) = 0;
}
