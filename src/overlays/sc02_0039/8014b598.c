/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8014B598 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u8 D_80126D1C;
extern s32 D_80126D74;

void func_8014B598(s32 a0, s32 a1) {
    D_80126D1C = a0;
    D_80126D74 = a1;
}
