/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80165770 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u8 D_80078EC1;
extern void func_800CAF6C(void);

void func_80165770(void) {
    if (D_80078EC1 == 0xC) {
        func_800CAF6C();
    }
}
