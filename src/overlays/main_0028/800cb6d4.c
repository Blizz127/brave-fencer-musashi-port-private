/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB6D4 - byte-exact against retail at -O2 (tools/register_match.py). */
#define ratan2 func_8004CFEC
extern s32 func_80047948(s32 a0);
extern s32 func_8004787C(s32 a0);
extern s32 func_80012F74(s32 a0, s32 a1, s32 a2, s32 a3);
extern s32 ratan2(s32 a0, s32 a1);

s32 func_800CB6D4(s32 a0) {
    s32 s1;
    s16 tmp[3];
    s32 v0;
    s16 v1;
    s32 sum;
    s16 diff;

    s1 = *(s32 *)(a0 + 0x20);

    v0 = func_80047948(*(s16 *)(a0 + 0x64));
    v1 = *(s16 *)(a0 + 0x60);
    tmp[0] = (v1 * v0) / 4096;

    if (*(s32 *)(a0 + 0x54) == 0) {
        tmp[1] = 0;
        v0 = func_8004787C(*(s16 *)(a0 + 0x64));
        v1 = *(s16 *)(a0 + 0x62);
        tmp[2] = (v1 * v0) / 4096;
    } else {
        v0 = func_8004787C(*(s16 *)(a0 + 0x64));
        v1 = *(s16 *)(a0 + 0x62);
        tmp[1] = (v1 * v0) / 4096;
        tmp[2] = 0;
    }

    v0 = func_80012F74(*(s16 *)(a0 + 0x6), (s16)(*(u16 *)(a0 + 0x10) + (u16)tmp[0]), 0xA, 1);
    *(s16 *)(a0 + 0x6) = v0;

    v0 = func_80012F74(*(s16 *)(a0 + 0xA), (s16)(*(u16 *)(a0 + 0x12) + (u16)tmp[1]), 0xA, 1);
    *(s16 *)(a0 + 0xA) = v0;

    v0 = func_80012F74(*(s16 *)(a0 + 0xE), (s16)(*(u16 *)(a0 + 0x14) + (u16)tmp[2]), 0xA, 1);
    *(s16 *)(a0 + 0xE) = v0;

    v0 = ratan2(*(s16 *)(a0 + 0x6) - *(s16 *)(a0 + 0x44), *(s16 *)(a0 + 0x46) - *(s16 *)(a0 + 0xA));
    *(u16 *)(s1 + 0x14) = (v0 - 0x200) & 0xFFF;

    {
        s32 f50 = *(s32 *)(a0 + 0x50);
        sum = *(u16 *)(a0 + 0x64) + f50;
    }
    *(u16 *)(a0 + 0x64) = sum;
    if (*(s32 *)(a0 + 0x50) >= 0) {
        diff = sum - *(u16 *)(a0 + 0x66);
    } else {
        diff = *(u16 *)(a0 + 0x66) - sum;
    }

    if (diff < 0x1001) {
        return 0;
    }
    *(u16 *)(a0 + 0x64) = *(u16 *)(a0 + 0x66);
    return 1;
}
