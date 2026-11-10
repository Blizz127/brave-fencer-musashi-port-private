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
extern void *D_801C4278;
extern void *D_801C427C;
extern void *D_801C4280;
extern s32 D_801C42A8;
extern s32 D_801C42AC;
extern s32 D_801C42B0;
extern s32 D_801C579C[];
extern u8 D_80185B60[];
extern u8 D_80185C08[];
extern u8 D_80185AB8[];
extern u8 D_80185BB4[];
extern u8 D_80185C34[];
extern u8 D_80185B0C[];
extern void func_8013D53C();
extern void func_8013DD68(void);
extern void func_8013D8FC(void);
extern void func_8013CF68(void);

void func_8013D3D4(int param_1, int param_2)
{
    u8 *p = D_80078E78;

    D_801C42A8 = param_2;
    D_801C42AC = (param_2 >> 2) & 3;
    D_801C42B0 = (param_2 >> 4) & 1;
    if (((param_2 >> 2) & 3) == 0) {
        D_801C4278 = D_80185B60;
        D_801C427C = D_80185C08;
        D_801C4280 = D_80185AB8;
    } else {
        D_801C4278 = D_80185BB4;
        D_801C427C = D_80185C34;
        D_801C4280 = D_80185B0C;
    }
    func_8013D53C();
    if ((param_2 & 1) != 0) {
        if (D_801C42B0 != 0) {
            func_8013DD68();
        } else {
            func_8013D8FC();
        }
        func_8013CF68();
        if ((D_801C42A8 & 2) != 0) {
            D_801C579C[0] = 0x140;
            D_801C579C[3] = 0x80;
            if (p[0x37] == 4) {
                D_801C579C[0] = 0x140;
                D_801C579C[3] = 0;
            }
            if (p[0x37] == 0) {
                D_801C579C[0] = 0x140;
                D_801C579C[3] = 0x80;
            }
        }
    }
}
