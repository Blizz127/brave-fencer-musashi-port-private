/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8012F0BC - byte-exact against retail at -O2 (tools/register_match.py). */
#define ApplyTransposeMatrixLV func_8004D504
extern void ApplyTransposeMatrixLV(void *a0, void *a1, void *a2);

void func_8012F0BC(s32 *a0, s32 *a1, s32 *a2) {
    s32 in[3];
    s32 out[3];
    in[0] = a1[0] - (a0[5] << 16);
    in[1] = a1[1] - (a0[6] << 16);
    in[2] = a1[2] - (a0[7] << 16);
    ApplyTransposeMatrixLV(a0, in, out);
    a2[0] = out[0];
    a2[1] = out[1];
    a2[2] = out[2];
}
