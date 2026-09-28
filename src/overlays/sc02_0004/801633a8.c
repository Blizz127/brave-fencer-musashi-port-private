/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801633A8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_80115100;
extern s32 D_80115200;

s32 func_801633A8(void) {
    s32 *p = &D_80115100;
    s32 *q = &D_80115200;
    s32 i;
    for (i = 0; i < 3; i++) {
        s32 v1 = q[i];
        if (v1 != 0) {
            if ((*(u16*)(p[i] + 0x5C) & 0x400) == 0) {
                return v1;
            }
        }
    }
    return 0;
}
