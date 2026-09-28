/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80144A04 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_80144A04(s32 *a0) {
    void (*fp)(void);
    fp = (void (*)(void))*(s32 *)((s32)a0 + 0xDC);
    fp();
}
