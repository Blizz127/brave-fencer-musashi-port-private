/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CD258 - byte-exact against retail at -O2 (tools/register_match.py). */


s32 func_800CD258(void *a0, void *a1) {
    s32 v;
    *(u8 *)((s32)a1 + 8) = 0;
    *(u8 *)((s32)a1 + 9) = 0;
    *(u8 *)((s32)a1 + 10) = 0;
    v = (*(u32 *)((s32)a0 + 0x1C)) << 3;
    *(u8 *)((s32)a1 + 14) = 0;
    *(u8 *)((s32)a1 + 12) = v;
    *(u8 *)((s32)a1 + 13) = v;
    return v;
}
