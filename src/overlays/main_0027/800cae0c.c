/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CAE0C - byte-exact against retail at -O2 (tools/register_match.py). */


void func_800CAE0C(void) {
    extern void func_800183E0(s32 a0);
    extern s32 D_800CC22C;
    extern s32 D_800CC1EC;
    ((void (*)(void *))func_800183E0)(&D_800CC22C);
    ((void (*)(s32))func_800183E0)((s32)&D_800CC1EC);
}
