/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80171904 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_80126D50;

void func_80171904(s32 a0) {
    D_80126D50 = a0 | (D_80126D50 & 0x7F000000);
}
