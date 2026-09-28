/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A1F3C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct M4_801A0168 {
    u8 unk0[4];
} M4_801A0168;
extern M4_801A0168 D_801A0168;
extern u16 D_8019FF8A;
extern s32 D_801AFD58;
extern s32 D_801EEAC8;
extern s16 D_801F8714;
extern u16 D_801F8718;
extern void func_80016450(s32 a0, s32 a1);
extern void func_801AAA6C(s32 a0);
extern s32 func_8012BEE8(s32 a0);
extern void func_801A3EEC(s32 a0);
extern void func_80184C70(void);
extern void func_80184DB0(s32 a0, void *a1, s32 a2);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8013C9C4(void *a0);
extern void func_801A3744(s32 a0);
extern s32 func_801A7CDC(void *a0);
extern s32 func_801A861C(s32 a0, s16 a1);
extern void func_801A8DCC(s32 a0, s32 a1);
extern void func_80184E20(void *a0);
extern void func_80184E98(s32 a0, s32 a1);
extern void func_8018503C(void);
extern int func_8005C49C(void);
extern s32 func_801A3798(s32 a0, s32 a1);
extern void func_801A40CC(s32 a0);
extern s32 func_8001AAA0(s32 a0);
extern void func_8017F558(void);
extern s32 func_80178970(s32 a0);
extern void func_80178D18(s32 a0);
extern void func_8017BF08(void *a0, void *a1, s32 a2, s32 a3);
extern void func_8017F004(void);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012B200(u8 *a0);
extern void func_8012AD44(s32 *a0, s16 a1);

void func_801A1F3C(s32 s0)
{
    M4_801A0168 sp10;
    s32 v0;
    void *p;

    sp10 = D_801A0168;
    switch (*(u16 *)(s0 + 0x34)) {
    case 0:
        if (*(s16 *)(s0 + 0x100) != 0) {
            func_80016450(*(s16 *)(s0 + 0x100) & 0xFF, 1);
            if (((*(u16 *)(s0 + 0x100) = *(u16 *)(s0 + 0x100) - 4) << 16) < 0) {
                *(u16 *)(s0 + 0x100) = 0;
            }
        }
        func_801AAA6C(s0);
        if (func_8012BEE8(s0) != 0) {
            func_801A3EEC(9);
            func_80184C70();
            func_80184DB0(0, &sp10, -8);
            *(s32 *)(s0 + 0x1C) = 0x20;
            *(u16 *)(s0 + 0x34) = 1;
            func_8002D4C8(0xB4B, 0);
        }
        break;
    case 1:
        func_801AAA6C(s0);
        if ((*(s32 *)(s0 + 0x1C) & 7) == 0) {
            func_8013C9C4(&D_801AFD58);
        }
        if (func_8012BEE8(s0) != 0) {
            u16 t;

            *(s32 *)(s0 + 0x1C) = 0x140;
            t = D_8019FF8A;
            *(u16 *)(s0 + 0x34) = 2;
            D_8019FF8A = t | 0x4000;
            func_8002D4C8(0xB5A, 0);
        }
        break;
    case 2:
        if (func_8012BEE8(s0) != 0) {
            func_801A3744(s0);
            *(u16 *)(*(s32 *)(s0 + 0x20) + 0x12) = 0;
            *(u16 *)(s0 + 0x34) = 3;
            func_8002D4C8(4, 0xB4B);
            func_8002D4C8(4, 0xB5A);
            break;
        }
        func_801AAA6C(s0);
        p = *(void **)(s0 + 0xD4);
        if (p != NULL) {
            v0 = *(s32 *)(s0 + 0x1C) & 0x1F;
            if (v0 == 7 || v0 == 0x14 || v0 == 0x17) {
                func_801A7CDC(p);
            }
        }
        if ((*(s32 *)(s0 + 0x1C) & 7) == 0) {
            func_8013C9C4(&D_801AFD58);
        }
        if ((*(s32 *)(s0 + 0x1C) & 0x1F) == 0) {
            if (func_801A861C(s0, *(s16 *)(s0 + 0x100)) != 0) {
                *(u16 *)(s0 + 0x100) = *(u16 *)(s0 + 0x100) + 1;
                func_8002D4C8(0xB59, 0);
            }
        }
        if (*(s32 *)(s0 + 0x1C) >= 0x11) {
            func_801A8DCC(s0, 0);
            func_80184E20((void *)(s0 + 4));
            func_80184E98(func_8005C49C() & 0xFF8, 0x60);
        }
        *(u16 *)(*(s32 *)(s0 + 0x20) + 0x12) += 0x80;
        break;
    case 3:
        if (func_801A3798(s0, 0) != 0) {
            func_801A40CC(s0);
            *(u16 *)(s0 + 0x34) = 4;
        }
        break;
    case 4:
        if (*(s16 *)(s0 + 0x84) != 0) {
            func_8001AAA0(0x8C);
            *(u16 *)(s0 + 0x34) = 5;
            func_8017F558();
        }
        break;
    case 5:
    case 6:
        break;
    }
    func_8018503C();
    if (*(s16 *)(s0 + 0x84) == 0) {
        *(u16 *)(s0 + 0x84) = func_8001AAA0(0x9D);
    }
    if (func_80178970(s0) != 0) {
        func_80178D18(s0);
        func_801A3EEC(1);
        func_8017BF08(&D_801F8714, &D_801F8718, 0xB, 0x120);
        func_8017F004();
        func_8012A828(s0, &D_801EEAC8);
        *(s32 *)(s0 + 0x1C) = (s16)(D_801F8714 / 79) + 0x18;
        func_8012B200((u8 *)s0);
        func_8012AD44((s32 *)s0, 1);
        *(s32 *)(s0 + 0x1C) = 0x10;
    }
}
