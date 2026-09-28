/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8015987C - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_800167B8(s32 a0);

s32 func_8015987C(s32 a0) {
    func_800167B8(4);
    *(u8 *)(a0 + 0x15) = *(u8 *)(a0 + 0x15) + 1;
    return 0;
}
