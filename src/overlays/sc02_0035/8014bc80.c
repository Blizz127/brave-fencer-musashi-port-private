/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8014BC80 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s16 D_80078EB4;
extern u8 D_800B9A17;

void func_8014BC80(s32 a0, s32 a1) {
    s32 v;
    v = *(u16 *)&D_80078EB4;
    if (v < a1) {
        D_80078EB4 = 0;
        D_800B9A17 = 0;
    } else {
        D_80078EB4 = v - a1;
    }
}
