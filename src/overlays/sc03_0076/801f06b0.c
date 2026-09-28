/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801F06B0 - byte-exact against retail at -O2 (tools/register_match.py). */


s32 func_801F06B0(s32 a0, s16 a1, s16 a2, s16 a3, s32 *p) {
    extern u8 D_80115158[];
    s32 t0 = 0;
    *p = 0x808080;
    a2 = D_80115158[(s16)a2 * 2];
    if (a1 < 5) {
        if (a1 > 0) {
            if ((s16)a3 < a2) {
                t0 = *(s32 *)(a0 + a3 * 4);
            }
        } else if (a1 != 0) {
            if ((s16)a3 < a2) {
                t0 = *(s32 *)(a0 + a3 * 4);
            }
        }
    } else if (a1 != 5) {
        if ((s16)a3 < a2) {
            t0 = *(s32 *)(a0 + a3 * 4);
        }
    }
    return t0;
}
