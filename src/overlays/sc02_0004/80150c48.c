/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80150C48 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_800AE6B0;
s32 func_80150480(s32 _arg0);
extern s32 func_80150480(s32 a0);
extern u16 D_800AE6DC;

void func_80150C48(s32 a0) {
    if (func_80150480(a0) != 0) {
        s32 p = *(s32 *)(a0 + 0x1A4);
        D_800AE6B0 = *(s32 *)(p + 0xDC);
        p = *(s32 *)(a0 + 0x1A4);
        D_800AE6DC = *(u16 *)(p + 0xFC);
    }
}
