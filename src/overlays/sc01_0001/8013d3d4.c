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
extern void *D_801EC758;
extern void *D_801EC75C;
extern void *D_801EC760;
extern s32 D_801EC788;
extern s32 D_801EC78C;
extern s32 D_801EC790;
extern s32 D_801F30AC[];
extern u8 D_80184098[];
extern u8 D_80184140[];
extern u8 D_80183FF0[];
extern u8 D_801840EC[];
extern u8 D_8018416C[];
extern u8 D_80184044[];
extern void func_8013D53C();
extern void func_8013DD68(void);
extern void func_8013D8FC(void);
extern void func_8013CF68(void);

void func_8013D3D4(int param_1, int param_2)
{
    u8 *p = D_80078E78;

    D_801EC788 = param_2;
    D_801EC78C = (param_2 >> 2) & 3;
    D_801EC790 = (param_2 >> 4) & 1;
    if (((param_2 >> 2) & 3) == 0) {
        D_801EC758 = D_80184098;
        D_801EC75C = D_80184140;
        D_801EC760 = D_80183FF0;
    } else {
        D_801EC758 = D_801840EC;
        D_801EC75C = D_8018416C;
        D_801EC760 = D_80184044;
    }
    func_8013D53C();
    if ((param_2 & 1) != 0) {
        if (D_801EC790 != 0) {
            func_8013DD68();
        } else {
            func_8013D8FC();
        }
        func_8013CF68();
        if ((D_801EC788 & 2) != 0) {
            D_801F30AC[0] = 0x140;
            D_801F30AC[3] = 0x80;
            if (p[0x37] == 4) {
                D_801F30AC[0] = 0x140;
                D_801F30AC[3] = 0;
            }
            if (p[0x37] == 0) {
                D_801F30AC[0] = 0x140;
                D_801F30AC[3] = 0x80;
            }
        }
    }
}
