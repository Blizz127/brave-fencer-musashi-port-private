/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017DB2C - byte-exact against retail at -O2 (tools/register_match.py). */
struct vec;
struct vec {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
};
extern s32 func_80128ED8(s32 param_1, s32 *param_2);

void func_8017DB2C(s32 a0) {
    s32 ret;
    u16 vecA[4];
    u16 vecB[4];

    ret = func_80128ED8(*(s32 *)(a0 + 0x20), (s32 *)(a0 + 0x24));
    if (ret != 0) {
        func_801292C8((u8 *)a0);
    } else {
        if (*(s16 *)(a0 + 0x2E) != 0) {
            func_8012931C((struct vec *)a0);
            *(s32 *)(a0 + 0x10) -= *(s32 *)(a0 + 0x10) >> 3;
            *(s32 *)(a0 + 0x14) += -0x4000;
            *(s32 *)(a0 + 0x18) -= *(s32 *)(a0 + 0x18) >> 3;
        } else {
            vecA[0] = *(u16 *)(a0 + 6);
            vecA[1] = *(u16 *)(a0 + 10);
            vecA[2] = *(u16 *)(a0 + 14);
            func_8012931C((struct vec *)a0);
            vecB[0] = *(u16 *)(a0 + 6);
            vecB[1] = *(u16 *)(a0 + 10);
            vecB[2] = *(u16 *)(a0 + 14);
            ret = func_80135168(0, vecA, vecB);
            if (ret != 0) {
                *(u16 *)(a0 + 6) = vecB[0];
                *(u16 *)(a0 + 10) = vecB[1];
                *(u16 *)(a0 + 14) = vecB[2];
                *(s32 *)(a0 + 0x14) = -(*(s32 *)(a0 + 0x14) >> 1);
            }
            *(s32 *)(a0 + 0x14) += 0x1C000;
        }
    }
}
