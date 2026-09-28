/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8012A8B0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_8012AAAC();

void func_8012A8B0(u8 *a0, s32 a1) {
    u16 v0 = *(u16 *)(a0 + 0x72);
    *(s32 *)(a0 + 0x90) = a1;
    *(s32 *)(a0 + 0x94) = 0;
    *(s32 *)(a0 + 0x9C) = 0;
    *(s16 *)(a0 + 0x9A) = 0;
    *(u16 *)(a0 + 0x72) = v0 & 0xF9FF;
    func_8012AAAC();
}
