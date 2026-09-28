/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80149D9C - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80149E94(s32 a0);
extern s32 func_80149DD8(s32 a0);

s32 func_80149D9C(s32 a0) {
    s32 v0;
    if (func_80149E94(a0) != 0) {
        v0 = 1;
    } else {
        v0 = func_80149DD8(a0) != 0;
    }
    return v0;
}
