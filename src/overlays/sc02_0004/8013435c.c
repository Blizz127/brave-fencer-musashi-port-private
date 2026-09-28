/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8013435C - byte-exact against retail at -O2 (tools/register_match.py). */


s32 func_8013435C(s16 *a0, s16 *a1, s32 a2, s16 *a3) {
    s32 t1;
    s32 sum;
    if (a3[1] < -0xE00) {
        t1 = -0x1800;
    } else {
        t1 = -0x2F00;
    }
    sum = a0[0] * a1[0] + a0[1] * a1[1];
    sum = sum + a0[2] * a1[2];
    sum = sum + a2;
    return sum < t1;
}
