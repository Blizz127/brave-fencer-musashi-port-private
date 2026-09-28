/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CAE0C - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_800183E0(s32 *a0);
extern s32 D_800CB95C;
extern s32 *D_800CB5D4[];

s32 func_800CAE0C(void) {
    s32 idx = D_800CB95C;
    s32 *p = D_800CB5D4[idx];

    D_800CB95C = idx + 1;
    if (p == ((void *)0) ) {
        p = D_800CB5D4[0];
        D_800CB95C = 1;
    }
    return func_800183E0(p);
}
