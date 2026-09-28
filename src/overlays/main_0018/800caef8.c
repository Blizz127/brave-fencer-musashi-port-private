/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CAEF8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_800CAF30();

void func_800CAEF8(void *a0) {
    func_800CAF30(a0);
    *(u8 *)((s32)a0 + 0x197) += 1;
}
