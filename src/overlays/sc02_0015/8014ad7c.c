/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8014AD7C - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_80126B58;
extern void func_8014ADA8(s32 a0, s32 a1);

void func_8014AD7C(s32 a0) {
    func_8014ADA8((s32)&D_80126B58, a0);
}
