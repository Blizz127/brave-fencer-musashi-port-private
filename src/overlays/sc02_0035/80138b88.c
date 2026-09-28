/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80138B88 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_80138B88(s32 a0) {
    s32 a1;
    if (*(s32*)(a0 + 0x8) & 0x2000) {
        *(s16*)(a0 + 0x4) = 0xD;
    } else {
        *(s16*)(a0 + 0x4) = 0xC;
        *(s32*)(a0 + 0x8) &= ~0x1000;
        a1 = *(s32*)(a0 + 0x40);
        if (a1 != 0) {
            if (*(u16*)(a0 + 0x18) != 0) {
                *(s16*)a1 = 3;
            }
        }
    }
}
