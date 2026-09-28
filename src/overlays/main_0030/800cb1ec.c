/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB1EC - byte-exact against retail at -O2 (tools/register_match.py). */
#define RotMatrixY func_8004A0DC
typedef struct { s32 w[8]; } Blk32_CB1EC;

void func_800CB1EC(void *a0) {
    extern u8 D_80078EC1;
    extern Blk32_CB1EC D_800AE620;
    extern s16 D_80126B5E;
    extern s16 D_80126B62;
    extern s16 D_80126B66;
    extern void func_80016714(void *a0, s32 a1);
    extern s32 func_80128ED8(s32 a0, s32 *a1);
    extern void RotMatrixY(s32 a0, void *a1);
    extern s32 func_80047948(s32 a0);
    extern void func_8012F14C(s32 a0, s32 a1, s32 a2);
    extern void func_80146C3C();

    s16 out[3];
    Blk32_CB1EC buf;
    s32 *s3;
    s32 *s4;
    s32 s5;
    s32 v1;
    s32 mask;

    s3 = *(s32 **)((s32)a0 + 0x20);
    s4 = *(s32 **)((s32)a0 + 0x34);

    if (D_80078EC1 == 0x13) {
        v1 = *(s32 *)((s32)a0 + 0x1C);
        s5 = 0;
        if (v1 < 0x10) {
            *(u8 *)((s32)s3 + 0x24) = *(u8 *)((s32)s3 + 0x25) = *(u8 *)((s32)s3 + 0x26) = *(u8 *)((s32)s3 + 0x26) + 4;
            *(u16 *)((s32)s3 + 0x18) -= 0x400;
            *(u16 *)((s32)s3 + 0x1A) -= 0x400;
        } else {
            s5 = v1 - 0x10;
            func_80128ED8((s32)s3, (s32 *)((s32)a0 + 0x24));
        }

        mask = 0x7FFFFFFF;
        *(s32 *)((s32)s3 + 4) &= mask;

        buf = D_800AE620;

        RotMatrixY(((s5 << 16) >> 11) + *(s32 *)((s32)a0 + 0x2C), &buf);

        out[0] = 0;
        buf.w[5] = D_80126B5E;
        buf.w[6] = D_80126B62;
        buf.w[7] = D_80126B66;

        v1 = func_80047948(((s5 & 0xF) << 8) + *(s32 *)((s32)a0 + 0x2C));
        out[1] = (v1 >> 9) - 0x30;
        out[2] = -0x50;

        func_8012F14C((s32)&buf, (s32)out, (s32)out);

        *(u16 *)((s32)a0 + 0x6) = out[0];
        *(u16 *)((s32)a0 + 0xA) = out[1];
        *(u16 *)((s32)a0 + 0xE) = out[2];

        *(s32 *)((s32)s4 + 4) &= mask;
        *(u16 *)((s32)s4 + 0x18) = *(u16 *)((s32)s3 + 0x18);
        *(u16 *)((s32)s4 + 0x1A) = *(u16 *)((s32)s3 + 0x1A);
        *(u16 *)((s32)s4 + 0x8) = *(u16 *)((s32)a0 + 0x6);
        *(u16 *)((s32)s4 + 0xA) = *(u16 *)((s32)a0 + 0xA);
        *(u16 *)((s32)s4 + 0xC) = *(u16 *)((s32)a0 + 0xE);
        *(s32 *)((s32)a0 + 0x1C) += 1;
    } else {
        if (s4 != ((void *)0) ) {
            func_80016714((void *)s4, 0x38);
        }
        func_80146C3C(a0);
    }
}
