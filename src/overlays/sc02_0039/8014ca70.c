/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8014CA70 - byte-exact against retail at -O2 (tools/register_match.py). */


u16 func_8014CA70(s32 a0, s32 a1) {
    s32 base = *(s32 *)((s32)a0 + 0x78);
    return *(u16 *)((a1 << 1) + base + 0x14);
}
