/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A0400 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012AD44(s32 *a0, s16 a1);
extern void func_8012AD80(s32 a0);
extern void func_8012B178(s32 a0, s32 a1);
extern void func_8012B200(u8 *a0);
extern s32 func_8012B8A4(s16 *a0);
extern s32 func_8012BEE8(s32 a0);
extern s32 func_8012C658(s32 a0, s32 a1, s32 a2);
extern void func_80132288(s32 *a0, s32 *a1, s32 a2);
extern void func_8013240C(s32 a0);
extern void func_801A3180(s32 a0, s32 a1);
extern void func_801A3624(s32 a0, u16 *a1, s32 a2);
extern void func_801A36A8(s32 a0);
extern void func_801A4328(s32 a0);
extern u16 D_8019FF8A;
extern s32 D_801AFBA4;
extern s32 D_801AFBB4;
extern s16 D_801AFBB8;
extern s32 D_801B6EC0;
extern s32 D_801B6EC4;
extern s32 D_801B6EC8;
extern s32 D_801B872C;
extern s32 D_801EEAC8;
extern s32 D_801EF270;
extern s32 D_801EF3B8;
extern s32 D_801EF6D0;
extern s32 D_801EF7D8;
extern s16 D_801F8714;
extern s32 D_801F8734;
extern s16 D_801F873A;
extern s32 D_801F8740;
extern s32 D_801F86FC;
extern s32 D_801F8700;
extern s32 D_801F8704;
extern u16 D_801F885C;

void func_801A0400(s32 arg0) {
    register s32 *p __asm__("$17");
    s32 v0;
    s32 v1;
    s32 r6;
    s32 rt;
    s32 flag;
    s16 sv0;
    s16 sv3;
    s16 sv5;
    s16 sv10;
    s16 sw5;
    s16 sw10;
    s32 d10;
    s32 q10;

    flag = 1;
    switch (*(u16 *)(arg0 + 0x34)) {
    case 0:
        sv0 = *(s16 *)(arg0 + 0xA);
        *(s16 *)(arg0 + 0xA) = (sv0 < -0x220) ? sv0 + 2 : -0x220;
        if (*(s32 *)(arg0 + 0x94) == 0x10) {
            goto incr;
        }
        break;
    case 1:
        *(u16 *)(arg0 + 0xA) -= 6;
        if (*(s32 *)(arg0 + 0x94) != 0x24) {
            break;
        }
        *(u16 *)(arg0 + 0x34) = *(u16 *)(arg0 + 0x34) + 1;
        func_8002D4C8(0xBA5, 0);
        break;
    case 2:
        *(u16 *)(arg0 + 0xA) += 0xA;
        if (*(s32 *)(arg0 + 0x94) == 0x28) {
            D_801B6EC4 = 0x1000000;
            D_801B6EC8 = 0x1000000;
            D_801F885C = 0x70;
            D_801B6EC0 = D_801B872C;
            D_8019FF8A |= 4;
        }
        if (*(s32 *)(arg0 + 0x94) == 0x30) {
            goto incr;
        }
        break;
    case 3:
        sv3 = *(s16 *)(arg0 + 0xA);
        *(s16 *)(arg0 + 0xA) = (sv3 < -0x23F) ? -0x240 : sv3 - 3;
        if (*(s32 *)(arg0 + 0x94) == 0x3C) {
            goto incr;
        }
        break;
    case 4:
        if (*(s16 *)(arg0 + 0x98) == 0) {
            func_801A3180(arg0, 0x100);
            if (!(D_8019FF8A & 0x40)) {
                *(u16 *)(arg0 + 0x34) = *(u16 *)(arg0 + 0x34) + 1;
            }
        }
        func_801A36A8(arg0);
        break;
    case 5:
        sv5 = *(s16 *)(arg0 + 0xA);
        if (sv5 < -0x200) {
            sw5 = sv5 + 8;
            *(s16 *)(arg0 + 0xA) = sw5;
            if (sw5 < -0x200) {
                break;
            }
        }
        func_8012A828(arg0, &D_801EF270);
        func_8012B200((u8 *) arg0);
        func_8012B178(arg0, -0x60000);
        goto incr;
    case 6:
        flag = 0;
        if ((u32) (*(s32 *)(arg0 + 0x94) - 8) < 0x19) {
            r6 = func_8012B8A4((s16 *) arg0);
            *(s16 *)(arg0 + 0xFE) = r6;
            func_801A3624((s16) r6, (u16 *) (*(s32 *)(arg0 + 0x20) + 0x12), 0x20);
            func_8012AD80(arg0);
            if (*(s32 *)(arg0 + 0x94) == 0x1B) {
                func_8012AD80(arg0);
            }
        }
        if (*(s32 *)(arg0 + 0x94) == 0x1C) {
            func_8012C658(0xD, 2, arg0);
        }
        if (*(s16 *)(arg0 + 0x98) != 0) {
            break;
        }
        *(s32 *)(arg0 + 0x1C) = 0x10;
        *(u16 *)(arg0 + 0x34) = *(u16 *)(arg0 + 0x34) + 1;
        break;
    case 7:
        flag = 1;
        if (func_8012BEE8(arg0) == 0) {
            break;
        }
        func_8012A828(arg0, &D_801EF3B8);
        goto incr;
    case 8:
        flag = 0;
        v1 = *(s32 *)(arg0 + 0x94);
        switch (v1) {
        case 0xB:
            v0 = 0;
            break;
        case 0x17:
            v0 = 1;
            break;
        default:
            v0 = -1;
            break;
        }
        if (v0 >= 0) {
            func_8012C658(0xD, v0, arg0);
        }
        if (*(s16 *)(arg0 + 0x98) != 0) {
            break;
        }
        func_8012A828(arg0, &D_801EF6D0);
        func_8012B200((u8 *) arg0);
        goto incr;
    case 9:
        flag = 0;
        func_8012AD80(arg0);
        if (*(s32 *)(arg0 + 0x94) == 8) {
            func_8012B178(arg0, 0x7C000);
            func_8002D4C8(0xBA6, 0);
        }
        if (*(s32 *)(arg0 + 0x94) == 0x1C) {
            func_8012B200((u8 *) arg0);
        }
        if (*(s16 *)(arg0 + 0x98) != 0) {
            break;
        }
        func_80132288(&D_801F8734, &D_801AFBB4, D_801B872C);
        *(s32 *)(arg0 + 0x18) = 0;
        *(s32 *)(arg0 + 0x10) = 0;
        *(u16 *)(arg0 + 0x34) = *(u16 *)(arg0 + 0x34) + 1;
        break;
    case 10:
        p = &D_801F8734;
        func_8013240C((s32) p);
        d10 = D_801AFBB8;
        q10 = 0x70 / d10;
        D_801F885C = ((d10 - D_801F873A) + 1) * q10 & 0xFFFE;
        if (D_801F8740 & 0x4000) {
            D_801B6EC0 = D_801F86FC;
            D_801B6EC4 = D_801F8700;
            D_801B6EC8 = D_801F8704;
            D_8019FF8A &= 0xFFFB;
        }
        sv10 = *(s16 *)(arg0 + 0xA);
        if (sv10 >= -0x23F) {
            sw10 = sv10 - 2;
            *(s16 *)(arg0 + 0xA) = sw10;
            if (sw10 >= -0x23F) {
                break;
            }
        }
        *(s16 *)(arg0 + 0xA) = -0x240;
        func_80132288(p, &D_801AFBA4, D_801B872C);
        func_8012A828(arg0, &D_801EF7D8);
    incr:
        *(u16 *)(arg0 + 0x34) = *(u16 *)(arg0 + 0x34) + 1;
        break;
    case 11:
        func_8013240C((s32) &D_801F8734);
        if (*(s16 *)(arg0 + 0x98) != 0) {
            break;
        }
        *(u16 *)(arg0 + 0x5C) |= 0x2000;
        func_8012A828(arg0, &D_801EEAC8);
        *(s32 *)(arg0 + 0x1C) = (s16) (D_801F8714 / 79) + 0x18;
        func_8012B200((u8 *) arg0);
        func_8012AD44((s32 *) arg0, 1);
        func_801A4328(0);
        break;
    }
    if (flag) {
        rt = func_8012B8A4((s16 *) arg0);
        *(s16 *)(arg0 + 0xFE) = rt;
        func_801A3624((s16) rt, (u16 *) (*(s32 *)(arg0 + 0x20) + 0x12), 0x40);
    }
}
