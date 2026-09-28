/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8016ED8C - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_80126D70;
extern void func_8016EDEC(s32 a0, s32 a1, s32 a2);

void func_8016ED8C(s32 a0, s32 a1, s32 a2) {
    func_8016EDEC(a0, a1, a2);
    D_80126D70 = a2;
}
