/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801EFBC0 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_801EFBC0(void) {

    extern u8 D_80078EBA;
    extern s32 D_801F6CA4;
    extern s32 D_801EF3EC;
    extern s32 D_801F0940[];
    extern s32 D_801F0900[];

    D_801F6CA4 = 0;
    if (D_80078EBA == 4) {
        *(s32 *)(D_801EF3EC + 4) = (s32)D_801F0940;
    } else {
        *(s32 *)(D_801EF3EC + 4) = (s32)D_801F0900;
    }
}
