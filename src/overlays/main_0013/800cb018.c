/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB018 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80154A74(s32 a0, s32 a1);

void func_800CB018(s32 a0) {
    extern void func_80154A74(s32 a0, s32 a1);
    *(u16 *)(a0 + 0x1BA) = 0x1000;
    *(u16 *)(a0 + 0x1B8) = 0x1000;
    *(u32 *)(a0 + 0x44) = *(u32 *)(a0 + 0x44) & ~2;
    func_80154A74(a0, 0x11);
}
