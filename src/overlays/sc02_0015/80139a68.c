/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80139A68 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s16 D_80127540[4];

void func_80139A68(s32 a0, u16 a1) {
    if (a1 < 4) {
        D_80127540[a1] = (s16)a0;
    }
}
