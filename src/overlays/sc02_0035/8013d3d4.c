/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8013D3D4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u8 D_80078E78[];
extern void func_8013CF68(void);
void func_8013CF68();
extern void *D_801BD688;
extern void *D_801BD68C;
extern void *D_801BD690;
extern s32 D_801BD6B8;
extern s32 D_801BD6BC;
extern s32 D_801BD6C0;
extern s32 D_801BE92C[];
extern u8 D_80184D10[];
extern u8 D_80184DB8[];
extern u8 D_80184C68[];
extern u8 D_80184D64[];
extern u8 D_80184DE4[];
extern u8 D_80184CBC[];
extern void func_8013D53C();
extern void func_8013DD68(void);
extern void func_8013D8FC(void);

void func_8013D3D4(int param_1, int param_2)
{
    u8 *p = D_80078E78;

    D_801BD6B8 = param_2;
    D_801BD6BC = (param_2 >> 2) & 3;
    D_801BD6C0 = (param_2 >> 4) & 1;
    if (((param_2 >> 2) & 3) == 0) {
        D_801BD688 = D_80184D10;
        D_801BD68C = D_80184DB8;
        D_801BD690 = D_80184C68;
    } else {
        D_801BD688 = D_80184D64;
        D_801BD68C = D_80184DE4;
        D_801BD690 = D_80184CBC;
    }
    func_8013D53C();
    if ((param_2 & 1) != 0) {
        if (D_801BD6C0 != 0) {
            func_8013DD68();
        } else {
            func_8013D8FC();
        }
        func_8013CF68();
        if ((D_801BD6B8 & 2) != 0) {
            D_801BE92C[0] = 0x140;
            D_801BE92C[3] = 0x80;
            if (p[0x37] == 4) {
                D_801BE92C[0] = 0x140;
                D_801BE92C[3] = 0;
            }
            if (p[0x37] == 0) {
                D_801BE92C[0] = 0x140;
                D_801BE92C[3] = 0x80;
            }
        }
    }
}
