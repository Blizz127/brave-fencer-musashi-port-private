/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801EF918 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_801EF918(void) {

    extern s16 D_801F9AB4;
    extern s16 D_801F9AB8;
    extern s16 D_801F9AC0;
    extern s32 D_801F9DA0;
    extern u8 D_801F9DB0[];
    extern s16 D_80115118;
    extern s16 D_8011512C;
    extern s16 D_80115126;
    extern s32 D_801F3248;
    extern s32 D_801F32E0;
    extern s32 D_801F338C[];
    extern s32 D_80115130[];
    extern s32 D_80115134;
    extern u8 D_80115138[];

    s16 i;

    D_801F9DA0 = 0;
    for (i = 0; i < 8; i++) {
        D_801F9DB0[i] = 0xFF;
    }
    D_801F9AB4 = 0;
    D_801F9AC0 = 0;
    D_80115118 = 0;
    if (D_801F9AB8 == 0) {
        D_8011512C = 0;
        D_801F32E0 = D_801F3248;
    } else {
        D_8011512C = 9;
        D_801F32E0 = 26;
    }
    D_80115130[0] = 0;
    D_80115134 = D_801F338C[D_80115126];
    for (i = 0; i < 6; i++) {
        D_80115138[i] = *(u16 *) (D_80115134 + i * 32);
        ((s16 *) D_80115130)[i + 20] = *(u16 *) (D_80115134 + i * 32 + 2);
    }
}
