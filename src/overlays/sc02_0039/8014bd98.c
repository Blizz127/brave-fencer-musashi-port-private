/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8014BD98 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s16 D_80078EB8;
extern u16 D_80078EB6;

void func_8014BD98(s32 a0, u16 a1) {
    D_80078EB8 = a1;
    if (D_80078EB6 < a1) {
        D_80078EB8 = D_80078EB6;
    }
}
