/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8012B8A4 - byte-exact against retail at -O2 (tools/register_match.py). */
#define ratan2 func_8004CFEC
extern u16 D_80126B5E;
extern u16 D_80126B66;
extern s32 ratan2(s32 a0, s32 a1);
extern s32 ratan2(s32 x, s32 y);

s32 func_8012B8A4(s16 *a0) {
    s16 cx = a0[7];
    s16 dx = D_80126B66;
    s16 dy = D_80126B5E;
    s16 cy = a0[3];
    return (ratan2(cx - dx, dy - cy) - 0x400) & 0xFFF;
}
