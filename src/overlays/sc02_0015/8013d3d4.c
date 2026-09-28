/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8013D3D4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u8 D_80078E78[];
extern void func_8013CF68(void);
void func_8013CF68();
extern void *D_8018F0E0;
extern void *D_8018F0E4;
extern void *D_8018F0E8;
extern s32 D_8018F110;
extern s32 D_8018F114;
extern s32 D_8018F118;
extern s32 D_80190584[];
extern u8 D_8017EA84[];
extern u8 D_8017EB2C[];
extern u8 D_8017E9DC[];
extern u8 D_8017EAD8[];
extern u8 D_8017EB58[];
extern u8 D_8017EA30[];
extern void func_8013D53C();
extern void func_8013DD68(void);
extern void func_8013D8FC(void);

void func_8013D3D4(int param_1, int param_2)
{
    u8 *p = D_80078E78;

    D_8018F110 = param_2;
    D_8018F114 = (param_2 >> 2) & 3;
    D_8018F118 = (param_2 >> 4) & 1;
    if (((param_2 >> 2) & 3) == 0) {
        D_8018F0E0 = D_8017EA84;
        D_8018F0E4 = D_8017EB2C;
        D_8018F0E8 = D_8017E9DC;
    } else {
        D_8018F0E0 = D_8017EAD8;
        D_8018F0E4 = D_8017EB58;
        D_8018F0E8 = D_8017EA30;
    }
    func_8013D53C();
    if ((param_2 & 1) != 0) {
        if (D_8018F118 != 0) {
            func_8013DD68();
        } else {
            func_8013D8FC();
        }
        func_8013CF68();
        if ((D_8018F110 & 2) != 0) {
            D_80190584[0] = 0x140;
            D_80190584[3] = 0x80;
            if (p[0x37] == 4) {
                D_80190584[0] = 0x140;
                D_80190584[3] = 0;
            }
            if (p[0x37] == 0) {
                D_80190584[0] = 0x140;
                D_80190584[3] = 0x80;
            }
        }
    }
}
