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
extern void *D_8019BE18;
extern void *D_8019BE1C;
extern void *D_8019BE20;
extern s32 D_8019BE48;
extern s32 D_8019BE4C;
extern s32 D_8019BE50;
extern s32 D_8019D0C4[];
extern u8 D_8017E558[];
extern u8 D_8017E600[];
extern u8 D_8017E4B0[];
extern u8 D_8017E5AC[];
extern u8 D_8017E62C[];
extern u8 D_8017E504[];
extern void func_8013D53C();
extern void func_8013DD68(void);
extern void func_8013D8FC(void);
extern void func_8013CF68(void);

void func_8013D3D4(int param_1, int param_2)
{
    u8 *p = D_80078E78;

    D_8019BE48 = param_2;
    D_8019BE4C = (param_2 >> 2) & 3;
    D_8019BE50 = (param_2 >> 4) & 1;
    if (((param_2 >> 2) & 3) == 0) {
        D_8019BE18 = D_8017E558;
        D_8019BE1C = D_8017E600;
        D_8019BE20 = D_8017E4B0;
    } else {
        D_8019BE18 = D_8017E5AC;
        D_8019BE1C = D_8017E62C;
        D_8019BE20 = D_8017E504;
    }
    func_8013D53C();
    if ((param_2 & 1) != 0) {
        if (D_8019BE50 != 0) {
            func_8013DD68();
        } else {
            func_8013D8FC();
        }
        func_8013CF68();
        if ((D_8019BE48 & 2) != 0) {
            D_8019D0C4[0] = 0x140;
            D_8019D0C4[3] = 0x80;
            if (p[0x37] == 4) {
                D_8019D0C4[0] = 0x140;
                D_8019D0C4[3] = 0;
            }
            if (p[0x37] == 0) {
                D_8019D0C4[0] = 0x140;
                D_8019D0C4[3] = 0x80;
            }
        }
    }
}
