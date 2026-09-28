/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801F2868 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_801F9F54;
extern s32 D_801F9DDC[];
extern s32 D_801F9DD8[];

void func_801F2868(s32 arg0, s32 arg1, s32 arg2) {

    extern s32 D_801F9F54;
    extern s32 D_801F9DDC[];
    extern s32 D_801F9DD8[];
    extern s32 D_801F9DE0[];
    s32 i;

    i = D_801F9F54;
    D_801F9DDC[i * 4] = arg0;
    D_801F9DD8[i * 4] = arg1;
    D_801F9DE0[i * 4] = arg2;
    D_801F9F54 = i + 1;
}
