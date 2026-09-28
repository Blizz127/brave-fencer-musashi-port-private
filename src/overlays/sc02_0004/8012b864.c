/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8012B864 - byte-exact against retail at -O2 (tools/register_match.py). */
#define ratan2 func_8004CFEC
extern s32 ratan2(s32 a0, s32 a1);
extern s32 ratan2(s32 x, s32 y);
extern s16 D_80126CB8;
extern s16 D_80126CB4;

s32 func_8012B864(s32 a0) {
    s32 dx = *(s16*)(a0 + 0xE) - D_80126CB8;
    s32 dy = D_80126CB4 - *(s16*)(a0 + 0x6);
    return (ratan2(dx, dy) - 0x400) & 0xFFF;
}
