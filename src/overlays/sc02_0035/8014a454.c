/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8014A454 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80012A60(s32 a0, s32 a1);

s32 func_8014A454(s32 a0) {
    s32 v0;
    if (*(u16 *)(a0 + 0x3C) & 0x4000) {
        v0 = (s16)func_80012A60(*(s16 *)(a0 + 0x42),
                                (*(u16 *)(*(s32 *)(a0 + 0x20) + 0x12) + 0x800) & 0xFFF);
        if (v0 < 0x2AA) {
            return 1;
        }
    }
    return 0;
}
