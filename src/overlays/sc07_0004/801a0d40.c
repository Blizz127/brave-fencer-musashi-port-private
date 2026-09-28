/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A0D40 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8002D4C8(s32 a0, s32 a1);
extern s32 func_8012C658(s32 a0, s32 a1, s32 a2);
extern s32 func_8012BEE8(s32 a0);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012B200(u8 *a0);
extern void func_8012AD44(s32 *a0, s16 a1);
extern s32 func_8012B8A4(s16 *a0);
extern void func_8017F418(void);
extern void func_801A3624(s32 a0, u16 *a1, s32 a2);
extern void func_801A3EEC(s32 a0);
extern void func_801A4328(s32 a0);
extern void func_801A108C(s32 arg0);
extern void func_801A1124(s32 a0);
extern void func_801A9AAC(void);
extern s32 func_801A9ADC(void);
extern s32 D_801EF4C0;
extern s32 D_801AFC60;
extern s32 D_801EF5C8;
extern s32 D_801EEAC8;
extern s16 D_801F8714;

void func_801A0D40(s32 a0) {
    s32 v0;
    s32 v1;

    switch (*(u16 *)(a0 + 0x34)) {
    case 0:
        if (*(s16 *)(a0 + 0xA) >= -0x220) {
            *(s16 *)(a0 + 0xA) = -0x220;
        } else {
            *(s16 *)(a0 + 0xA) = *(s16 *)(a0 + 0xA) + 2;
        }
        if (*(s32 *)(a0 + 0x94) == 0x14) {
            *(u16 *)(a0 + 0x34) = *(u16 *)(a0 + 0x34) + 1;
            func_8002D4C8(0xBA5, 0);
        }
        break;
    case 1:
        v0 = *(u16 *)(a0 + 0xA) - 0x10;
        *(s16 *)(a0 + 0xA) = v0;
        if (*(s32 *)(a0 + 0x94) == 0x1A) {
            func_8012C658(0x3A4, *(u16 *)(a0 + 2) == 4, a0);
            *(s32 *)(a0 + 0x1C) = 0x14;
            *(u16 *)(a0 + 0x34) = *(u16 *)(a0 + 0x34) + 1;
        }
        break;
    case 2:
        if (*(s16 *)(a0 + 0x98) != 0) {
            break;
        }
        if (func_8012BEE8(a0) != 0) {
            func_8012A828(a0, &D_801EF4C0);
            *(u16 *)(a0 + 0x34) = *(u16 *)(a0 + 0x34) + 1;
            if (*(u16 *)(a0 + 2) == 4) {
                a0 = 8;
                func_801A9AAC();
            } else {
                a0 = 7;
            }
            func_801A3EEC(a0);
        }
        break;
    case 3:
        if (*(s16 *)(a0 + 0x98) == 0) {
            func_8012A828(a0, &D_801AFC60);
            *(s32 *)(a0 + 0x1C) = 0x60;
            *(u16 *)(a0 + 0x34) = *(u16 *)(a0 + 0x34) + 1;
            break;
        }
        *(s32 *)(a0 + 0x1C) = *(s32 *)(a0 + 0x1C) + 1;
        if (*(u16 *)(a0 + 2) == 4) {
            func_801A108C(a0);
            func_801A9ADC();
        } else {
            func_801A1124(a0);
        }
        break;
    case 4:
        if (func_8012BEE8(a0) != 0) {
            func_8012A828(a0, &D_801EF5C8);
            *(u16 *)(a0 + 0x34) = *(u16 *)(a0 + 0x34) + 1;
        } else if (*(u16 *)(a0 + 2) == 4) {
            func_801A108C(a0);
        } else {
            func_801A1124(a0);
        }
        if (*(u16 *)(a0 + 2) == 4) {
            func_801A9ADC();
        }
        break;
    case 5:
        if (*(s16 *)(a0 + 0xA) < -0x240) {
            *(s16 *)(a0 + 0xA) = *(s16 *)(a0 + 0xA) + 1;
        }
        if (*(s16 *)(a0 + 0x98) == 0 && *(s16 *)(a0 + 0xA) >= -0x240) {
            if (*(u16 *)(a0 + 2) == 4) {
                *(s32 *)(a0 + 0x1C) = 8;
            } else {
                *(s32 *)(a0 + 0x1C) = 0x20;
            }
            *(u16 *)(a0 + 0x34) = *(u16 *)(a0 + 0x34) + 1;
        }
        if (*(u16 *)(a0 + 2) == 4) {
            func_801A9ADC();
        }
        break;
    case 6:
        v1 = func_8012B8A4((s16 *)a0);
        *(s16 *)(a0 + 0xFE) = v1;
        func_801A3624((s16)v1, (u16 *)(*(s32 *)(a0 + 0x20) + 0x12), 0x40);
        if (func_8012BEE8(a0) != 0) {
            func_8012A828(a0, &D_801EEAC8);
            *(s32 *)(a0 + 0x1C) = (s16)(D_801F8714 / 79) + 0x18;
            func_8012B200((u8 *)a0);
            func_8012AD44((s32 *)a0, 1);
            func_801A4328(0);
            func_8017F418();
            func_801A3EEC(1);
            *(u16 *)(a0 + 0x5C) = *(u16 *)(a0 + 0x5C) | 0x2000;
            break;
        }
        if (*(u16 *)(a0 + 2) == 4) {
            func_801A9ADC();
        }
        break;
    }
}
