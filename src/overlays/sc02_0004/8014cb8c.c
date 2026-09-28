/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8014CB8C - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_80126B9C;

s32 func_8014CB8C(void) {
    return D_80126B9C & 0x1000;
}
