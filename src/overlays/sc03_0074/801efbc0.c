/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801EFBC0 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_801EFBC0(void) {

    extern u8 D_80078EB1;
    extern s32 D_801EF3EC;
    extern s32 D_801F5F04;
    extern s32 D_801F0234[];
    extern s32 D_801F0204[];

    D_801F5F04 = 0;
    if ((u32)D_80078EB1 >= 0x12) {
        *(s32 *)(D_801EF3EC + 4) = (s32)D_801F0234;
    } else {
        *(s32 *)(D_801EF3EC + 4) = (s32)D_801F0204;
    }
}
