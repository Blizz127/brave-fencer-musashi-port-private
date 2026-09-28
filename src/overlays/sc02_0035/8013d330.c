/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8013D330 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u8 D_801BE9D2;
extern u8 D_801BEA46;
extern u8 D_801BE8FA;
extern u8 D_801BE9B4;
extern u8 D_801BE8D8;
extern u8 D_801BE8F9;
extern s32 D_801BE9B8;

void func_8013D330(void) {
    if ((D_801BE9D2 & 0xff) != D_801BEA46) {
        D_801BE9D2 = ((D_801BE9D2 & 0xff) < D_801BEA46) ? (D_801BE9D2 + 1) : (D_801BE9D2 - 1);
    }
    if ((D_801BE8FA & 0xff) != D_801BE9B4) {
        D_801BE8FA = ((D_801BE8FA & 0xff) < D_801BE9B4) ? (D_801BE8FA + 1) : (D_801BE8FA - 1);
    }
    if ((D_801BE8D8 & 0xff) != D_801BE8F9) {
        D_801BE8D8 = ((D_801BE8D8 & 0xff) < D_801BE8F9) ? (D_801BE8D8 + 1) : (D_801BE8D8 - 1);
    }
    D_801BE9B8 = 1;
}
