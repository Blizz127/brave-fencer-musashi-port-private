/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801473EC - byte-exact against retail at -O2 (tools/register_match.py). */


void func_801473EC(s32 *a0) {
    s32 *a2;
    a2 = a0;
    a2[1] += a2[4];
    a2[2] += a2[5];
    a2[3] += a2[6];
    if (a2[4] != 0 || a2[5] != 0 || a2[6] != 0) {
        a2[0x11] |= 0x80000000;
    }
}
