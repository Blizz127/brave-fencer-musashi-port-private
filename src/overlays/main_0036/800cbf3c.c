/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CBF3C - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_800CC010;
extern u8 D_800CC011;
extern u8 D_800CC012;
extern u8 D_800CC013;

void func_800CBF3C(void) {
    u8 c;
    c = D_800CC013 - 2;
    D_800CC013 = c;
    if (c >= 0x81) {
        D_800CC013 = 0;
    }
    c = D_800CC013;
    (*(u8 *)&D_800CC010) = c;
    D_800CC011 = c;
    D_800CC012 = c;
}
