/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801E2D58 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_801E2D58(void) {
    extern u8 D_80078EB1;
    extern s32 D_801E256C;
    extern s32 D_801E906C;
    extern s32 D_801E3290[];
    extern s32 D_801E32C0[];

    D_801E906C = 0;
    if (D_80078EB1 >= 0x12) {
        *(s32 *)(D_801E256C + 4) = (s32)D_801E32C0;
    } else {
        *(s32 *)(D_801E256C + 4) = (s32)D_801E3290;
    }
}
