/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017E25C - byte-exact against retail at -O2 (tools/register_match.py). */


void func_8017E25C(s32 a0)
{
    s16 t;
    s32 v1;
    s32 v0;

    t = *(s16 *)(a0 + 0xDE);
    if (t < -2) {
        *(s32 *)(a0 + 0xE0) += 0x20000;
    } else if (t >= 3) {
        *(s32 *)(a0 + 0xE0) -= 0x20000;
    }

    v1 = *(s32 *)(a0 + 0xE0);
    if (v1 < 0) {
        v0 = v1 + 0x8000;
        *(s32 *)(a0 + 0xE0) = v0;
        if (v0 > 0) {
            *(s32 *)(a0 + 0xE0) = 0;
        }
    } else if (v1 > 0) {
        v0 = v1 - 0x8000;
        *(s32 *)(a0 + 0xE0) = v0;
        if (v0 < 0) {
            *(s32 *)(a0 + 0xE0) = 0;
        }
    }

    *(s32 *)(a0 + 0xDC) += *(s32 *)(a0 + 0xE0);
    *(s16 *)(*(s32 *)(a0 + 0x20) + 0x14) = *(u16 *)(a0 + 0xDE);
}
