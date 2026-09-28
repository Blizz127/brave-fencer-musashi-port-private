/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8014BD24 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s16 D_80078EB8;
extern u16 D_80078EB6;

void func_8014BD24(s32 a0, s32 a1) {
    u16 v;
    v = *(u16 *)&D_80078EB8 + a1;
    D_80078EB8 = v;
    if (D_80078EB6 < v) {
        D_80078EB8 = D_80078EB6;
    }
}
