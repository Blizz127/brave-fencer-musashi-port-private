/* Owner re-derivation from retail assembly (clean room, clean input set; D2 grouped GTE macros). */
/* Visibility test for a point against a packed pair of half extents: returns 1 at once for the
 * sentinel 0x7FFF7FFF, otherwise transforms the 3-word position through the matrix at
 * D_800AE688 (perspective transform), and returns 1 when the GTE flag shows no error and the
 * projected x/y lie in (-hx, hx] and (-hy, hy] (hx = low half, hy = high half of the bounds). */
#include "psx_types.h"
#include "gte_ops.h"

typedef struct {
    s16 m[3][3];
    s16 pad;
    s32 t[3];
} Mat;

extern Mat D_800AE688;

s32 func_80021174(s32 bounds, s32 *pos)
{
    s32 out[3];

    if (bounds == 0x7FFF7FFF) {
        return 1;
    }
    gte_g_ld_rot(&D_800AE688);
    gte_g_ld_trans(&D_800AE688);
    gte_g_ld_lv0(pos);
    gte_nop();
    gte_nop();
    gte_rtps();
    gte_swc2(14, 0, &out[0]);
    gte_g_st_flag(&out[1]);
    gte_g_st_sz3_sra2(&out[2]);
    if (out[1] < 0) {
        return 0;
    }
    if (-(s16)bounds < ((s16 *)out)[0] && ((s16 *)out)[0] <= (s16)bounds
        && -(bounds >> 16) < ((s16 *)out)[1] && ((s16 *)out)[1] <= (bounds >> 16)) {
        return 1;
    }
    return 0;
}
