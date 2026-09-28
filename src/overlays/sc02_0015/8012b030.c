/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8012B030 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80134510(s32 arg);

s32 func_8012B030(u8 *a0) {
    u16 local[3];
    local[0] = *(u16 *)(a0 + 0x6);
    local[1] = *(u16 *)(a0 + 0xA);
    local[2] = *(u16 *)(a0 + 0xE);
    if (func_80134510((s32)local) == 0) {
        return 0;
    }
    *(u16 *)(a0 + 0x6) = local[0];
    *(u16 *)(a0 + 0xA) = local[1];
    *(u16 *)(a0 + 0xE) = local[2];
    *(u16 *)(a0 + 0xC) = 0;
    *(u16 *)(a0 + 0x8) = 0;
    *(u16 *)(a0 + 0x4) = 0;
    return 1;
}
