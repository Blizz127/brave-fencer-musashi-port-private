/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8013D3D4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u8 D_80078E78[];
extern void func_8013CF68(void);
void func_8013CF68();
extern void *D_80195008;
extern void *D_8019500C;
extern void *D_80195010;
extern s32 D_80195038;
extern s32 D_8019503C;
extern s32 D_80195040;
extern s32 D_801962AC[];
extern u8 D_8017E51C[];
extern u8 D_8017E5C4[];
extern u8 D_8017E474[];
extern u8 D_8017E570[];
extern u8 D_8017E5F0[];
extern u8 D_8017E4C8[];
extern void func_8013D53C();
extern void func_8013DD68(void);
extern void func_8013D8FC(void);

void func_8013D3D4(int param_1, int param_2)
{
    u8 *p = D_80078E78;

    D_80195038 = param_2;
    D_8019503C = (param_2 >> 2) & 3;
    D_80195040 = (param_2 >> 4) & 1;
    if (((param_2 >> 2) & 3) == 0) {
        D_80195008 = D_8017E51C;
        D_8019500C = D_8017E5C4;
        D_80195010 = D_8017E474;
    } else {
        D_80195008 = D_8017E570;
        D_8019500C = D_8017E5F0;
        D_80195010 = D_8017E4C8;
    }
    func_8013D53C();
    if ((param_2 & 1) != 0) {
        if (D_80195040 != 0) {
            func_8013DD68();
        } else {
            func_8013D8FC();
        }
        func_8013CF68();
        if ((D_80195038 & 2) != 0) {
            D_801962AC[0] = 0x140;
            D_801962AC[3] = 0x80;
            if (p[0x37] == 4) {
                D_801962AC[0] = 0x140;
                D_801962AC[3] = 0;
            }
            if (p[0x37] == 0) {
                D_801962AC[0] = 0x140;
                D_801962AC[3] = 0x80;
            }
        }
    }
}
