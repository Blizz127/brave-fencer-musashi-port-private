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
extern void *D_80195388;
extern void *D_8019538C;
extern void *D_80195390;
extern s32 D_801953B8;
extern s32 D_801953BC;
extern s32 D_801953C0;
extern s32 D_8019662C[];
extern u8 D_8017DB40[];
extern u8 D_8017DBE8[];
extern u8 D_8017DA98[];
extern u8 D_8017DB94[];
extern u8 D_8017DC14[];
extern u8 D_8017DAEC[];
extern void func_8013D53C();
extern void func_8013DD68(void);
extern void func_8013D8FC(void);
extern void func_8013CF68(void);

void func_8013D3D4(int param_1, int param_2)
{
    u8 *p = D_80078E78;

    D_801953B8 = param_2;
    D_801953BC = (param_2 >> 2) & 3;
    D_801953C0 = (param_2 >> 4) & 1;
    if (((param_2 >> 2) & 3) == 0) {
        D_80195388 = D_8017DB40;
        D_8019538C = D_8017DBE8;
        D_80195390 = D_8017DA98;
    } else {
        D_80195388 = D_8017DB94;
        D_8019538C = D_8017DC14;
        D_80195390 = D_8017DAEC;
    }
    func_8013D53C();
    if ((param_2 & 1) != 0) {
        if (D_801953C0 != 0) {
            func_8013DD68();
        } else {
            func_8013D8FC();
        }
        func_8013CF68();
        if ((D_801953B8 & 2) != 0) {
            D_8019662C[0] = 0x140;
            D_8019662C[3] = 0x80;
            if (p[0x37] == 4) {
                D_8019662C[0] = 0x140;
                D_8019662C[3] = 0;
            }
            if (p[0x37] == 0) {
                D_8019662C[0] = 0x140;
                D_8019662C[3] = 0x80;
            }
        }
    }
}
