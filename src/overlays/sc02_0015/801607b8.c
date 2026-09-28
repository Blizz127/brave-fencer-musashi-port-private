/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801607B8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80149048(s32 *a0);

void func_801607B8(s32 *a0) {
    a0[0x11] &= ~1;
    func_80149048(a0);
}
