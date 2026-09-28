/* Complete retail export [8013D3D4,8013D53C). */
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
extern void *D_801B6358;
extern void *D_801B635C;
extern void *D_801B6360;
extern s32 D_801B6388;
extern s32 D_801B638C;
extern s32 D_801B6390;
extern s32 D_801B79F4[];
extern u8 D_801854B0[];
extern u8 D_80185558[];
extern u8 D_80185408[];
extern u8 D_80185504[];
extern u8 D_80185584[];
extern u8 D_8018545C[];
extern void func_8013D53C();
extern void func_8013DD68(void);
extern void func_8013D8FC(void);
extern void func_8013CF68(void);

void func_8013D3D4(int param_1, int param_2)
{
    u8 *p = D_80078E78;

    D_801B6388 = param_2;
    D_801B638C = (param_2 >> 2) & 3;
    D_801B6390 = (param_2 >> 4) & 1;
    if (((param_2 >> 2) & 3) == 0) {
        D_801B6358 = D_801854B0;
        D_801B635C = D_80185558;
        D_801B6360 = D_80185408;
    } else {
        D_801B6358 = D_80185504;
        D_801B635C = D_80185584;
        D_801B6360 = D_8018545C;
    }
    func_8013D53C();
    if ((param_2 & 1) != 0) {
        if (D_801B6390 != 0) {
            func_8013DD68();
        } else {
            func_8013D8FC();
        }
        func_8013CF68();
        if ((D_801B6388 & 2) != 0) {
            D_801B79F4[0] = 0x140;
            D_801B79F4[3] = 0x80;
            if (p[0x37] == 4) {
                D_801B79F4[0] = 0x140;
                D_801B79F4[3] = 0;
            }
            if (p[0x37] == 0) {
                D_801B79F4[0] = 0x140;
                D_801B79F4[3] = 0x80;
            }
        }
    }
}
