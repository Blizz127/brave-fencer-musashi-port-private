/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8013D330 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u8 D_801A0D8A;
extern u8 D_801A0DFE;
extern u8 D_801A0CB2;
extern u8 D_801A0D6C;
extern u8 D_801A0C90;
extern u8 D_801A0CB1;
extern s32 D_801A0D70;

void func_8013D330(void) {
    if ((D_801A0D8A & 0xff) != D_801A0DFE) {
        D_801A0D8A = ((D_801A0D8A & 0xff) < D_801A0DFE) ? (D_801A0D8A + 1) : (D_801A0D8A - 1);
    }
    if ((D_801A0CB2 & 0xff) != D_801A0D6C) {
        D_801A0CB2 = ((D_801A0CB2 & 0xff) < D_801A0D6C) ? (D_801A0CB2 + 1) : (D_801A0CB2 - 1);
    }
    if ((D_801A0C90 & 0xff) != D_801A0CB1) {
        D_801A0C90 = ((D_801A0C90 & 0xff) < D_801A0CB1) ? (D_801A0C90 + 1) : (D_801A0C90 - 1);
    }
    D_801A0D70 = 1;
}
