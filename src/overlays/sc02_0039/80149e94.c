/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80149E94 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_8016F1AC(void);
extern u8 D_801202A0[];
extern s32 func_80149F2C(s32 a0, s32 a1);

s32 func_80149E94(s32 arg0) {
    u8 *p;
    if ((func_8016F1AC() == 0) && (*(u8 *)(arg0 + 0x1C5) != 0)) {
        *(u8 *)(arg0 + 0x1C5) = 0;
        for (p = D_801202A0; p < D_801202A0 + 0x6480; p += 0x10C) {
            if (func_80149F2C(arg0, (s32)p) != 0) {
                return 1;
            }
        }
    }
    return 0;
}
