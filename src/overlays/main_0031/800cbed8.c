/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CBED8 - byte-exact against retail at -O2 (tools/register_match.py). */


s32 func_800CBED8(s32 *arg0) {
    s16 *p;
    s32 ret;
    p = (s16 *) arg0;
    ret = 0;
    if (p[3] < -0x60) {
        p[3] = -0x60;
        ret = 1;
    } else if (p[3] > 0x60) {
        p[3] = 0x60;
        ret = 1;
    }
    if (p[5] < -0x40) {
        p[5] = -0x40;
        ret++;
    } else if (p[5] > 0x40) {
        p[5] = 0x40;
        ret++;
    }
    return ret;
}
