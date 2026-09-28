/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80150150 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80134510(s32 arg);

s32 func_80150150(s32 a, s32 b) {
    return func_80134510(b) != 0;
}
