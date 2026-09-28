/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801E2D58 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_801E2D58(void) {
    extern u8 D_80078EBA;
    extern s32 D_801E256C;
    extern s32 D_801E9E34;
    extern s32 D_801E39F4[];
    extern s32 D_801E39B4[];

    D_801E9E34 = 0;
    if (D_80078EBA == 4) {
        *(s32 *)(D_801E256C + 4) = (s32)D_801E39F4;
    } else {
        *(s32 *)(D_801E256C + 4) = (s32)D_801E39B4;
    }
}
