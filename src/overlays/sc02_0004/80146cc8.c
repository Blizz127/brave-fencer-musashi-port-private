/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80146CC8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_80127098;
extern s32 D_80127094;
extern s32 D_80127090;

void func_80146CC8(s32 a0) {
    s32 *p = &D_80127090;
    *(s32*)(a0 + 0x10) += *p;
    *(s32*)(a0 + 0x14) += D_80127094;
    *(s32*)(a0 + 0x18) += D_80127098;
    *p = 0;
    D_80127094 = 0;
    D_80127098 = 0;
}
