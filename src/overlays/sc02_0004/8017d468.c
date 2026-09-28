/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017D468 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_80126950;
extern void func_80174E9C(s32 a0);
extern s32 D_801919B0;

void func_8017D468(void) {
    func_80174E9C((s32)&D_801919B0);
    D_80126950 = 0x1F4;
}
