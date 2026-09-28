/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80147814 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_80147814(s32 a0, s32 a1) {
    s32 v0 = *(s32*)(a0 + 0x34) + a1;
    *(s32*)(a0 + 0x34) = v0;
    if (a1 < 0) {
        if (v0 < (s32)0xFFE10000) {
            *(s32*)(a0 + 0x34) = (s32)0xFFE10000;
            return;
        }
    }
    if (a1 > 0) {
        if ((s32)0x1F0000 < *(s32*)(a0 + 0x34)) {
            *(s32*)(a0 + 0x34) = 0x1F0000;
        }
    }
}
