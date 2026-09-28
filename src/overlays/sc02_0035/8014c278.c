/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8014C278 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80013328(s32 a0, s32 a1);

s32 func_8014C278(s32 a0, s32 a1, s32 a2) {
    return func_80013328(a0 + 4, a1 + 4) < (s32)(a2 & 0xFFFF);
}
