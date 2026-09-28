/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8016F330 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_80126D50;

void func_8016F330(void) {
    D_80126D50 = D_80126D50 | 0x10000000;
}
