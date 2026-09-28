/* Overlay range [8017CEB8,8017CF3C) from MAIN.CD member 0012.
 * SHA256(span)=5db86f8dbba23722320af2967b4803f7f4c86e91f2e3ae7fa7c0361ba93361b8.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017CEB8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u8 D_80115158[];

s32 func_8017CEB8(s32 a0, s16 a1, s16 a2, s16 a3, s32* p)
{
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
