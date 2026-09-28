/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801F29E0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_8001ABBC(u32, u32, void *, u32, u32);

void func_801F29E0(void) {

    extern u8 D_800AF040[];
    func_8001ABBC(0, 0, D_800AF040, 0, 0);
}
