/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8013E410 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u8 D_801202A0[];

s32 func_8013E410(void) {
    s32 a0;
    s32 v1;
    v1 = (s32)D_801202A0;
    for (a0 = 0; a0 < 0x60; a0++, v1 += 0x10C) {
        if (*(u16 *)v1 == 0) {
            return v1;
        }
    }
    return 0;
}
