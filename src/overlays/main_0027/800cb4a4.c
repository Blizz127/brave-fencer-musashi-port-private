/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB4A4 - byte-exact against retail at -O2 (tools/register_match.py). */
#define currentLocationId D_800B9A08
extern s32 D_80078EC8;
extern u8 D_800CC298[];
extern void func_800CB82C(s32 a0, s32 a1);
extern void func_80146D90(s32 a0);
extern s32 func_801488A8(s32 a0);
extern s32 func_80148D44(s32 a0);
extern void func_80162FF4(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_800134FC(s32 a0, void *a1, void *a2);
extern void func_8001599C(void *a0, void *a1);
extern void func_80162FC0(s32 a0);
extern void func_800CBCB4(void *a0);
extern s32 func_80012F74(s32 a0, s32 a1, s32 a2, s32 a3);
extern s16 currentLocationId;
extern s16 D_800CC29A;
extern s16 D_800CC29C;
typedef struct { s32 w[4]; } CB4A4_V4;

void func_800CB4A4(s32 a0) {
    u8 *ap;
    s32 s1;
    s32 s3;
    s32 *s2;
    s32 v0;
    s32 d;
    s32 flag;
    CB4A4_V4 bak[2];
    s16 *dig;

    s1 = a0;
    s3 = *(s32 *)(s1 + 0x4C);
    ap = *(u8 **)(s1 + 0x20);
    if (D_80078EC8 < 0x28) {
        *(u16 *)(ap + 0x18) = *(u16 *)(ap + 0x18) - 0x40;
        *(u16 *)(ap + 0x1A) = *(u16 *)(ap + 0x1A) - 0x40;
    }
    func_800CB82C(s1, *(s32 *)(s1 + 0x58));
    if (func_801488A8(s3) != 0) {
        bak[1] = *(CB4A4_V4 *)(s1 + 0x10);
        func_80146D90(s1);
        *(s32 *)(s1 + 0x18) = 0;
        *(s32 *)(s1 + 0x14) = 0;
        v0 = func_80148D44((*(s32 *)(s1 + 0x10) = 0, s1));
        *(u16 *)(*(s32 *)(s1 + 0x20) + 0x12) = v0;
        func_80162FF4(s1, 0, 0, 0xFFFE4000);
        s2 = (s32 *)(s1 + 0x10);
        if (currentLocationId == 0x3038) {
            bak[0] = *(CB4A4_V4 *)s2;
            func_800134FC(0x400, &bak[0], &bak[0]);
            func_8001599C(&bak[0], s2);
        }
        *(s32 *)(s1 + 0x10) += bak[1].w[0];
        *(s32 *)(s1 + 0x14) += bak[1].w[1];
        *(s32 *)(s1 + 0x18) += bak[1].w[2];
        if (*(s32 *)(s1 + 0x10) > 0xE0000) {
            *(s32 *)(s1 + 0x10) = 0xE0000;
        } else if (*(s32 *)(s1 + 0x10) < -0xE0000) {
            *(s32 *)(s1 + 0x10) = -0xE0000;
        }
        if (*(s32 *)(s1 + 0x14) > 0xE0000) {
            *(s32 *)(s1 + 0x14) = 0xE0000;
        } else if (*(s32 *)(s1 + 0x14) < -0xE0000) {
            *(s32 *)(s1 + 0x14) = -0xE0000;
        }
        if (*(s32 *)(s1 + 0x18) > 0xE0000) {
            *(s32 *)(s1 + 0x18) = 0xE0000;
        } else if (*(s32 *)(s1 + 0x18) < -0xE0000) {
            *(s32 *)(s1 + 0x18) = -0xE0000;
        }
    } else {
        flag = 0;
        if (*(s32 *)(s1 + 0x10) != 0) {
            flag = 1;
            if (*(s32 *)(s1 + 0x10) >= 0) {
                d = *(s32 *)(s1 + 0x10) - 0x8000;
                *(s32 *)(s1 + 0x10) = d;
                if (d < 0) {
                    *(s32 *)(s1 + 0x10) = 0;
                }
            } else {
                d = *(s32 *)(s1 + 0x10) + 0x8000;
                *(s32 *)(s1 + 0x10) = d;
                if (d >= 0) {
                    *(s32 *)(s1 + 0x10) = 0;
                }
            }
        }
        if (*(s32 *)(s1 + 0x14) != 0) {
            flag = 1;
            if (*(s32 *)(s1 + 0x14) >= 0) {
                d = *(s32 *)(s1 + 0x14) - 0x8000;
                *(s32 *)(s1 + 0x14) = d;
                if (d < 0) {
                    *(s32 *)(s1 + 0x14) = 0;
                }
            } else {
                d = *(s32 *)(s1 + 0x14) + 0x8000;
                *(s32 *)(s1 + 0x14) = d;
                if (d >= 0) {
                    *(s32 *)(s1 + 0x14) = 0;
                }
            }
        }
        if (*(s32 *)(s1 + 0x18) != 0) {
            flag = 1;
            if (*(s32 *)(s1 + 0x18) >= 0) {
                d = *(s32 *)(s1 + 0x18) - 0x8000;
                *(s32 *)(s1 + 0x18) = d;
                if (d < 0) {
                    *(s32 *)(s1 + 0x18) = 0;
                }
            } else {
                d = *(s32 *)(s1 + 0x18) + 0x8000;
                *(s32 *)(s1 + 0x18) = d;
                if (d >= 0) {
                    *(s32 *)(s1 + 0x18) = 0;
                }
            }
        }
        if (flag == 0) {
            goto tail;
        }
    }
    func_80162FC0(s1);
tail:
    func_800CBCB4((void *)s1);
    dig = (s16 *)D_800CC298;
    v0 = func_80012F74(dig[0], *(s16 *)(s1 + 6), 0xA, 1);
    dig[0] = v0;
    v0 = func_80012F74(D_800CC29A, *(s16 *)(s1 + 0xA), 0xA, 1);
    D_800CC29A = v0;
    v0 = func_80012F74(D_800CC29C, *(s16 *)(s1 + 0xE), 0xA, 1);
    D_800CC29C = v0;
    memcpy((void *)(s3 + 0x154), &D_800CC298[0], 8);
}
