/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8013BCDC - byte-exact against retail at -O0 (tools/register_match.py). */


void func_8013BCDC(void) {

    extern s32 D_80184C24;
    s32 pad[4];
    if (D_80184C24 != 0) {
        ((void (*)(void))D_80184C24)();
    }
}
