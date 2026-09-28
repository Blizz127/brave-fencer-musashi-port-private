/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801657A0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_801657D8(void);
extern u8 D_80078EC3;

void func_801657A0(void) {
    if (D_80078EC3 == 0) {
        D_80078EC3 = 1;
        func_801657D8();
    }
}
