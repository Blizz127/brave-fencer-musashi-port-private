/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CAF38 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_800CAF38(void *a0) {

    extern s32 D_80078EC8;
    extern s32 D_80078EA4;
    extern void func_80165840(void);
    extern s32 func_80165A20(s32);

    if (D_80078EC8 == 0) {
        func_80165840();
        func_80165A20((s32)a0);
    } else {
        D_80078EA4 = 0xA00000;
    }
}
