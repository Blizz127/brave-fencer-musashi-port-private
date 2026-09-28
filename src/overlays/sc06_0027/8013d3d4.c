/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8013D3D4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_80078E78[];
extern void *D_8019C068;
extern void *D_8019C06C;
extern void *D_8019C070;
extern s32 D_8019C098;
extern s32 D_8019C09C;
extern s32 D_8019C0A0;
extern s32 D_8019D314[];
extern u8 D_8017E814[];
extern u8 D_8017E8BC[];
extern u8 D_8017E76C[];
extern u8 D_8017E868[];
extern u8 D_8017E8E8[];
extern u8 D_8017E7C0[];
extern void func_8013D53C();
extern void func_8013DD68(void);
extern void func_8013D8FC(void);
extern void func_8013CF68(void);

void func_8013D3D4(int param_1, int param_2)
{
    u8 *p = D_80078E78;

    D_8019C098 = param_2;
    D_8019C09C = (param_2 >> 2) & 3;
    D_8019C0A0 = (param_2 >> 4) & 1;
    if (((param_2 >> 2) & 3) == 0) {
        D_8019C068 = D_8017E814;
        D_8019C06C = D_8017E8BC;
        D_8019C070 = D_8017E76C;
    } else {
        D_8019C068 = D_8017E868;
        D_8019C06C = D_8017E8E8;
        D_8019C070 = D_8017E7C0;
    }
    func_8013D53C();
    if ((param_2 & 1) != 0) {
        if (D_8019C0A0 != 0) {
            func_8013DD68();
        } else {
            func_8013D8FC();
        }
        func_8013CF68();
        if ((D_8019C098 & 2) != 0) {
            D_8019D314[0] = 0x140;
            D_8019D314[3] = 0x80;
            if (p[0x37] == 4) {
                D_8019D314[0] = 0x140;
                D_8019D314[3] = 0;
            }
            if (p[0x37] == 0) {
                D_8019D314[0] = 0x140;
                D_8019D314[3] = 0x80;
            }
        }
    }
}
