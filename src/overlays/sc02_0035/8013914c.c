/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8013914C - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80139220(s32 a0);

s32 func_8013914C(s32 a0, s32 a1) {
    s32 t;
    if ((s32)*(u16 *)(a0 + 0x14) >= *(s16 *)(a0 + 0x2C)) {
        if (func_80139220(a0) != 0) {
            return 1;
        }
    }
    t = *(u16 *)(a0 + 0x14);
    *(s16 *)(a1 + 0x0) = *(u16 *)(a0 + 0x38) + (((u32)(t * 3)) >> 1);
    t = *(u16 *)(a0 + 0x12);
    *(s16 *)(a1 + 0x2) = *(u16 *)(a0 + 0x3A) + ((t * 3) << 2);
    *(s16 *)(a0 + 0x14) = *(u16 *)(a0 + 0x14) + 1;
    return 0;
}
