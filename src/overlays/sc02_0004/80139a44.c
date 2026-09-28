/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80139A44 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_80127530[4];

void func_80139A44(s32 a0, u16 a1) {
    if (a1 < 4) {
        D_80127530[a1] = a0;
    }
}
