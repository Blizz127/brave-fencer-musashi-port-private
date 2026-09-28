/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801EFE7C - byte-exact against retail at -O2 (tools/register_match.py). */


void func_801EFE7C(void) {
    extern s16 D_801EF318;
    extern s32 D_801EF3EC;
    extern u8 D_801F0340[];
    extern u8 D_801F0378[];
    extern u8 D_801F03AC[];

    switch (D_801EF318) {
    case 0:
        *(s32 *)(*(s32 *)&D_801EF3EC + 4) = (s32)D_801F0340;
        break;
    case 1:
        *(s32 *)(*(s32 *)&D_801EF3EC + 4) = (s32)D_801F0378;
        break;
    case 2:
        *(s32 *)(*(s32 *)&D_801EF3EC + 4) = (s32)D_801F03AC;
        break;
    }
}
