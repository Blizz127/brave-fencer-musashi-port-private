/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80161278 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_801612B8(void *a0, s32 a1);
extern s32 D_801152BC;
extern int func_80161374(int param_1, unsigned int param_2);

void func_80161278(void *a0) {
    s32 r;
    D_801152BC = 0;
    r = func_801612B8(a0, 1);
    func_80161374(a0, r);
}
