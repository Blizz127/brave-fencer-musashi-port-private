/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CAF20 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_80078EC8;
extern void func_80165A20(void);

void func_800CAF20(void) {
    if (D_80078EC8 == 0) {
        func_80165A20();
    }
}
