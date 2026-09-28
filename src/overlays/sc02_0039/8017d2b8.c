/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017D2B8 - byte-exact against retail at -O2 (tools/register_match.py). */
#define ApplyMatrixSV func_80048FBC
extern void ApplyMatrixSV(void *a0, void *a1, void *a2);
extern s32 func_80012C6C(s32 a0, s32 a1, s32 a2);
extern s32 func_80012ABC(s32 a0, s32 a1, s32 a2);
extern void func_8017D930(void *a0, void *a1);

void func_8017D2B8(s32 param_1, s32 param_2, s16 *param_3) {
    s32 m1[8];
    u16 svec_in[4];
    u16 svec_out[4];
    u16 rot[4];

    *(s32 *)(param_1 + 0x8)  = (s16)func_80012C6C((s32)*(s16 *)(param_1 + 0x8),  (s32)*(s16 *)(param_1 + 0xC),  4);
    *(s32 *)(param_1 + 0x10) = (s16)func_80012C6C((s32)*(s16 *)(param_1 + 0x10), (s32)*(s16 *)(param_1 + 0x14), 4);
    *(s16 *)(param_1 + 0x18) = func_80012ABC((s32)*(s16 *)(param_1 + 0x18), (s32)*(s16 *)(param_1 + 0x20), 4);
    *(s16 *)(param_1 + 0x1A) = func_80012ABC((s32)*(s16 *)(param_1 + 0x1A), (s32)*(s16 *)(param_1 + 0x22), 4);
    *(s16 *)(param_1 + 0x1C) = func_80012ABC((s32)*(s16 *)(param_1 + 0x1C), (s32)*(s16 *)(param_1 + 0x24), 4);
    *(s16 *)(param_1 + 0x28) = func_80012C6C((s32)*(s16 *)(param_1 + 0x28), (s32)*(s16 *)(param_1 + 0x2E), 0x10);
    *(s16 *)(param_1 + 0x2A) = func_80012C6C((s32)*(s16 *)(param_1 + 0x2A), (s32)*(s16 *)(param_1 + 0x30), 0x10);
    *(s16 *)(param_1 + 0x2C) = func_80012C6C((s32)*(s16 *)(param_1 + 0x2C), (s32)*(s16 *)(param_1 + 0x32), 0x10);

    *(s32 *)(param_1 + 0x48) = (s32)*(s16 *)(param_1 + 0x28) + (s32)param_3[0];
    *(s32 *)(param_1 + 0x4C) = (s32)*(s16 *)(param_1 + 0x2A) + (s32)param_3[1];
    *(s32 *)(param_1 + 0x50) = (s32)*(s16 *)(param_1 + 0x2C) + (s32)param_3[2];

    rot[0] = *(u16 *)(param_1 + 0x18);
    rot[1] = *(u16 *)(param_1 + 0x1A) + param_2;
    rot[2] = *(u16 *)(param_1 + 0x1C);
    func_8017D930(rot, m1);

    svec_in[0] = 0;
    svec_in[1] = 0;
    svec_in[2] = *(s32 *)(param_1 + 0x10);
    ApplyMatrixSV(m1, svec_in, svec_out);

    *(s32 *)(param_1 + 0x3C) = ((s32)(s16)svec_out[0] >> 3) + *(s16 *)(param_1 + 0x28) + param_3[0];
    *(s32 *)(param_1 + 0x40) = ((s32)(s16)svec_out[1] >> 3) + *(s16 *)(param_1 + 0x2A) + param_3[1];
    *(s32 *)(param_1 + 0x44) = ((s32)(s16)svec_out[2] >> 3) + *(s16 *)(param_1 + 0x2C) + param_3[2];
}
