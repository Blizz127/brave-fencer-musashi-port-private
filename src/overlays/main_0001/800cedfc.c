/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CEDFC - byte-exact against retail at -O2 (tools/register_match.py). */


void func_800CEDFC(void) {

    extern u16 D_800B99E4;
    extern void (*D_800CF450[])(void);
    u32 v1;
    v1 = D_800B99E4;
    if (v1 < 8) {
        D_800CF450[v1]();
    }
}
