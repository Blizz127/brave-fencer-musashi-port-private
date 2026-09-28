/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8012B70C - byte-exact against retail at -O2 (tools/register_match.py). */
#define ratan2 func_8004CFEC
extern s32 ratan2(s32 a0, s32 a1);

s32 func_8012B70C(s16 *a0, s16 *a1) {
    s16 ax = a0[2];
    s16 bx = a1[2];
    s16 by = a1[0];
    s16 ay = a0[0];
    return (ratan2(ax - bx, by - ay) - 0x400) & 0xFFF;
}
