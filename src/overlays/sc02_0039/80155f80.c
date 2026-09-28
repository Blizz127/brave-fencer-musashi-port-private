/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80155F80 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80154A74(s32 a0, s32 a1);

s32 func_80155F80(s32 a0)
{
    *(u32 *)(a0 + 0x44) = *(u32 *)(a0 + 0x44) & ~2;
    func_80154A74(a0, 0x11);
}
