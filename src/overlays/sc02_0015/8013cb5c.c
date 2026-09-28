/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8013CB5C - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_8018F0FC;
extern s32 D_8018F100;
extern s32 D_8018F128;
extern s32 D_8018F12C;

void func_8013CB5C(void) {
    D_8018F100 = D_8018F128;
    D_8018F0FC = D_8018F12C;
}
