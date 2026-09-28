/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80174188 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_8014BCEC(s32 a0, s32 a1);
extern s32 func_8014BCEC(s32, s32);

s32 func_80174188(s32 a0) {
    return func_8014BCEC(a0, 0x19);
}
