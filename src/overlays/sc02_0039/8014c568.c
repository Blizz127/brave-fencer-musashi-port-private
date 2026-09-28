/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8014C568 - byte-exact against retail at -O2 (tools/register_match.py). */
#define ratan2 func_8004CFEC
extern s32 ratan2(s32 a0, s32 a1);
extern s32 ratan2(s32, s32);
extern s32 ratan2(s32 x, s32 y);

s32 func_8014C568(s16 *a0, s16 *a1) {
    return ratan2(a0[3] - a1[0], a0[7] - a1[2]) & 0xFFF;
}
