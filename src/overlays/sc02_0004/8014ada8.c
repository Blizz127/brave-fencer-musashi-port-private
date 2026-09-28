/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8014ADA8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_80078E8C;

void func_8014ADA8(s32 a0, s32 a1) {
    s32 v0;
    v0 = D_80078E8C + a1;
    D_80078E8C = v0;
    if (0x1869F < (u32)v0) {
        D_80078E8C = 0x1869F;
    }
}
