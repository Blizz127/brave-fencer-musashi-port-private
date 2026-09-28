/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CCFA8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s16 D_801152B0;
extern s16 D_801152B4;

void func_800CCFA8(s32 *a0) {
    s32 t = D_801152B0 << 6;
    *(s32 *)((s32)a0 + 0x238) = 0x80000;
    *(s32 *)((s32)a0 + 0x234) = t;
    *(s32 *)((s32)a0 + 0x23C) = D_801152B4 << 6;
    *(s16 *)((s32)a0 + 2) = 3;
}
