/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A2400 - byte-exact against retail at -O2 (tools/register_match.py). */
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
typedef struct { s32 vx, vy, vz, pad; } Vec32_801A2400;
typedef struct { s16 vx, vy, vz, pad; } SVec_801A2400;
typedef struct { s32 w[8]; } Mtx32_801A2400;
extern u16 D_8019FF8A;
extern u16 D_801F8EB2[];
extern u16 D_801F8EB0;
extern s32 D_801F8720;
extern s32 D_80062BC0;
extern s32 D_801AFDDC;
extern u8 D_8018A27C[];
extern s32 func_8012BEE8(s32 a0);
extern void func_801A34C4(s32 a0);
extern void func_801A34FC(s32 arg0, u16 *arg1);
extern s32 func_8012B744(void *a0, void *a1);
extern void func_8004A0DC(s32 a0, void *a1);
extern void func_800484EC(s32 a0, s32 a1, s32 a2);
extern s32 func_8004787C(s32 a0);
extern void func_801A3624(s32 a0, u16 *a1, s32 a2);
extern void func_8012AD80(s32 a0);
extern s32 func_801A3594(void *a0);
extern void func_801A3744(s32 a0);
extern s32 func_801A3798(s32 a0, s32 a1);
extern void func_801A395C(s32 a0, s32 a1);
extern s32 func_8012C588(s32 a0, s32 a1);
extern void func_80184C70(void);
extern void func_80184DB0(s32 a0, void *a1, s32 a2);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_801A8DCC(s32 a0, s32 a1);
extern void func_80184E20(void *a0);
extern void func_80184E98(s32 a0, s32 a1);
extern void func_8018503C(void);
extern int func_8005C49C(void);
extern s32 func_801A8564(s32 a0);
extern void func_80016450(s32 a0, s32 a1);
extern void func_801A2C88(void);
extern void func_801A2CA4(void);
extern void func_801A4060(s32 a0);
extern void func_801A43EC(s32 a0);
extern void func_801ADC40(u8 *a0);
extern void func_801AD5B4(s32 a0, s32 a1);
extern void func_801A86F8(void);
extern void func_801A876C(s32 a0, s16 a1, s32 a2);
extern void func_801A87C4(s32 a0, s16 a1, s32 a2);
extern void func_801ADA9C(s32 a0);
extern void func_801AEB94(void);
extern s32 func_801A8670(s32 a0);
extern s32 func_801A86B4(s32 a0);
extern void func_801AD294(void);
extern void func_801AD640(s32 a0, s32 a1);
extern void func_801AD2CC(void);
extern s32 func_801ACE04(s32 a0);
extern s32 func_80019198(void);
extern void func_80019064(void *a0);
extern void func_800D1724(s32 a0);
extern s32 func_80178970();

void func_801A2400(s32 arg0) {
    /* D_800AE620 at BLOCK scope exactly as func_801A3180 (:931): the file-scope
     * spelling `extern Mtx32_801A90D8 D_800AE620;` lands LATER (:2001) and a
     * second file-scope spelling is a hard gcc-2.7.2 conflicting-types error. */
    extern s32 D_800AE620[8];
    Vec32_801A2400 sp10;
    SVec_801A2400 sp20;
    Mtx32_801A2400 m;          /* sp+0x28 */
    Vec32_801A2400 sp48;
    M4_801A0168 sp58;          /* sp+0x58 (house style: cf. func_801A19C0) */
    register s32 s1 __asm__("$17");
    s32 s0;
    s32 v0;
    s32 v1;

    s1 = arg0;
    switch (*(u16 *)(s1 + 0x34)) {
    case 0:
        if (func_8012BEE8(s1) != 0) {
            v0 = *(s16 *)(s1 + 6) * *(s16 *)(s1 + 6) +
                 *(s16 *)(s1 + 0xE) * *(s16 *)(s1 + 0xE);
            *(u16 *)(s1 + 0x102) = 0;
            *(s32 *)(s1 + 0x1C) = 0x20;
            *(u16 *)(s1 + 0x34) = *(u16 *)(s1 + 0x34) + 1;
            if (v0 >= 0x41) {
                D_8019FF8A |= 0x40;
                sp20.vz = 0;
                sp20.vy = 0;
                sp20.vx = 0;
                func_801A34FC(s1, (u16 *)&sp20);
                v0 = func_8012B744((void *)(s1 + 4), &sp20);
                m = *(Mtx32_801A2400 *)&D_800AE620;
                func_8004A0DC((s16)v0, &m);
                sp10.vy = 0;
                sp10.vx = 0;
                sp10.vz = 0xFFFC0000;
                func_800484EC((s32)&m, (s32)&sp10, s1 + 0x10);
            } else {
                func_801A34C4(s1);
            }
        } else {
            if (*(s32 *)(s1 + 0x1C) == 0x10) {
                ((void (*)(s32))func_801A2C88)(s1);
            }
            ((void (*)(s32))func_801A2CA4)(s1);
        }
        break;
    case 1:
        func_8012BEE8(s1);
        if (((*(u16 *)(s1 + 0x102) >> 8) & 0x7F) == 0) {
            ((void (*)(s32))func_801A2C88)(s1);
        }
        ((void (*)(s32))func_801A2CA4)(s1);
        v0 = *(u16 *)(s1 + 0x102) + 0x400;
        *(u16 *)(s1 + 0x102) = v0;
        v0 = func_8004787C((s16)v0);
        *(u16 *)(s1 + 0xA) = *(u16 *)(s1 + 0xA) + (v0 >> 10);
        func_801A4060(s1);
        func_801A3624(0, (u16 *)(*(s32 *)(s1 + 0x20) + 0x12), 0x20);
        s0 = 1;
        if (D_8019FF8A & 0x40) {
            func_8012AD80(s1);
            s0 = func_801A3594((void *)s1);
            if (s0 != 0) {
                func_801A34C4(s1);
            }
        }
        if (s0 != 0 && *(s32 *)(s1 + 0x1C) == 0) {
            func_801A3744(s1);
            *(s16 *)(*(s32 *)(s1 + 0x20) + 0x12) = 0;
            *(u16 *)(s1 + 0x34) = *(u16 *)(s1 + 0x34) + 1;
        }
        break;
    case 2:
        if ((*(u16 *)(s1 + 0x102) >> 8) == 0) {
            ((void (*)(s32))func_801A2C88)(s1);
        }
        ((void (*)(s32))func_801A2CA4)(s1);
        v0 = *(u16 *)(s1 + 0x102) + 0x400;
        *(u16 *)(s1 + 0x102) = v0;
        v0 = func_8004787C((s16)v0);
        *(u16 *)(s1 + 6) = *(u16 *)(s1 + 6) + (v0 >> 9);
        func_801A4060(s1);
        func_801A3798(s1, 0);
        if (*(s16 *)(s1 + 0xE6) < 0) {
            *(u16 *)(s1 + 0x98) = 0;
            *(u16 *)(s1 + 0x34) = *(u16 *)(s1 + 0x34) + 1;
        }
        break;
    case 3:
        if ((*(u16 *)(s1 + 0x102) >> 8) == 0) {
            ((void (*)(s32))func_801A2C88)(s1);
        }
        ((void (*)(s32))func_801A2CA4)(s1);
        v0 = *(u16 *)(s1 + 0x102) + 0x400;
        *(u16 *)(s1 + 0x102) = v0;
        v0 = func_8004787C((s16)v0);
        *(u16 *)(s1 + 0xA) = *(u16 *)(s1 + 0xA) + (v0 >> 10);
        func_801A4060(s1);
        if (((s32 (*)(s32, s32))func_801A395C)(s1, -0x2A0) != 0) {
            func_8012C588(0x1FE, s1);
            *(s32 *)(s1 + 0x1C) = 0x70;
            *(u16 *)(s1 + 0x34) = *(u16 *)(s1 + 0x34) + 1;
            func_80184C70();
            sp58 = D_801A0168;
            func_80184DB0(0, &sp58, -8);
            func_8002D4C8(0xB5A, 0);
        }
        break;
    case 4:
        v0 = *(u16 *)(s1 + 0x102) + 0x400;
        *(u16 *)(s1 + 0x102) = v0;
        v0 = func_8004787C((s16)v0);
        *(u16 *)(s1 + 0xA) = *(u16 *)(s1 + 0xA) + (v0 >> 10);
        func_801A4060(s1);
        sp20.vx = 0;
        sp20.vy = -0x40;
        sp20.vz = 0x20;
        func_801A8DCC(s1, (s32)&sp20);
        func_801A8DCC(s1, (s32)&sp20);
        sp48.vx = *(s32 *)(s1 + 4);
        sp48.vy = *(s32 *)(s1 + 8) + 0xFFC00000;
        sp48.vz = *(s32 *)(s1 + 0xC);
        func_80184E20(&sp48);
        func_80184E98(func_8005C49C() & 0xFF8, 0x60);
        func_801ADC40((u8 *)s1);
        func_8012BEE8(s1);
        v1 = *(s32 *)(s1 + 0x1C);
        if ((v1 & 7) == 0) {
            func_801AD5B4(s1, (v1 & 0x18) >> 3);
            func_8002D4C8(0xB59, 0);
        }
        if (*(s32 *)(s1 + 0x1C) == 0x64) {
            *(s32 *)(s1 + 0xD4) = func_801A8564(s1);
        }
        if (*(s32 *)(s1 + 0x1C) < 0x60) {
            func_801A86F8();
            if (*(s32 *)(s1 + 0xD4) != 0) {
                func_801A876C(*(s32 *)(s1 + 0xD4), 0x1600, 0x30);
            }
        }
        if (*(s32 *)(s1 + 0x1C) == 0xE) {
            func_801ADA9C(s1);
        }
        if (*(s32 *)(s1 + 0x1C) < 0xF) {
            D_801F8EB2[0] += 0xA;
            D_801F8EB0 += 0xC;
            func_801AEB94();
        }
        if (*(s32 *)(s1 + 0x1C) == 8) {
            func_801A8670(s1);
            func_801A86B4(s1);
            func_8002D4C8(0xB4D, 0);
        }
        if (*(s32 *)(s1 + 0x1C) == 0) {
            *(s32 *)(s1 + 0x1C) = 0x60;
            *(u16 *)(s1 + 0x34) = 5;
            func_8002D4C8(4, 0xB5A);
        }
        break;
    case 5:
        D_801F8EB2[0] += 0xA;
        D_801F8EB0 += 0xC;
        func_801AEB94();
        func_801A86F8();
        if (*(s32 *)(s1 + 0xD4) != 0) {
            if (*(s32 *)(s1 + 0x1C) < 0x10) {
                func_801A87C4(*(s32 *)(s1 + 0xD4), 0x1000, 0x100);
            } else {
                func_801A876C(*(s32 *)(s1 + 0xD4), 0x1600, 0x30);
            }
        }
        if (func_8012BEE8(s1) != 0 && D_801F8720 != 0) {
            func_801AD294();
            *(u16 *)(s1 + 0x100) = 1;
            *(s32 *)(s1 + 0x1C) = 0x50;
            *(u16 *)(s1 + 0x34) = 6;
        }
        break;
    case 6:
        if ((*(s32 *)(s1 + 0x1C) & 0xF) == 0) {
            func_8012C588(0x39D, s1);
            func_801AD640(s1, *(u16 *)(s1 + 0x100) & 3);
            *(u16 *)(s1 + 0x100) = *(u16 *)(s1 + 0x100) + 2;
            if (func_80019198() == 0) {
                func_80019064(&D_80062BC0);
            }
        }
        func_801AEB94();
        if (func_8012BEE8(s1) != 0) {
            *(s32 *)(s1 + 0xCC) = func_8012C588(0x39F, s1);
            func_801AD2CC();
            *(u16 *)(s1 + 0x34) = 7;
        }
        break;
    case 7:
        s0 = 1;
        if (*(s32 *)(s1 + 0xCC) != 0) {
            s0 = func_801ACE04(*(s32 *)(s1 + 0xCC)) != 0;
        }
        if (s0 != 0) {
            *(u16 *)(s1 + 0x100) = 0;
            *(u16 *)(s1 + 0x34) = 8;
        }
        *(s32 *)(s1 + 0x1C) = *(s32 *)(s1 + 0x1C) + 1;
        if ((*(s32 *)(s1 + 0x1C) & 7) == 0 && func_80019198() == 0) {
            func_80019064(&D_801AFDDC);
        }
        break;
    case 8:
        if (*(s16 *)(s1 + 0x100) < 0xFF) {
            *(s16 *)(s1 + 0x100) += 4;
            if (*(s16 *)(s1 + 0x100) >= 0x100) {
                *(s16 *)(s1 + 0x100) = 0xFF;
                *(u16 *)(s1 + 0x34) = 9;
                func_800D1724((s32)D_8018A27C);
            } else if (*(s16 *)(s1 + 0x100) < 0x80) {
                *(s32 *)(s1 + 0x1C) = *(s32 *)(s1 + 0x1C) + 1;
                if ((*(s32 *)(s1 + 0x1C) & 7) == 0 && func_80019198() == 0) {
                    func_80019064(&D_801AFDDC);
                }
            }
        }
        func_80016450(*(u8 *)(s1 + 0x100), 1);
        break;
    case 9:
        func_80016450(0xFF, 1);
        break;
    }
    func_8018503C();
    ((void (*)(void))func_801A43EC)();
    func_80178970(s1);
}
