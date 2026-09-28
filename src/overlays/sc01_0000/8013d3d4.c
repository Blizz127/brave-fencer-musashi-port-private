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
extern void *D_801A44C8;
extern void *D_801A44CC;
extern void *D_801A44D0;
extern s32 D_801A44F8;
extern s32 D_801A44FC;
extern s32 D_801A4500;
extern s32 D_801A57CC[];
extern u8 D_8017F448[];
extern u8 D_8017F4F0[];
extern u8 D_8017F3A0[];
extern u8 D_8017F49C[];
extern u8 D_8017F51C[];
extern u8 D_8017F3F4[];
extern void func_8013D53C();
extern void func_8013DD68(void);
extern void func_8013D8FC(void);
extern void func_8013CF68(void);

void func_8013D3D4(int param_1, int param_2)
{
    u8 *p = D_80078E78;

    D_801A44F8 = param_2;
    D_801A44FC = (param_2 >> 2) & 3;
    D_801A4500 = (param_2 >> 4) & 1;
    if (((param_2 >> 2) & 3) == 0) {
        D_801A44C8 = D_8017F448;
        D_801A44CC = D_8017F4F0;
        D_801A44D0 = D_8017F3A0;
    } else {
        D_801A44C8 = D_8017F49C;
        D_801A44CC = D_8017F51C;
        D_801A44D0 = D_8017F3F4;
    }
    func_8013D53C();
    if ((param_2 & 1) != 0) {
        if (D_801A4500 != 0) {
            func_8013DD68();
        } else {
            func_8013D8FC();
        }
        func_8013CF68();
        if ((D_801A44F8 & 2) != 0) {
            D_801A57CC[0] = 0x140;
            D_801A57CC[3] = 0x80;
            if (p[0x37] == 4) {
                D_801A57CC[0] = 0x140;
                D_801A57CC[3] = 0;
            }
            if (p[0x37] == 0) {
                D_801A57CC[0] = 0x140;
                D_801A57CC[3] = 0x80;
            }
        }
    }
}
