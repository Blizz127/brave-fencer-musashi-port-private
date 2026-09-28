/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CAED8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u8 D_800CBD2C[];

void func_800CAED8(u8 *a0) {
    func_80154274(a0, D_800CBD2C);
    func_800CBB70(a0);
    *(u8 *)(a0 + 0xBF) = 0;
    *(u8 *)(a0 + 0xBE) = 0;
    func_801655E4(a0);
    func_80146E90(a0, 0x12);
    *(u8 *)(a0 + 0x197) += 1;
}
