/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CAE14 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_800183E0(s32 *a0);

void func_800CAE14(void) {

    extern s32 D_800CBF60;
    extern s32 D_800CBF20;
    func_800183E0(&D_800CBF60);
    func_800183E0(&D_800CBF20);
}
