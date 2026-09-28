/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017D53C - byte-exact against retail at -O2 (tools/register_match.py). */


void func_8017D53C(s32 param_1) {
    extern u16 D_80126940;
    extern s16 D_80126942;
    extern s16 D_80126944;
    extern void func_8017D5C8(s32, s16 *);
    s16 buf[3];
    buf[0] = D_80126940;
    if (D_80126942 < -0x570) {
        buf[1] = -0x570;
    } else if (!(D_80126942 < -0x3bf)) {
        buf[1] = -0x3c0;
    } else {
        buf[1] = D_80126942;
    }
    if (D_80126944 < -0x60) {
        buf[2] = -0x60;
    } else {
        buf[2] = D_80126944;
    }
    func_8017D5C8(param_1, buf);
}
