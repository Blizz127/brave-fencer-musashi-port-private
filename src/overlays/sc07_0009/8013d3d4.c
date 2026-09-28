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
extern void *D_801A2A18;
extern void *D_801A2A1C;
extern void *D_801A2A20;
extern s32 D_801A2A48;
extern s32 D_801A2A4C;
extern s32 D_801A2A50;
extern s32 D_801A3CBC[];
extern u8 D_8017E5E4[];
extern u8 D_8017E68C[];
extern u8 D_8017E53C[];
extern u8 D_8017E638[];
extern u8 D_8017E6B8[];
extern u8 D_8017E590[];
extern void func_8013D53C();
extern void func_8013DD68(void);
extern void func_8013D8FC(void);
extern void func_8013CF68(void);

void func_8013D3D4(int param_1, int param_2)
{
    u8 *p = D_80078E78;

    D_801A2A48 = param_2;
    D_801A2A4C = (param_2 >> 2) & 3;
    D_801A2A50 = (param_2 >> 4) & 1;
    if (((param_2 >> 2) & 3) == 0) {
        D_801A2A18 = D_8017E5E4;
        D_801A2A1C = D_8017E68C;
        D_801A2A20 = D_8017E53C;
    } else {
        D_801A2A18 = D_8017E638;
        D_801A2A1C = D_8017E6B8;
        D_801A2A20 = D_8017E590;
    }
    func_8013D53C();
    if ((param_2 & 1) != 0) {
        if (D_801A2A50 != 0) {
            func_8013DD68();
        } else {
            func_8013D8FC();
        }
        func_8013CF68();
        if ((D_801A2A48 & 2) != 0) {
            D_801A3CBC[0] = 0x140;
            D_801A3CBC[3] = 0x80;
            if (p[0x37] == 4) {
                D_801A3CBC[0] = 0x140;
                D_801A3CBC[3] = 0;
            }
            if (p[0x37] == 0) {
                D_801A3CBC[0] = 0x140;
                D_801A3CBC[3] = 0x80;
            }
        }
    }
}
