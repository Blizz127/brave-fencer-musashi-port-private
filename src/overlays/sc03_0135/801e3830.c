/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801E3830 - byte-exact against retail at -O2 (tools/register_match.py). */


s32 func_801E3830(s32 arg0, s16 arg1, s16 arg2, s16 arg3, s32 *arg4) {
    extern u8 D_80115158[];
    s32 t0 = 0;
    *arg4 = 0x808080;
    arg2 = D_80115158[(s16)arg2 * 2];
    if (arg1 < 5) {
        if (arg1 > 0) {
            if ((s16)arg3 < arg2) {
                t0 = *(s32 *)(arg0 + arg3 * 4);
            }
        } else if (arg1 != 0) {
            if ((s16)arg3 < arg2) {
                t0 = *(s32 *)(arg0 + arg3 * 4);
            }
        }
    } else if (arg1 != 5) {
        if ((s16)arg3 < arg2) {
            t0 = *(s32 *)(arg0 + arg3 * 4);
        }
    }
    return t0;
}
