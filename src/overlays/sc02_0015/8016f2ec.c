/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8016F2EC - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_80126D50;

void func_8016F2EC(void) {
    D_80126D50 = D_80126D50 | 0x8000000;
}
