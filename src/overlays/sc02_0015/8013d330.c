/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8013D330 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u8 D_8019062A;
extern u8 D_8019069E;
extern u8 D_80190552;
extern u8 D_8019060C;
extern u8 D_80190530;
extern u8 D_80190551;
extern s32 D_80190610;

void func_8013D330(void) {
    if ((D_8019062A & 0xff) != D_8019069E) {
        D_8019062A = ((D_8019062A & 0xff) < D_8019069E) ? (D_8019062A + 1) : (D_8019062A - 1);
    }
    if ((D_80190552 & 0xff) != D_8019060C) {
        D_80190552 = ((D_80190552 & 0xff) < D_8019060C) ? (D_80190552 + 1) : (D_80190552 - 1);
    }
    if ((D_80190530 & 0xff) != D_80190551) {
        D_80190530 = ((D_80190530 & 0xff) < D_80190551) ? (D_80190530 + 1) : (D_80190530 - 1);
    }
    D_80190610 = 1;
}
