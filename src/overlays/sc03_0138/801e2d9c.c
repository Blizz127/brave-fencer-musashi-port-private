/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801E2D9C - byte-exact against retail at -O2 (tools/register_match.py). */


void func_801E2D9C(void) {
    extern s32 D_801E2460;
    extern s32 D_801EC2C4;
    extern s32 D_801E256C;
    extern s32 D_801E3904[];
    extern s32 D_801E394C[];

    s32 var;

    var = D_801E2460;
    D_801EC2C4 = var;
    if (var == 1) {
        *(s32 *)(D_801E256C + 4) = (s32)D_801E3904;
    } else {
        *(s32 *)(D_801E256C + 4) = (s32)D_801E394C;
    }
}
