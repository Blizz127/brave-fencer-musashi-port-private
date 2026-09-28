/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80147264 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s16 D_80126BB8;
extern s16 D_80126BBA;
extern s16 D_80126BBC;

void func_80147264(s32 a0) {
    D_80126BB8 = *(u16 *)(a0 + 0x0);
    D_80126BBA = *(u16 *)(a0 + 0x2);
    D_80126BBC = *(u16 *)(a0 + 0x4);
}
