/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8015640C - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80029178(s32 arg);
extern s32 func_80029178(s32 a0);
extern s32 func_80029178(s32);
extern s32 func_801564B0(s32 a0);

s32 func_8015640C(s32 a0, s32 a1) {
    if ((func_801564B0(a0) & 0xFFFF) != 0) {
        if ((func_80029178(0x1C) & 0xFF) != 0) {
            return (((175 * (a1 & 0xFFFF)) / 100) & 0xFFFF) | 0x8000;
        } else {
            return (((150 * (a1 & 0xFFFF)) / 100) & 0xFFFF) | 0x8000;
        }
    }
    return a1 & 0xFFFF;
}
