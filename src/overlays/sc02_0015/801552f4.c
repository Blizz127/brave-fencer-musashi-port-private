/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801552F4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_800DE2A4[];

void func_801552F4(s32 a0) {
    s32 *p = D_800DE2A4;
    s32 v0 = *p;
    if (v0 != 0) {
        do {
            v0 &= 0x80FFFFFF;
            *p = v0;
            p += 1;
            v0 = *p;
        } while (v0 != 0);
    }
    *(s32 *)(a0 + 0x44) = *(s32 *)(a0 + 0x44) | 0x30000000;
}
