/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80159434 - byte-exact against retail at -O2 (tools/register_match.py). */


s32 func_80159434(s32 a0, s32 a1) {
    s32 a2 = *(s32 *)((s32)a0 + 0x20);
    u16 v1 = *(u16 *)((s32)a0 + 0x23A);
    u16 v0 = *(u16 *)((s32)a2 + 0x10);
    *(u16 *)((s32)a2 + 0x10) = (v0 - v1) & 0xFFF;
    return (*(s32 *)((s32)a0 + 0x238) += a1);
}
