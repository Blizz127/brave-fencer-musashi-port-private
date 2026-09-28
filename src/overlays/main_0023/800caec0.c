/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CAEC0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_801655E4(s32 a0);

void func_800CAEC0(u8 *a0) {
    u8 *s0;

    func_801655E4((s32)a0);
    s0 = a0;
    s0[0x197]++;
}
