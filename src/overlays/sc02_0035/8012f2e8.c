/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8012F2E8 - byte-exact against retail at -O2 (tools/register_match.py). */
#define ApplyTransposeMatrixLV func_8004D504
extern void ApplyTransposeMatrixLV(void *a0, void *a1, void *a2);

void func_8012F2E8(s32 a0, s32 a1, s32 a2) {
    s32 s0 = a2;
    s32 in[3];
    s32 out[3];
    s32 mtx;
    mtx = *(s32 *)(a0 + 0x20);
    in[0] = *(s16 *)(a1 + 0x0) - *(s32 *)(mtx + 0x48);
    in[1] = *(s16 *)(a1 + 0x2) - *(s32 *)(mtx + 0x4C);
    in[2] = *(s16 *)(a1 + 0x4) - *(s32 *)(mtx + 0x50);
    ApplyTransposeMatrixLV((void *)(mtx + 0x34), in, out);
    *(s16 *)(s0 + 0x0) = out[0];
    *(s16 *)(s0 + 0x2) = out[1];
    *(s16 *)(s0 + 0x4) = out[2];
}
