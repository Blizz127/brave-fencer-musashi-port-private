/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80164E40 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u8 D_801951C0;
extern u8 D_801951C1;
extern u8 D_801951C2;

s32 func_80164E40(void) {
    u8 *p = &D_801951C0;
    if (*p != 0) {
        *p -= 0x10;
    }
    if (D_801951C1 != 0) {
        D_801951C1 -= 0x10;
    }
    if (D_801951C2 != 0) {
        D_801951C2 -= 0x10;
    }
    return *(s32 *)p == 0;
}
