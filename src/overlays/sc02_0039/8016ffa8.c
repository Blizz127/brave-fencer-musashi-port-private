/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8016FFA8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80171990(u8 *a0);

void func_8016FFA8(u8 *a0) {
    *(u16 *)(a0 + 0xAC) |= 0x40;
    *(u16 *)(a0 + 0xAA) |= 0x40;
    func_80171990(a0);
}
