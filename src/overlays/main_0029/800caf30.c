/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CAF30 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_80078EC8;
extern s32 func_80165A20(s32 a0);

void func_800CAF30(s32 a0) {
    if (D_80078EC8 == 0) {
        func_80165A20(a0);
    }
}
