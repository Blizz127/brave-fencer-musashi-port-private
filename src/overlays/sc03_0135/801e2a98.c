/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801E2A98 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_801E2A98(void) {
    extern u32 D_801EAC3C;
    extern u8 D_801EAC4C[];
    extern s16 D_801EA954;
    extern s16 D_801EA950;
    extern s16 D_801EA95C;
    extern s16 D_80115118;
    extern s16 D_8011512C;
    extern s32 D_801E63B0;
    extern s32 D_801E6448;
    extern s16 D_80115126;
    extern s32 D_80115130[];
    extern s32 D_801E64F4[];
    extern s32 D_80115134;
    extern u8 D_80115138[];

    s16 i;

    D_801EAC3C = 0;
    for (i = 0; i < 8; i++) {
        D_801EAC4C[i] = 0xFF;
    }
    D_801EA950 = 0;
    D_801EA95C = 0;
    D_80115118 = 0;
    if (D_801EA954 == 0) {
        D_8011512C = 0;
        D_801E6448 = D_801E63B0;
    } else {
        D_8011512C = 9;
        D_801E6448 = 0x1A;
    }
    i = 0;
    D_80115130[0] = 0;
    D_80115134 = D_801E64F4[D_80115126];
    for (i = 0; i < 6; i++) {
        D_80115138[i] = *(u16 *)(D_80115134 + i * 32);
        ((s16 *)D_80115130)[20 + i] = *(u16 *)(D_80115134 + i * 32 + 2);
    }
}
