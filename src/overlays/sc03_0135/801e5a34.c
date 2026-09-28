/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801E5A34 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_801E5A34(s32 a0, s32 a1, s32 a2) {
    extern s32 D_801EADF0;
    extern s32 D_801EAC74[][4];
    extern s32 D_801EAC78[][4];
    extern s32 D_801EAC7C[][4];
    s32 n = D_801EADF0;
    D_801EAC78[n][0] = a0;
    D_801EAC74[n][0] = a1;
    D_801EAC7C[n][0] = a2;
    D_801EADF0 = n + 1;
}
