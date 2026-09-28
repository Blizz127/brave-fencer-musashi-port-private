/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CAEC0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u8 D_800CC01C[];
extern void func_80154274(void *a0, void *a1);
extern void func_801655E4(void *a0);

void func_800CAEC0(u8 *a0) {
    func_80154274(a0, D_800CC01C);
    func_801655E4(a0);
    *(u8 *)(a0 + 0x197) = *(u8 *)(a0 + 0x197) + 1;
}
