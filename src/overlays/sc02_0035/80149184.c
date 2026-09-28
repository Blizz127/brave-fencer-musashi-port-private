/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80149184 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_801491C4(s32 a0);

s32 func_80149184(s32 a0) {
    s32 v0;
    s32 v1;
    v0 = func_801491C4(a0);
    v1 = *(u16*)(*(s32*)(a0 + 0x20) + 0x12);
    return (v1 - v0) & 0xFFF;
}
