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
extern void *D_80199840;
extern void *D_80199844;
extern void *D_80199848;
extern s32 D_80199870;
extern s32 D_80199874;
extern s32 D_80199878;
extern s32 D_8019AAEC[];
extern u8 D_8017F40C[];
extern u8 D_8017F4B4[];
extern u8 D_8017F364[];
extern u8 D_8017F460[];
extern u8 D_8017F4E0[];
extern u8 D_8017F3B8[];
extern void func_8013D53C();
extern void func_8013DD68(void);
extern void func_8013D8FC(void);
extern void func_8013CF68(void);

void func_8013D3D4(int param_1, int param_2)
{
    u8 *p = D_80078E78;

    D_80199870 = param_2;
    D_80199874 = (param_2 >> 2) & 3;
    D_80199878 = (param_2 >> 4) & 1;
    if (((param_2 >> 2) & 3) == 0) {
        D_80199840 = D_8017F40C;
        D_80199844 = D_8017F4B4;
        D_80199848 = D_8017F364;
    } else {
        D_80199840 = D_8017F460;
        D_80199844 = D_8017F4E0;
        D_80199848 = D_8017F3B8;
    }
    func_8013D53C();
    if ((param_2 & 1) != 0) {
        if (D_80199878 != 0) {
            func_8013DD68();
        } else {
            func_8013D8FC();
        }
        func_8013CF68();
        if ((D_80199870 & 2) != 0) {
            D_8019AAEC[0] = 0x140;
            D_8019AAEC[3] = 0x80;
            if (p[0x37] == 4) {
                D_8019AAEC[0] = 0x140;
                D_8019AAEC[3] = 0;
            }
            if (p[0x37] == 0) {
                D_8019AAEC[0] = 0x140;
                D_8019AAEC[3] = 0x80;
            }
        }
    }
}
