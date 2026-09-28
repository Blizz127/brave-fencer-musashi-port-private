/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CAE0C - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_800183E0(s32 *a0);

void func_800CAE0C(void) {

    extern s32 D_800CAF34;
    func_800183E0(&D_800CAF34);
}
