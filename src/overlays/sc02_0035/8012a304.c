/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8012A304 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s8 D_801152C0;
extern s16 D_80127080;
extern s16 D_801152C2;

void func_8012A304(s32 a0, s32 a1) {
    D_801152C0 = 1;
    D_80127080 = a0;
    D_801152C2 = a1;
}
