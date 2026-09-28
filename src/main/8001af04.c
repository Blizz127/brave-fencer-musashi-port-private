/* Exact retail word export [8001AF04,8001AF34); verified against pinned EXE and asm. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8001AF04 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

extern s32 D_800BA1B4;

s32 func_8001AF04(void) {
    s32 value = D_800BA1B4;
    if (value == 0) {
        return 0;
    }
    if (value == 3) {
        return 1;
    }
    return 2;
}
