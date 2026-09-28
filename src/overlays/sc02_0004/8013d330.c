/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8013D330 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u8 D_80196352;
extern u8 D_801963C6;
extern u8 D_8019627A;
extern u8 D_80196334;
extern u8 D_80196258;
extern u8 D_80196279;
extern s32 D_80196338;

void func_8013D330(void) {
    if ((D_80196352 & 0xff) != D_801963C6) {
        D_80196352 = ((D_80196352 & 0xff) < D_801963C6) ? (D_80196352 + 1) : (D_80196352 - 1);
    }
    if ((D_8019627A & 0xff) != D_80196334) {
        D_8019627A = ((D_8019627A & 0xff) < D_80196334) ? (D_8019627A + 1) : (D_8019627A - 1);
    }
    if ((D_80196258 & 0xff) != D_80196279) {
        D_80196258 = ((D_80196258 & 0xff) < D_80196279) ? (D_80196258 + 1) : (D_80196258 - 1);
    }
    D_80196338 = 1;
}
