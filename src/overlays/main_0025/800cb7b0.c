/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB7B0 - byte-exact against retail at -O2 (tools/register_match.py). */


s32 func_800CB7B0(s32 arg0) {
    s32 x;
    s32 t;
    s32 u;

    func_80015978(arg0 + 4, &x);
    if ((func_8012EFB8(&x, &x) & 0xFFFFEFFF) == 0) {
        t = *(s16 *) &x;
        if (t < 0) {
            t = -t;
        }
        if (t < 201) {
            u = *((s16 *) &x + 1);
            if (u >= 0) {
                if (u >= 161) {
                    goto epilogue;
                }
                return 0;
            } else {
                if (-u < 161) {
                    return 0;
                }
                goto epilogue;
            }
        } else {
            goto epilogue;
        }
    } else {
        goto epilogue;
    }
epilogue:
    return 1;
}
