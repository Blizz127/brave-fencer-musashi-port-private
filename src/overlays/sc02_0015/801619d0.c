/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801619D0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u8 D_80078EC0;
extern u8  D_80078EC0;

s32 func_801619D0(void *a0) {
    s32 v0;
    if (*(s16 *)((s32)a0 + 0x1C8) == 0) {
        v0 = 0;
    } else {
        v0 = ((D_80078EC0 & 0x7F) ^ 3) == 0;
    }
    return v0;
}
